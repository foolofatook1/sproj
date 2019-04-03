CC = lcc -Wa-l -Wl-m -Wl-j -DUSE_SFT_FOR_REG -Wl-yp0x143=0x80 

LEVEL_2_INCLUDE = level_2.o ../assets/sprites/hero_lie_down.o ../assets/sprites/hero_walk_sideways.o ../assets/sprites/fisherman_walk_sideways.o ../assets/sprites/fisherman_walk_up.o ../assets/sprites/hero_walk_down.o ../assets/sprites/hero_walk_up.o ../assets/bkgs/deck.o ../assets/sprites/asakawa_walk_sideways.o ../assets/sprites/miner_front_idle.o ../assets/sprites/student_front_idle.o ../assets/sprites/fisherman_front_idle.o

CRAB_CATCH_INCLUDE = crab_catch.o ../assets/sprites/norm_crab.o ../assets/sprites/king_crab.o

all: $(LEVEL_2_INCLUDE) $(CRAB_CATCH_INCLUDE)
clean: 
	rm -f .*.swp *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm *.sn1 

%.o : %.c
	$(CC) -Wf-bo2 -Wf-ba2 -c -o $@ $<
