CC = lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG

TEXT_INCLUDE = text/assets/chain_border.o text/assets/chain_border_tiles.o text/assets/font.o text/assets/blank_screen_tiles.o text/assets/blank_screen.o text/text.o

LEVEL_1_INCLUDE = level_1/assets/shit_pot.o assets/sprites/hero_front_idle.o assets/sprites/hero_back_idle.o assets/sprites/fisherman_front_idle.o assets/sprites/fisherman_idle_back.o assets/sprites/miner_walk_left.o assets/sprites/miner_walk_up.o assets/sprites/miner_idle_back.o assets/sprites/student_idle_back.o assets/sprites/asakawa_front_idle.o assets/sprites/asakawa_air_shot.o level_1/level_1.o

START_UP_INCLUDE = start_up/start_up.o

BINS = main.gb

all: $(BINS)

clean: 
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm text/*.o text/*.lst text/*.map text/*.gb text/*~ text/*.rel text/*.cdb text/*.ihx text/*.lnk text/*.sym text/*.asm start_up/*.o start_up/*.lst start_up/*.map start_up/*.gb start_up/*~ start_up/*.rel start_up/*.cdb start_up/*.ihx start_up/*.lnk start_up/*.sym start_up/*.asm level_1/*.o level_1/*.lst level_1/*.map level_1/*.gb level_1/*~ level_1/*.rel level_1/*.cdb level_1/*.ihx level_1/*.lnk level_1/*.sym level_1/*.asm text/assets/*.lst $(TEXT_INCLUDE) assets/sprites/*.lst level_1/assets/*.lst $(LEVEL_1_INCLUDE) start_up/assets/*.lst start_up/assets/*.o start_up/*.lst $(START_UP_INCLUDE)

####
# Text file & assets
#
text/assets/chain_border.o: text/assets/chain_border.c
	$(CC) -c -o $@ $<

text/assets/chain_border_tiles.o: text/assets/chain_border_tiles.c
	$(CC) -c -o $@ $<

text/assets/font.o: text/assets/font.c
	$(CC) -c -o $@ $<

text/assets/blank_screen_tiles.o: text/assets/blank_screen_tiles.c
	$(CC) -c -o $@ $<

text/assets/blank_screen.o: text/assets/blank_screen.c
	$(CC) -c -o $@ $<

text/text.o: text/text.c
	$(CC) -c -o $@ $<

###
# Level 1 file & assets
#

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

###
# Start up file (no assets)
#

start_up/start_up.o: start_up/start_up.c
	$(CC) -c -o $@ $<

main.gb: main.o $(START_UP_INCLUDE) $(TEXT_INCLUDE) $(LEVEL_1_INCLUDE)
	$(CC) -o $@ main.o $(START_UP_INCLUDE) $(TEXT_INCLUDE) $(LEVEL_1_INCLUDE)

play:
	../bgb/*.exe *.gb
