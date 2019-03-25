CC = lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG

INCLUDE = ../kani_kousen/assets/sprites/miner_walk_up.o

BINS = half_sprites.gb

all: $(BINS)

clean: 
	rm -f ../kani_kousen/assets/sprites/*.o ../kani_kousen/assets/sprites/*.lst ../kani_kousen/assets/sprites/.*.swp .*.swp *.lst *.map *.o *.gb *.sym

%.o : %.c
	$(CC) -c -o $@ $<

half_sprites.gb: half_sprites.o $(INCLUDE)
	$(CC)  -o $@ half_sprites.o $(INCLUDE)

play:
	../bgb/bgb.exe *.gb
