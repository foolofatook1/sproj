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
	$(CC) -DUSE_SFT_FOR_REG -c -o $@ $<

bank2.o: bank2.c
	$(CC) -DUSE_SFT_FOR_REG -Wf-bo2 -Wf-ba2 -c -o $@ $<

###
# And include text file now
#

# Lets link them now for the main thing
#	ROM+MBC1+RAM : -Wl-yt2
#	4 ROM banks  : -Wl-yo4
#	4 RAM banks  : -Wl-ya4
#
banks.gb: banks.o text.o bank2.o
	$(CC) -DUSE_SFT_FOR_REG -Wl-yt2 -Wl-yo4 -Wl-ya4 -o $@ banks.o text.o bank2.o

play:
	../bgb/*.exe *.gb
