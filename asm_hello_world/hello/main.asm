INCLUDE "gbhw.inc"

SECTION "header", ROM0[$100]
	nop
	jp main

; these macros are defined in gbhw.inc -- worth checking out
	ROM_HEADER ROM_NOMBC, ROM_SIZE_32KBYTE, RAM_SIZE_0KBYTE

main:
	nop			 ; no program
	di			 ; disable interrupt
	ld sp, $ffff ; apparently just piling on top of ram?

init:
	ld a, %11100100 ; initialize palette
	ld [rBGP], a ; this loads those into palette register
	ld a, 0 	 ; the following will load 0 into scroll x and y
	ld [rSCX], a
	ld [rSCY], a
	call LCD_off ; call the routine that turns off LCD

	; load the tiles in memory of tiles
	ld hl, Tiles 			; HL loaded in the direction of our tile
	ld de, _VRAM	  		; address in the video memory
	ld b, TilesEnd-Tiles	; number of bytes to copy

.loop:
	ld a,[hl]
	ld [de], a
	dec b
	jr z, .end_loop
	inc hl
	dec de
	jr .loop
.end_loop:
	ld hl, Map
	ld de, _SCRN0
	ld bc, 32*32
	call CopyMemory

CopyMemory:
	ld a, [hl]
	ld [de], a
	dec bc
	ld a, c
	or b
	ret z
	inc hl
	inc de
	jr CopyMemory

.clean_loop:
	ld a, 0
	ld [hl], a
	dec de
	ld a, d
	or b
	ret z
	inc de
	jr .clean_loop

	; configure and activate display
	ld a,LCDCF_ON|LCDCF_BG8000|LCDCF_BG9800|LCDCF_BGON|LCDCF_OBJ8|LCDCF_OBJOFF
	ld [rLCDC], a

inf:
	halt
	nop
	jr inf

; turn LCD off
LCD_off:
	ld a,[rLCDC]
	rlca		; sets the high bit of LCDC in the carry flag
	ret nc		; Display is already off (return if carry != 0)a

.wait_VBlank
	ld a,[rLY]	; read LCDC Y-coordinate
	cp 145		; compare it to 145 (are we in VBlank? 0000 - 144)
	jr nz, .wait_VBlank ; if this is false we go next, if true we jump.

	; we are in VBlank, 
	ld a,[rLCDC]  ; but the contents of the LCDC in a
	res 7,a		; apparently zeroing bit 8 on the LCD
	ld [rLCDC],a

	ret

Tiles:
;	DB $00, $00, $00, $00, $00, $00, $00, $00
;	DB $00, $00, $00, $00, $00, $00, $00, $00
;	DB $7C, $7C, $82, $FE, $82, $D6, $82, $D6
;	DB $82, $FE, $82, $BA, $82, $C6, $7C, $7C
	INCLUDE "basic_palette.z80"
TilesEnd:

Map:
	INCLUDE "test.z80"
MapEnd:
