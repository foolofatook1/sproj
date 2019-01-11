; just a moving sprite

INCLUDE "gbhw.inc"

_SPR0_Y 	EQU 	_OAMRAM ; beginning of sprite memory
_SPR0_X 	EQU 	_OAMRAM+1
_SPR0_NUM	EQU		_OAMRAM+2
_SPR0_ATT 	EQU		_OAMRAM+3

; variables for sprite movement
_MOVX		EQU		_RAM	; start of disposable data RAM
_MOVY		EQU		_RAM+1

SECTION "start", ROM0[$100]
	nop
	jp		main

; This is a basic ROM 
; defined without mapper, and without 32K RAM (like Tetris)
	ROM_HEADER ROM_NOMBC, ROM_SIZE_32KBYTE, RAM_SIZE_0KBYTE

; program start
main:
	nop
	di
	ld		sp, $ffff

; initialize the screen
init:
	ld		a, %11100100

	ld 		[rBGP], a		; write to background palette
	ld 		[rOBP0], a		; and to object palette

	ld 		a, 0
	ld 		[rSCX], a		; write 0 to x and y pos
	ld 		[rSCY], a

	call 	LCD_off			; turn off the LCD

	; load tiles into memory
	ld		hl, Tiles
	ld		de, _VRAM
	ld 		b, 32
	
.load_loop:
	ld		a,[hl]
	ld		[de], a
	dec 	b
	jr		z, .end_load_loop
	inc		hl
	inc 	de
	jr		.load_loop
.end_load_loop
	; fill the screen with tiles 0
	ld 		hl, _SCRN0
	ld 		de, 32*32 		; tile counter
; clean screen loop:
.clean_loop:
	ld		a, 0
	ld		[hl], a
	dec 	de
	; is de zero?
	ld 		a, d
	or 		e
	jp 		z, .end_clean_loop
	inc 	hl
	jp		.clean_loop
.end_clean_loop:
	; Now we draw the sprite on the clean background
	ld		a, 30
	ld		[_SPR0_Y], a	; sprite Y position
	ld 		a, 30
	ld 		[_SPR0_X], a	; sprite X position
	ld		a, 1
	ld		[_SPR0_NUM], a	; tile number to use
	ld		a, 0
	ld 		[_SPR0_ATT], a	; special attributes (nothing)

	; configure and activate display
	ld		a, LCDCF_ON|LCDCF_BG8000|LCDCF_BG9800|LCDCF_BGON|LCDCF_OBJ8|LCDCF_OBJON
	ld		[rLCDC], a

	; prepare animation variables for movement
	ld		a, 1
	ld		[_MOVX], a
	ld		[_MOVY], a

; infinite animation loop
animate:
; first wait for VBlank
.wait_VBlank:
	ld		a, [rLY]
	cp		145
	jr		nz, .wait_VBlank
	; increment y
	ld		a, [_SPR0_Y]
	ld		hl, _MOVY
	add		a, [hl]
	ld 		hl, _SPR0_Y
	ld 		[hl], a
	; compare to see if direction changed
	cp 		152			; so the screen is not gone out of bounds to the right
	jr		z, .dec_y
	cp		16
	jr		z, .inc_y	; so the screen is not gone out of bounds to the left
	; in the case that there was no change:
	jr		.end_y
.dec_y:
	ld		a, -1		; for decreasing y
	ld 		[_MOVY], a
	jr		.end_y
.inc_y:
	ld		a, 1		; for increasing y
	ld		[_MOVY], a
.end_y:
	; go with the same X but change the margins?
	ld		a, [_SPR0_X]
	ld		hl, _MOVX
	add		a, [hl]

	ld 		hl, _SPR0_X
	ld		[hl], a
	cp 		160
	jr		z, .dec_x
	cp		8
	jr		z, .inc_x
	jr		.end_x
.dec_x:
	ld		a, -1
	ld		[_MOVX], a
	jr		.end_x
.inc_x:
	ld		a, 1
	ld		[_MOVX], a
.end_x:
	call 	slow_down
	jr		animate

; routine for turning off LCD
LCD_off:
	ld		a, [rLY]		; load LCDC Y-Coordinate into a
	rlca					; sets high bit of LCDC in carry flag
	ret		nc

.wait_VBlank

	ld 		a, [rLCDC]
	res		7, a			; zero bit 7 on the LCD
	ld		[rLCDC], a

	ret

; delay routine
slow_down:
	ld		de, 2000		; number of times to execute loop
.delay:
	dec de
	ld a, d
	or e					; see if zero
	jr z, .end_delay
	nop
	jr .delay
.end_delay:
	ret
	
; The tiles	
Tiles:
	DB $AA, $00, $44, $00, $AA, $00, $11, $00
	DB $AA, $00, $44, $00, $AA, $00, $11, $00
	DB $3E, $3E, $41, $7F, $41, $6B, $41, $7F
	DB $41, $63, $41, $7F, $3E, $3E, $00, $00
EndTiles:
