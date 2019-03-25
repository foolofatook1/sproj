CC = lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -Wl-yp0x143=0x80

BIN = set_sprite_palette.gb

all: $(BIN)

clean:
	rm -f *.o *.lst *.map .*.swp *.sym *.gb

%.o : %.c
	$(CC) -c -o $@ $<

set_sprite_palette.gb: set_sprite_palette.o
	$(CC) -o $@ set_sprite_palette.o

play: 
	../bgb/bgb.exe *.gb
