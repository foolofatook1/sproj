CC = lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -Wl-yp0x143=0x80

BIN = sound.gb

all: $(BIN)

%.o: %.c	
	$(CC) -c -o $@ $<

sound.gb: sound.o
	$(CC) -o $@ sound.o

play:
	~/bgb/bgb.exe *.gb

clean:
	rm -f *.lst .*.swp .swp *.map *.o *.gb *.asm *.sym *.sn1
