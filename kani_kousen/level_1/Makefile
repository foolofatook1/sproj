all:
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -c -o asakawa_battle.o asakawa_battle.c
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o asakawa_battle.gb asakawa_battle.o

clean:
	rm *.o *.gb *.sym *.map *.lst

play:
	wine ../../bgb/*.exe asakawa_battle.gb
