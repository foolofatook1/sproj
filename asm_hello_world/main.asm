INCLUDE "hardware.inc"
INCLUDE "second_map.inc"

SECTION "Header", ROM0[$100] 
        ; name  , mem type[optional addr -- this one begins at $100] 
        ; -- two sections with the same name is a no go
; specifically, execution begins at $100, and the header begins at $104.
; This leaves us 4 bytes of code

EntryPoint: ; This is where execution begins
    di ; Disable interrupts. 
    jp Start ; This whole function just goes to Start function

; Here is the header, which spans from $104 to $14f
REPT $150 - $104 
    db 0
ENDR

SECTION "Game code", ROM0

Start: 
    ; Turn off the LCD
.waitVBlank
    ld a, [rLY] 
    cp 144 ; Check if the LCD is past VBlank
    jr c, .waitVBlank

    xor a ; ld a, 0 ; We only need ot resest a value with bit 7 reset, but 0 okay
    ld [rLCDC], a ; We will have to write to LCDC again later

    ; Now LCD is turned off!

    ld hl, $9000
    ld de, FontTiles
    ld bc, FontTilesEnd - FontTiles
.copyFont
    ld a, [de] ; Grab 1 byte from the source
    ld [hli], a ; Place it at the destination, incrementing hl
    inc de ; Move to next byte
    dec bc ; Decrement count
    ld a, b ; Check if count is 0, since 'dec bc' doesn't update flags
    or c
    jr nz, .copyFont

    ld hl, $9400 ; This will print the string at the top-left corner 
    ld de, HelloWorldStr
.copyString
    ld a, [de]
    ld [hli], a
    inc de
    and a ; Check if the byte we just copied is zero
    jr nz, .copyString ; Continue if it's not

    jr nz, .copyString

    ; Init display registers
    ld a, %11100100
    ld [rBGP], a

    xor a ; ld a, 0
    ld [rSCY], a
    ld [rSCX], a

    ; Shut sound down
    ld [rNR52], a

    ; Turn screen on, display background
    ld a, %10000001
    ld [rLCDC], a

    ; to trap CPU into infinite loop do the following:
    ; Lock up
.lockup
    jr .lockup

SECTION "Font", ROM0

FontTiles:
INCBIN "second_map.z80" ; makes RGBDS copy the file's contents directly into the made ROM
FontTilesEnd:

SECTION "Hello World!", ROM0

HelloWorldStr: 
    db "Happy New Year!", 0
    ;db tells TGBASM to place some bytes of data (dw for 16-bit words, and dl 
    ;for 32). With db, you can also use strings, which are automatically encoded,
    ; by default using ASCII. The 0 at the end tells the copy function to stop.
