CC = lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG 

SPRITES = asakawa_air_shot.o asakawa_front_idle.o asakawa_walk_sideways.o bed.o fisherman_front_idle.o fisherman_idle_back.o fisherman_walk_sideways.o fisherman_walk_up.o hero_back_idle.o hero_front_idle.o hero_lie_down.o hero_walk_down.o hero_walk_sideways.o hero_walk_up.o king_crab.o miner_front_idle.o miner_idle_back.o miner_walk_left.o miner_walk_up.o norm_crab.o soldier.o student_front_idle.o student_idle_back.o student_lie_down.o 

TILES = blank_screen_tiles.o chain_border_tiles.o font.o sh_tiles.o

FILES = text.o

BIN = main.gb

all: $(BIN)

clean:
	rm -f *.o .*.swp .swp *.lst *.map *.asm *.ASM *.rel *.sym *.gb

%.o:%.c
	$(CC) -c -o $@ $<

main.gb: main.o $(SPRITES) $(TILES) $(FILES)
	$(CC) -o $@ main.o $(SPRITES) $(TILES) $(FILES)

play:
	~/bgb/*.exe *.gb
