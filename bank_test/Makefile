CC = lcc -Wa-l -Wl-m -Wl-j 

BINS = banks.gb

all: $(BINS)

clean:
	rm -f assets/*.o *.o assets/*.lst *.lst assets/*.map *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm
############################################################
# Lets just start by trying to compile to a single memory 
# bank for the battle stuff.
#
#	This is going to bank 2 (ROM+RAM)
#		ROM bank 2 : -Wf-bo2
#		RAM bank 2 : -Wf-ba2
#
text.o: text.c
	$(CC) -Wf-bo2 -Wf-ba2 -c -o $@ $<

###
# We also want our assets in bank 2 :p
#
assets/chain_border.o: assets/chain_border.c
	$(CC) -Wf-bo2 -Wf-ba2 -c -o $@ $<

assets/chain_border_tiles.o: assets/chain_border_tiles.c
	$(CC) -Wf-bo2 -Wf-ba2 -c -o $@ $<

assets/small_chain_border.o: assets/small_chain_border.c
	$(CC) -Wf-bo2 -Wf-ba2 -c -o $@ $<

assets/font.o: assets/font.c
	$(CC) -Wf-bo2 -Wf-ba2 -c -o $@ $<


###
# And include text file now
#

# Lets link them now for the main thing
#	ROM+MBC1+RAM : -Wl-yt2
#	4 ROM banks  : -Wl-yo4
#	4 RAM banks  : -Wl-ya4
#
banks.gb: banks.o text.o assets/chain_border.o assets/chain_border_tiles.o assets/small_chain_border.o assets/font.o
	$(CC) -Wl-yt2 -Wl-yo4 -Wl-ya4 -o $@ banks.o text.o assets/chain_border.o assets/chain_border_tiles.o assets/small_chain_border.o assets/font.o

play:
	../bgb/*.exe *.gb
