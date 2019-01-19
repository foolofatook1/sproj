INCLUDE "gbhw.inc"			

_FONT_TILES		EQU		$9200

; variable to save the state of the pad
_PAD			EQU		_RAM

_POINT			EQU		_OAMRAM

; sprite stuffs
_SPR_X			EQU		_OAMRAM+1
_SPR_Y			EQU		_OAMRAM+2
_SPR_NUM		EQU		_OAMRAM+3

SECTION "VBlank", ROM0[$040]
	reti

; The program begins here:
SECTION "top",ROM0[$0100]
	nop
	jp  	main

	; Head of the ROM (Macro defined in gbhw.inc)
	; defines a rom without mapper, without 32K RAM, the basics
	; (Such as tetris)
	ROM_HEADER  ROM_NOMBC, ROM_SIZE_32KBYTE, RAM_SIZE_0KBYTE

; This is primarily for loading the stack pointer
main:
	nop
	di					; disables interrupts
	ld		sp, $ffff		; We aim pile atop the ram

init:
	; load the pallets
	ld		a, %11100100		; Palette colors from the darkest to
	ld		[rBGP], a		; We write this in the background palette register 
	ld		[rOBP0],a		; sprite palette

	; scroll
	ld		a, 96			; write 0 records scroll in X and Y
	ld		[rSCX], a		; positioned so that the visible screen
	ld		a, 0
	ld		[rSCY], a		; at the beginning (upper left) of the fund.

	ld		[_POINT], a 	; when POINT is 0 we point to start
	
	; We call the routine that turns off the LCD so that we can write to it
	call		LCD_off		

	; We load the tiles in memory of tiles
	ld		hl, Tiles			
	ld		de, _VRAM			; address in the video memory 
	ld		bc, TilesEnd-Tiles	; a counter
	call 	mem_cp

	; We load the map 
	ld		hl, Map
	ld		de, _SCRN0		; map 0 
	ld		bc, 32*32		; a counter
	call	mem_cp

	; sprite stuff
	ld		de, _OAMRAM
	ld		bc, 40*4
	ld		l, 0
	call	clean_mem

	ld		a, 14			; sprite X and Y pos
	ld		[_SPR_X], a
	ld		a, 5			; Y will inc for each down
	ld		[_SPR_Y], a
	ld		a, 50			; tile number
	ld		[_SPR_NUM], a


	; configure and activate the display
	ld 		a, LCDCF_ON|LCDCF_BG8000|LCDCF_BG9800|LCDCF_BGON|LCDCF_OBJ8|LCDCF_OBJON
	ld  	[rLCDC], a


; an infinite loop to keep rendering the screen
draw:
	; read the pad
	call 	pad

	; just wait for VBlank whenever we make changes to VRAM
.wait_VBlank:
	ld		a, [rLY]
	cp		145
	jr		nz, .wait_VBlank	

	ld		a, [_PAD]
	and		%00010000		; right
	call	nz, right
	
	ld		a, [_PAD]
	and		%00100000		; left
	call	nz, left		

	ld		a, [_PAD]
	and		%01000000		; up
	call	nz, up

	ld		a, [_PAD]
	and		%10000000		; down
	call	nz, down

	; a small delay may be necessary
	call 	slow_down
	jp		draw


; move screen right
right:

	ld		a, [rSCX]
	cp		96
	jr		z, .no_right
	inc 	a
	ld		[rSCX], a
	ret
.no_right
	ld		a, 96
	ld		[rSCX], a
	ret

; move screen left
left:
	ld		a, [rSCX]
	cp		0
	jr		z, .no_left
	dec		a
	ld		[rSCX], a
	ret
.no_left
	ld		a, 0
	ld		[rSCX], a
	ret
	
; move screen up
up:
	ld		a, [_POINT]
	
	cp		0
	jr		z, quit

	cp		1
	jr		z, start

	cp		2
	jr		z, new_game

;	ld		a, [rSCY]
;	cp		0
;	jr		z, .no_up
;	dec		a
;	ld		[rSCY], a
;	ret
;.no_up
;	ld		a, 0
;	ld		[rSCY], a
;	ret

; move screen down
down:
	ld		a, [_POINT]
	
	cp		0
	jr		z, new_game

	cp		1
	jr		z, quit
	
	cp		2
	jr		z, start

;	ld		a, [rSCY]
;	cp		96
;	jr		z, .no_down
;	inc		a
;	ld		[rSCY], a
;	ret
;.no_down
;	ld		a, 96
;	ld		[rSCY], a
;	ret

;	ld		a, [_POINT]
;	cp		0
;	jr		z, new_game
;	cp		1
;	jr		z, quit
;	cp		2
;	jr		z, start

start:
.wait_VBlank
	ld		a, 0
	ld		[_POINT], a

	call	clean
	
	ld		hl, MapStart
	ld		de, _SCRN0
	ld		bc, 32*32
	call	mem_cp
	call	slow_down
	ret



new_game:
.wait_VBlank
	ld		a, 1
	ld		[_POINT], a

	call	clean

	ld		hl, MapNewGame
	ld		de, _SCRN0
	ld		bc, 32*32
	call	mem_cp
	call	slow_down
	ret

quit:
.wait_VBlank
	ld		a, 2
	ld		[_POINT], a

	call	clean

	ld		hl, MapQuit
	ld		de, _SCRN0
	ld		bc, 32*32
	call	mem_cp
	call	slow_down
	ret

slow_down:
	ld		de, 6000
.delay:
	dec		de
	ld		a, d
	or		e
	jr		z, .end_delay
.end_delay:
	ret

; joypad bits work as follows:
; 7 - nada
; 6 - nada
; 5 - P15 Select Button (0 = Select)
; 4 - P14 Select direct (0 = Select)
; 3 - P13 Down or Start	(0 = Down)
; 2 - P12 Up or Select	(0 = Down)
; 1 - P11 Left or B  	(0 = Down)
; 0 - P10 Right or A 	(0 = Down)
; rP1 is the register for reading the joypad info
pad:
	; checking the direction pad
	ld		a, %00100000
	ld		[rP1], a

	; now we do several readings to avoid bounciness
	ld		a, [rP1] 

	and		$0F				; and them with the last 4 bits
	swap	a				; switch lower 4 with upper 4 bits
;	ld		b, a			; this may not be needed

;	ld		a, %00010000	; this may not be needed
;	ld		[rP1], a		; this may not be needed
;
;	ld		a, [rP1]		; this may not be needed
;	ld		a, [rP1]	
;	ld		a, [rP1]	
;	ld		a, [rP1]	
;	ld		a, [rP1]	
	
;	and 	$0F 			; this may not be needed
	or 		b

	cpl
	ld		[_PAD], a			; then keep the status of the pad in b
	
	ret


; LCD shutdown routine
LCD_off:
	ld		a,[rLCDC]
	rlca	                ;  Sets the high bit of LCDC in the carry flag
	ret		nc              ;  Display is already off, again.

; We VBlank hope to, because we can not turn off the screen
; some other time
.wait_VBlank
	; we are in VBlank, we turn off the LCD
	ld		a,[rLCDC]		; in A, the contents of the LCDC
	res		7,a			; we zero bit 7 (on the LCD)
	ld		[rLCDC],a		; eWe wrote in the LCDC register content A
	ret					; return

clean:
.wait_VBlank
	ld		hl, Map
	ld		de, _SCRN0
	ld		bc, 32*32
	call	mem_cp
	;call	slow_down
	ret

clean_mem:
	ld		a, l
	ld		[de], a
	dec		bc

	ld		a, c
	or		b
	ret		z
	inc		de
	jr		clean_mem

; memory copy routine
; copy a number of bytes from one direction to another
; expects the parameters:
; hl - copying data address
; of - destination address
; bc - number of data to be copied
; destroys the contents of A
mem_cp:
	ld		a, [hl]		; To load the data in
	ld		[de], a		; copy the data to the destination
	dec		bc		; least one copy
	; We check if bc is zero
	ld		a, c
	or		b
	ret		z		; If zero, we return
	; if not, we still
	inc		hl
	inc		de
	jr		mem_cp


Tiles:
	INCLUDE "ship_tiles.z80"
TilesEnd:

Map:
	INCLUDE "open_screen.z80"
MapEnd:

MapStart:
	INCLUDE "ship_start.z80"
MapStartEnd:

MapNewGame:
	INCLUDE "ship_ng.z80"
MapNewGameEnd:

MapQuit:
	INCLUDE "ship_quit.z80"
MapQuitEnd:

Font:
	INCLUDE "font.z80"
EndFont:
