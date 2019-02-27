all:
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -c -o main.o main.c 
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG -o main.gb main.o

clean:
	rm *.o *.gb *.sym *.map *.lst

play:
	wine ../bgb/*.exe main.gb
