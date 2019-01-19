_FONT_TILES		EQU		$9200

; Load the message into the register
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

INCLUDE "font/font.z80"

; New Game
SECTION "New Game", ROMX[$4000]
	db "> New Game", 0
