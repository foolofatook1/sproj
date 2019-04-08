CC = lcc -Wa-l -Wl-m -Wl-j 

ASSETS = assets/black_screen.o assets/blank_screen.o assets/blank_screen_tiles.o assets/chain_border.o assets/chain_border_tiles.o assets/font.o assets/small_chain_border.o text.o

BIN = test.gb

all: $(BIN)

clean:
	rm -f *.o *.lst .*.swp .swp *.map *.sym *.gb assets/*.o assets/*.lst assets/.*.swp assets/.swp assets/*.map assets/*.sym assets/*.gb

$(ASSETS):%.o : %.c
	$(CC) -c -o $@ $<

test.gb: test.o $(ASSETS)
	$(CC) -o $@ test.o $(ASSETS)

write:
	wine ~/bgb/bgb.exe *.gb
