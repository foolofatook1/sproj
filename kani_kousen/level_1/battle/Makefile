CC = lcc -Wa-l -Wl-m -Wl-j 

BINS = asakawa_battle.gb

all: $(BINS)

clean:
	rm -f ../../text/*.o *.o ../../text/*.lst *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm
############################################################
# Lets just start by trying to compile to a single memory 
# bank for the battle stuff.
#
#	This is going to bank 2 (ROM+RAM)
#		ROM bank 2 : -Wf-bo2
#		RAM bank 2 : -Wf-ba2
#
battle.o: battle.c
	$(CC) -Wf-bo2 -c -o $@ $<

../../text/text.o: ../../text/text.c
	$(CC) -Wf-bo2 -c -o $@ $<

# Lets link them now for the main thing
#	ROM+MBC1+RAM : -Wl-yt2
#	4 ROM banks  : -Wl-yo4
#	4 RAM banks  : -Wl-ya4
#
asakawa_battle.gb: asakawa_battle.o ../../text/text.o battle.o
	$(CC) -Wl-yt2 -Wl-yo4 -Wl-ya4 -o $@ asakawa_battle.o ../../text/text.o battle.o ../../text/assets/chain_border.o ../../text/assets/small_chain_border.o ../../text/assets/chain_border_tiles.o ../../text/assets/font.o

play:
	../../../bgb/*.exe *.gb
