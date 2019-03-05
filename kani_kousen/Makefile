all:
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -c -o main.o main.c 
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o main.gb main.o level_1/level_1.o start_up/start_up.o text/text.o level_1/assets/level_1_screen_tiles.o level_1/assets/level_1_screen.o level_1/assets/shit_pot_tiles.o level_1/assets/shit_pot.o assets/sprites/hero_front_idle.o assets/sprites/hero_back_idle.o assets/sprites/fisherman_front_idle.o assets/sprites/fisherman_idle_back.o assets/sprites/miner_walk_left.o assets/sprites/miner_walk_up.o assets/sprites/miner_idle_back.o assets/sprites/student_idle_back.o assets/sprites/asakawa_front_idle.o assets/sprites/asakawa_air_shot.o text/assets/chain_border.o text/assets/font.o text/assets/chain_border_tiles.o

clean:
	rm *.o *.gb *.sym *.map *.lst

play:
	wine ../bgb/*.exe main.gb
