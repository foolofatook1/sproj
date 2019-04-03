all:
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o chain_border.o chain_border.c
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o font.o font.c
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o chain_border_tiles.o chain_border_tiles.c	
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o small_chain_border.o small_chain_border.c

clean:
	rm *.o *.lst
