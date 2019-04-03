all:
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -c -o blank_screen.o blank_screen.c 
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -c -o blank_screen_tiles.o blank_screen_tiles.c 
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -c -o level_1_screen.o level_1_screen.c 
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -c -o level_1_screen_tiles.o level_1_screen_tiles.c 
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -c -o shit_pot.o shit_pot.c 
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -c -o shit_pot_tiles.o shit_pot_tiles.c 


clean:
	rm *.o *.lst
