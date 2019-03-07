CC = lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG

BINS = main.gb

all: $(BINS)

clean: 
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm level_1/*.o level_1/*.lst level_1/*.map level_1/*.gb level_1/*~ level_1/*.rel level_1/*.cdb level_1/*.ihx level_1/*.lnk level_1/*.sym level_1/*.asm text/*.o text/*.lst text/*.map text/*.gb text/*~ text/*.rel text/*.cdb text/*.cdb text/*.ihx text/*.lnk text/*.sym text/*.asm

###
# Text and text assets
#
text/assets/chain_border.o: text/assets/chain_border.c
	$(CC) -c -o $@ $<

text/assets/chain_border_tiles.o: text/assets/chain_border_tiles.c
	$(CC) -c -o $@ $<

text/assets/font.o: text/assets/font.c
	$(CC) -c -o $@ $<

text/text.o: text/text.c
	$(CC) -c -o $@ $<
###
# Level 1 and assets
#

level_1/assets/level_1_screen_tiles.o: level_1/assets/level_1_screen_tiles.c
	$(CC) -c -o $@ $<

level_1/assets/level_1_screen.o: level_1/assets/level_1_screen.c
	$(CC) -c -o $@ $<

level_1/assets/shit_pot_tiles.o: level_1/assets/shit_pot_tiles.c
	$(CC) -c -o $@ $<

level_1/assets/shit_pot.o: level_1/assets/shit_pot.c
	$(CC) -c -o $@ $<

assets/sprites/hero_front_idle.o: assets/sprites/hero_front_idle.c
	$(CC) -c -o $@ $<

assets/sprites/hero_back_idle.o: assets/sprites/hero_back_idle.c
	$(CC) -c -o $@ $<

assets/sprites/fisherman_front_idle.o: assets/sprites/fisherman_front_idle.c
	$(CC) -c -o $@ $<

assets/sprites/fisherman_idle_back.o: assets/sprites/fisherman_idle_back.c
	$(CC) -c -o $@ $<

assets/sprites/miner_walk_left.o: assets/sprites/miner_walk_left.c
	$(CC) -c -o $@ $<

assets/sprites/miner_walk_up.o: assets/sprites/miner_walk_up.c
	$(CC) -c -o $@ $<

assets/sprites/miner_idle_back.o: assets/sprites/miner_idle_back.c
	$(CC) -c -o $@ $<

assets/sprites/student_idle_back.o: assets/sprites/student_idle_back.c
	$(CC) -c -o $@ $<

assets/sprites/asakawa_front_idle.o: assets/sprites/asakawa_front_idle.c
	$(CC) -c -o $@ $<

assets/sprites/asakawa_air_shot.o: assets/sprites/asakawa_air_shot.c
	$(CC) -c -o $@ $<

level_1/level_1.o: level_1/level_1.c 
	$(CC) -c -o $@ $<

main.gb: main.o text/text.o level_1/level_1.o start_up/start_up.o text/assets/chain_border.o text/assets/font.o text/assets/chain_border_tiles.o start_up/assets/open_screen.o start_up/assets/ship_tiles.o level_1/assets/level_1_screen_tiles.o level_1/assets/level_1_screen.o level_1/assets/shit_pot_tiles.o level_1/assets/shit_pot.o assets/sprites/hero_front_idle.o assets/sprites/hero_back_idle.o assets/sprites/fisherman_front_idle.o assets/sprites/fisherman_idle_back.o assets/sprites/miner_walk_left.o assets/sprites/miner_walk_up.o assets/sprites/miner_idle_back.o assets/sprites/student_idle_back.o assets/sprites/asakawa_front_idle.o assets/sprites/asakawa_air_shot.o
	$(CC) -o $@ main.o text/text.o level_1/level_1.o start_up/start_up.o text/assets/chain_border.o text/assets/font.o text/assets/chain_border_tiles.o start_up/assets/open_screen.o start_up/assets/ship_tiles.o level_1/assets/level_1_screen_tiles.o level_1/assets/level_1_screen.o level_1/assets/shit_pot_tiles.o level_1/assets/shit_pot.o assets/sprites/hero_front_idle.o assets/sprites/hero_back_idle.o assets/sprites/fisherman_front_idle.o assets/sprites/fisherman_idle_back.o assets/sprites/miner_walk_left.o assets/sprites/miner_walk_up.o assets/sprites/miner_idle_back.o assets/sprites/student_idle_back.o assets/sprites/asakawa_front_idle.o assets/sprites/asakawa_air_shot.o

play:
	../bgb/*.exe *.gb
