CC = lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -Wl-yp0x143=0x80 

TEXT_INCLUDE = text/assets/small_chain_border.o text/assets/chain_border.o text/assets/chain_border_tiles.o text/assets/font.o text/assets/blank_screen_tiles.o text/assets/black_screen.o text/assets/blank_screen.o text/text.o 

LEVEL_1_INCLUDE = level_1/assets/shit_pot.o assets/sprites/hero_front_idle.o assets/sprites/hero_back_idle.o assets/sprites/fisherman_front_idle.o assets/sprites/fisherman_idle_back.o assets/sprites/miner_walk_left.o assets/sprites/miner_walk_up.o assets/sprites/miner_idle_back.o assets/sprites/student_idle_back.o assets/sprites/asakawa_front_idle.o assets/sprites/asakawa_air_shot.o level_1/asakawa_battle.o level_1/level_1.o

LEVEL_2_INCLUDE = level_2/level_2.o  #level_2/test.o

LEVEL_3_INCLUDE = level_3/level_3.o

CRAB_CATCH_INCLUDE = level_2/crab_catch.o 

# level_2_include starts at assets/sprites/hero_lie_down.o
# crab_catch_include starts after student_front_idle.o
LEVEL_ASSETS = assets/level_assets/level_assets.o assets/sprites/hero_lie_down.o assets/sprites/hero_walk_sideways.o assets/sprites/fisherman_walk_sideways.o assets/sprites/fisherman_walk_up.o assets/sprites/hero_walk_down.o assets/sprites/hero_walk_up.o assets/bkgs/deck.o assets/sprites/asakawa_walk_sideways.o assets/sprites/miner_front_idle.o assets/sprites/student_front_idle.o assets/sprites/norm_crab.o assets/sprites/king_crab.o assets/sprites/bed.o assets/sprites/soldier.o assets/sprites/student_lie_down.o assets/sickle_hammer.o assets/sh_tiles.o

SOUND_INCLUDE = sound/sound.o

START_UP_INCLUDE = start_up/start_up.o

BATTLE_INCLUDE = battle/battle.o

SPRITE_PROPS = assets/sprite_palette.o

BKG_PROPS = assets/bkg_palette.o

ENDING_INCLUDE = end/end.o

BINS = kani_kousen.gb

all: $(BINS)

clean: 
	rm -f .*.swp *.o *.lst *.map *.gb *~ *.rel *.cdb .swp *.ihx *.lnk *.sym *.asm *.sn1 text/assets/*.lst text/assets/*.lst text/*.o text/*.lst text/.*.swp $(TEXT_INCLUDE) assets/sprites/*.lst level_1/assets/*.lst assets/sprites/.*.swp $(LEVEL_1_INCLUDE) start_up/assets/*.lst start_up/assets/.*.swp start_up/assets/*.o start_up/.*.swp start_up/*.lst start_up/*.map start_up/*.sym start_up/*.rel $(START_UP_INCLUDE) level_1/.*.swp level_1/*.lst $(BATTLE_INCLUDE) battle/*.lst battle/*.map battle/.*.swp $(LEVEL_2_INCLUDE) level_2/*.lst level_2/*.map level_2/.*.swp level_2/*.o $(SPRITE_PROPS) $(BKG_PROPS) assets/*.lst assets/*.map assets/.*.swp $(LEVEL_ASSETS) assets/level_assets/*.lst assets/level_assets/*.map assets/level_assets/.*.swp $(CRAB_CATCH_INCLUDE) level_3/*.o level_3/.*.swp level_3/*.map level_3/*.rel level_3/*.lst level_3/*.asm $(LEVEL_3_INCLUDE) end/.*.swp end/*.map end/*.rel end/*.lst end/*.asm $(ENDING_INCLUDE) sound/.*.swp sound/*.map sound/*.rel sound/*.lst sound/*.asm $(SOUND_INCLUDE)

$(TEXT_INCLUDE):%.o : %.c
	$(CC) -c -o $@ $<
$(START_UP_INCLUDE):%.o : %.c
	$(CC) -c -o $@ $<
$(LEVEL_1_INCLUDE):%.o : %.c
	$(CC) -c -o $@ $<
$(BATTLE_INCLUDE):%.o : %.c
	$(CC) -c -o $@ $<
$(SPRITE_PROPS):%.o : %.c
	$(CC) -c -o $@ $<
$(BKG_PROPS):%.o : %.c
	$(CC) -c -o $@ $<
$(LEVEL_ASSETS):%.o : %.c
	$(CC) -c -o $@ $<
$(LEVEL_2_INCLUDE):%.o : %.c
	$(CC) -c -o $@ $<
$(CRAB_CATCH_INCLUDE):%.o : %.c
	$(CC) -c -o $@ $<
$(LEVEL_3_INCLUDE):%.o : %.c
	$(CC) -c -o $@ $<
$(ENDING_INCLUDE):%.o : %.c
	$(CC) -c -o $@ $<
$(SOUND_INCLUDE):%.o : %.c

kani_kousen.gb: main.o $(START_UP_INCLUDE) $(TEXT_INCLUDE) $(LEVEL_1_INCLUDE) $(BATTLE_INCLUDE) $(LEVEL_2_INCLUDE) $(SPRITE_PROPS) $(BKG_PROPS) $(LEVEL_ASSETS) $(CRAB_CATCH_INCLUDE) $(LEVEL_3_INCLUDE) $(ENDING_INCLUDE) $(SOUND_INCLUDE)
	$(CC) -o $@ main.o $(START_UP_INCLUDE) $(TEXT_INCLUDE) $(LEVEL_1_INCLUDE) $(BATTLE_INCLUDE) $(LEVEL_2_INCLUDE) $(SPRITE_PROPS) $(BKG_PROPS) $(LEVEL_ASSETS) $(CRAB_CATCH_INCLUDE) $(LEVEL_3_INCLUDE) $(ENDING_INCLUDE) $(SOUND_INCLUDE)

play:
	~/bgb/bgb.exe *.gb
