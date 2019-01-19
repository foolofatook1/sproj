; Hello joypad
; David Pello 2010
; ladecadence.net
; For the tutorial(Spanish): 
	; http://wiki.ladecadence.net/doku.php?id=tutorial_de_ensamblador

INCLUDE "gbhw.inc"          ; import file definitions

; We define constants to work with our sprite
_SPR0_Y     EQU     _OAMRAM ; sprite Y 0 is the beginning of the sprite mem
_SPR0_X     EQU     _OAMRAM+1
_SPR0_NUM   EQU     _OAMRAM+2
_SPR0_ATT   EQU     _OAMRAM+3

;variable to save the state of the pad
_PAD        EQU     _RAM ; at the beginning of the internal RAM

	; The program begins here:
SECTION "start",ROM0[$0100]
	nop
	jp      inicio

	; Head of the ROM (Macro defined in gbhw.inc)
	; defines a rom without mapper, without 32K RAM, the basics
	; (Such as tetris)
	ROM_HEADER  ROM_NOMBC, ROM_SIZE_32KBYTE, RAM_SIZE_0KBYTE

	; Here begins are program
inicio:
	nop
	di                      ; disables interrupts
	ld      sp, $ffff       ; We aim pile atop the ram

inicializacion:
	ld      a, %11100100    ; Palette colors from the darkest to
	; lighter, 11 10 01 00
	ld      [rBGP], a       ; We write this in the background palette register
	ld      [rOBP0], a      ; and sprite palette 0

	; create another palette to the palette 2 sprites, reverse to normal
	ld      a, %00011011
	ld      [rOBP1], a


	ld      a, 0            ; write 0 records scroll in X and Y 
	ld      [rSCX], a       ; positioned so that the visible screen
	ld      [rSCY], a       ; at the beginning (upper left) of the fund.

	call    apaga_LCD       ; We call the routine that turns off the LCD

	; We load the tiles in memory of tiles

	ld      hl, Tiles       ; HL loaded in the direction of our tile
	ld      de, _VRAM       ; address in the video memory
	ld      b, 32           ; b = 32, number of bytes to copy (2 tiles)

.bucle_carga:
	ld      a,[hl]          ; load in the data pointed to by HL
	ld      [de], a         ; and we put in the address pointed in DE
	dec     b               ; decrement b, b = b-1
	jr      z, .fin_bucle_carga ; if b = 0, finished, nothing left to copy 
	inc     hl              ; We increased the read direction
	inc     de              ; We increased the write direction
	jr      .bucle_carga    ; we follow
.fin_bucle_carga:

	;  We clean the screen (fill entire background map), with tile 0

	ld      hl, _SCRN0
	ld      de, 32*32       ; number of tiles on the background map
.bucle_limpieza_fondo:
	ld      a, 0            ; tile 0 is our empty tile
	ld      [hl], a
	dec     de
	; Now I have to check if it is zero, to see if I have it 
	; finishes copying. dec not modify any flag, so I can not
	; check the zero flag directly, but that is zero, dye 
	; They must be zero two, so I can make or including 
	; and if the result is zero, both are zero.
	ld      a, d            ; d loaded in to
	or      e               ; and make a or e
	jp      z, .fin_bucle_limpieza_fondo    ; if d or e is zero, it is zero. 
	; Ended.
	inc     hl              ; We increased the write direction
	jp      .bucle_limpieza_fondo
.fin_bucle_limpieza_fondo

	; Well, we have all the map tiles filled with tile 0
	; We clean the memory of sprites

	ld      hl, _OAMRAM     ; sprite attribute memory
	ld      de, 40*4        ; 40 sprites x 4 bytes each
.bucle_limpieza_sprites
	ld      a, 0            ; we will start fresh, so the sprites
	ld      [hl], a         ; unused, will be offscreen
	dec     de
	; as in previous loop
	ld      a, d            ; d loaded in to
	or      e               ; and make a or e
	jp      z, .fin_bucle_limpieza_sprites  ; if d or e is zero, it is zero.
	inc     hl              ; We increased the write direction
	jp      .bucle_limpieza_sprites
.fin_bucle_limpieza_sprites

	; Now we will create the sprite.

	ld      a, 74
	ld      [_SPR0_Y], a    ; Y position of the sprite
	ld      a, 90
	ld      [_SPR0_X], a    ; X position of the sprite
	ld      a, 1
	ld      [_SPR0_NUM], a  ; number of tile on the table that we will use tiles
	ld      a, 0
	ld      [_SPR0_ATT], a  ; special attributes, so far nothing.

	; configure and activate the display
	ld      a, LCDCF_ON|LCDCF_BG8000|LCDCF_BG9800|LCDCF_BGON|LCDCF_OBJ8|LCDCF_OBJON
	ld      [rLCDC], a


main:
	call 	lee_pad

.wait:
	ld		a, [rLY]
	cp		145
	jr		nz, .wait

	ld		a, [_PAD]
	and		%00010000
	call	nz, mueve_derecha

	ld		a, [_PAD]
	and		%00100000
	call	nz, mueve_izquierda

	ld		a, [_PAD]
	and		%01000000
	call	nz, mueve_arriba

	ld		a, [_PAD]
	and		%10000000
	call	nz, mueve_abajo

	call retardo

	call main


mueve_derecha:
	ld		a, [_SPR0_X]
	cp		160
	ret		z

	inc		a
	ld		[_SPR0_X], a
	ret

mueve_izquierda:
	ld		a, [_SPR0_X]
	cp		8
	ret		z

	dec		a
	ld		[_SPR0_X], a
	ret

mueve_arriba:
	ld		a, [_SPR0_Y]
	cp		16
	ret		z

	dec		a
	ld		[_SPR0_Y], a
	ret

mueve_abajo:
	ld		a, [_SPR0_Y]
	cp		16
	ret		z

	dec		a
	ld		[_SPR0_Y], a
	ret

apaga_LCD:
	ld      a,[rLCDC]
	rlca                    ; It sets the high bit of LCDC in the carry flag
	ret     nc              ; Display is already off, again.

	; We VBlank hope to, because we can not turn off the screen
	; some other time

.espera_VBlank
	ld      a, [rLY]
	cp      145
	jr      nz, .espera_VBlank

	; we are in VBlank, turn off the LCD 
	ld      a,[rLCDC]       ;in A, the contents of the LCDC
	res     7,a             ; we zero bit 7 (on the LCD)
	ld      [rLCDC],a       ; We wrote in the LCDC register content A

	ret                     ; return

; Routine reading pad
lee_pad:
	;  we will read the Cruzeta:
	ld      a, %00100000    ; bit 4-0, 5-1 bit (on Cruzeta, no buttons)
	ld      [rP1], a

	; now we read the status of the Cruzeta, to avoid bouncing
	; We do several readings
	ld      a, [rP1]
	ld      a, [rP1]
	ld      a, [rP1]
	ld      a, [rP1]

	and     $0F             ; only care about the bottom 4 bits.
	swap    a               ; lower and upper exchange. 
	ld      b, a            ; We keep Cruzeta status in b

	; we go for the buttons
	ld      a, %00010000    ; bit 4 to 1, bit 5 to 0 (enabled buttons, not Cruzeta)
	ld      [rP1], a

	; read several times to avoid bouncing
	ld      a, [rP1]
	ld      a, [rP1]
	ld      a, [rP1]
	ld      a, [rP1]

	; we at A, the state of the buttons
	and     $0F             ; only care about the bottom 4 bit
	or      b               ; or make a to b, to "meter" in Part
	; A superior, Cruzeta status.

	; we now have at A, the state of all, we complement and
	; store it in the variable
	cpl
	ld      [_PAD], a
	; return
	ret


retardo:
	ld		de, 2000
.delay:
	dec		de
	ld		a, d
	or		e
	jr		z, .fin_delay
	nop
	jr		.delay
.fin_delay:
	ret

	; Our tiles Facts
Tiles:
	DB  $AA, $00, $44, $00, $AA, $00, $11, $00
	DB  $AA, $00, $44, $00, $AA, $00, $11, $00
	DB  $3E, $3E, $41, $7F, $41, $6B, $41, $7F
	DB  $41, $63, $41, $7F, $3E, $3E, $00, $00
EndTiles:
