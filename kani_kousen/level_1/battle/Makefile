CC = lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG

TEXT_INCLUDE = ../../text/assets/small_chain_border.o ../../text/assets/chain_border.o ../../text/assets/chain_border_tiles.o ../../text/assets/font.o ../../text/assets/blank_screen_tiles.o ../../text/assets/blank_screen.o ../../text/text.o

BATTLE_INCLUDE = ../../assets/sprites/asakawa_front_idle.o ../../assets/sprites/hero_back_idle.o battle.o

BINS = asakawa_battle.gb

all: $(BINS)

clean:
	rm -f $(TEXT_INCLUDE) ../../text/assets/*.lst ../../text/assets/.*.swp ../../text/assets/*.map ../../text/*.lst ../../text/*.map ../../text/.*.swp $(BATTLE_INCLUDE) ../../assets/sprites/*.lst ../../assets/sprites/.*.swp ../../asssets/sprites/*.map *.map *.lst .*.swp *.gb *.sym *.o

%.o : %.c
	$(CC) -c -o $@ $<

asakawa_battle.gb: asakawa_battle.o $(TEXT_INCLUDE) $(BATTLE_INCLUDE)
	$(CC) -o $@ asakawa_battle.o $(TEXT_INCLUDE) $(BATTLE_INCLUDE)

play:
	../../../bgb/*.exe *.gb
