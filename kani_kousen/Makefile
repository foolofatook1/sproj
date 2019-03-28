CC = lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -Wl-yp0x143=0x80 

TEXT_INCLUDE = text/assets/small_chain_border.o text/assets/chain_border.o text/assets/chain_border_tiles.o text/assets/font.o text/assets/blank_screen_tiles.o text/assets/black_screen.o text/assets/blank_screen.o text/text.o 

LEVEL_1_INCLUDE = level_1/assets/shit_pot.o assets/sprites/hero_front_idle.o assets/sprites/hero_back_idle.o assets/sprites/fisherman_front_idle.o assets/sprites/fisherman_idle_back.o assets/sprites/miner_walk_left.o assets/sprites/miner_walk_up.o assets/sprites/miner_idle_back.o assets/sprites/student_idle_back.o assets/sprites/asakawa_front_idle.o assets/sprites/asakawa_air_shot.o level_1/asakawa_battle.o level_1/level_1.o

LEVEL_2_INCLUDE = level_2/level_2.o assets/sprites/hero_lie_down.o assets/sprites/hero_walk_sideways.o assets/sprites/fisherman_walk_sideways.o

LEVEL_ASSETS = assets/level_assets/level_assets.o

START_UP_INCLUDE = start_up/start_up.o

BATTLE_INCLUDE = battle/battle.o

SPRITE_PROPS = assets/sprite_palette.o

BKG_PROPS = assets/bkg_palette.o

BINS = main.gb

all: $(BINS)

clean: 
	rm -f .*.swp *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm text/assets/*.lst text/assets/*.lst text/*.o text/*.lst text/.*.swp $(TEXT_INCLUDE) assets/sprites/*.lst level_1/assets/*.lst assets/sprites/.*.swp $(LEVEL_1_INCLUDE) start_up/assets/*.lst start_up/assets/.*.swp start_up/assets/*.o start_up/.*.swp start_up/*.lst $(START_UP_INCLUDE) level_1/.*.swp level_1/*.lst $(BATTLE_INCLUDE) battle/*.lst battle/*.map battle/.*.swp $(LEVEL_2_INCLUDE) level_2/*.lst level_2/*.map level_2/.*.swp $(SPRITE_PROPS) $(BKG_PROPS) assets/*.lst assets/*.map assets/.*.swp $(LEVEL_ASSETS) assets/level_assets/*.lst assets/level_assets/*.map assets/level_assets/.*.swp

%.o : %.c
	$(CC) -c -o $@ $<

main.gb: main.o $(START_UP_INCLUDE) $(TEXT_INCLUDE) $(LEVEL_1_INCLUDE) $(BATTLE_INCLUDE) $(LEVEL_2_INCLUDE) $(SPRITE_PROPS) $(BKG_PROPS) $(LEVEL_ASSETS)
	$(CC) -o $@ main.o $(START_UP_INCLUDE) $(TEXT_INCLUDE) $(LEVEL_1_INCLUDE) $(BATTLE_INCLUDE) $(LEVEL_2_INCLUDE) $(SPRITE_PROPS) $(BKG_PROPS) $(LEVEL_ASSETS)

play:
	../bgb/bgb.exe *.gb
