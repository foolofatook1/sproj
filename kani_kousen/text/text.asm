INCLUDE "gbhw.inc"

; Constants
_FONT_TILES		EQU		$9200

; Variables
_BANK			EQU		_RAM
_PAD			EQU		_RAM+1

SECTION "VBlank", ROM0 [$0040]
	reti		; i suppose this returns and increments

SECTION "start", ROM0[$0100]
	nop
	jp	main

	
	ROM_HEADER ROM_NOMBC, ROM_SIZE_32KBYTE, RAM_SIZE_0KBYTE

main:
	nop
	di
	ld		sp, $ffff

write:
	; begin by loading variables
	ld		a, 1
	ld		[_BANK], a
	
	; palette
	ld		a, %11100100
	ld		[rBGP], a
	
	; scroll
	ld		a, 0
	ld		[rSCX], a
	ld 		[rSCY], a 
	call	LCD_off

	; load the tiles for the font
	ld		hl, Font
	ld		de, _FONT_TILES
	ld		bc, EndFont-Font

	call 	mem_cp

	; configure and activate the display
	ld		a, LCDCF_ON|LCDCF_BG8800|LCDCF_BG9800|LCDCF_BGON|LCDCF_OBJ8
	ld		[rLCDC], a

; main loop	
type:
	call	NewGame
	jr 		type
	
NewGame:
	ld		hl, $4000


; print message
print:
	push	hl
	ld		hl, _SCRN0+32*2+8
	ld		a, c
	cp		0
	jr		z, .done_y
.do_y:
	ld		de, 32
	add		hl, de
	dec 	a
	jr		nz, .do_y
.done_y:
	ld		a, b
	cp		4
	jr		z, .done_x
.done_x:
	push	hl
	pop		de
	pop		hl
.print:
	ld		a, [hl]
	cp		0
	ret		z
	ld		[de], a
	inc 	de
	inc 	hl
	jr		.print
	ret	

; LCD shutdown routine	
LCD_off:
	ld		a, [rLCDC]
	rlca
	ret		nc
	
	call 	wait_VBlank
	
	ld		a, [rLCDC]
	res		7, a
	ld		[rLCDC], a
	ret

wait_VBlank:
	ld		a, [rLY]
	cp 		145
	jr		nz, wait_VBlank
	ret
; memory copy routine
mem_cp:
	ld		a, [hl]
	ld		[de], a
	dec 	bc

	ld		a, c
	or		b
	ret 	z

	inc 	hl
	inc 	de
	jr		mem_cp

INCLUDE "font.z80"

; New Game
SECTION "New Game", ROMX[$4000]
	db "> New Game", 0
