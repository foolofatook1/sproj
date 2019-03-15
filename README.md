# sproj
For my senior project my goal is to develop a GameBoy game
based on [Kobayashi Takiji](https://en.wikipedia.org/wiki/Takiji_Kobayashi)'s
novel, [*Kani Kousen*](https://en.wikipedia.org/wiki/Kani_K%C5%8Dsen) (*蟹工船*) or *The Crab Cannery Ship.* 
Given this is a Computer Science and Japanese Language & Literature joint major,
the primary interest from the aspect of Japanese Language & Lit.
is looking at the particular ways in which a video game
interpretation of a novel is capable of telling a story.
For the Computer Science aspect I'm looking to add internet
connectivity to my GameBoy via the game cartridge.
Hopefully this game will be able to be accessed
from any GameBoy && person with the "smart" cartridge on this website here.

In the months leading up to the fall semester of 2018 I've been preparing 
by looking at the narrative structure of notable nintendo games; such as 
Final Fantasy, and most notably, Dragon Quest. Drawing on this research I 
hope to better inform my own ability to tell a story using this unique medium.
This essay located [here](https://drive.google.com/file/d/0B9o0-nqRyNwnV0R5c2E3bXBjSzNJWTNQN00tS2FGOHpCc1JR/view?usp=sharing) is particularly interesting (if you can 
read Japanese) because of its evaluation of the game Dragon Quest III as a 
candidate for a Sci-fi award. Looking into the kind of development tools 
that will come in handy for programming a GameBoy game has also been a part 
of the research leading up to this point. 


## Some notes on things that I should consider moving forward: ##

	* Memory is layed out differently when banking
		* must do further research into those differences
	* should also look deeper into the compiling differences 
	  between when compiling a game with ROM and RAM banks 
	  as opposed to the normal setup that I've been using thus far.

	* until then, the game can continue to be developed by making
	  little "games" within, which will then be configured to match
	  the memory layout later.


## Installing and Downloading Beta Game ##
I've just decided that if one *truly* feels compelled to download a copy of this
game in its current form, I may as well let them. Here's how it's done:

**Step 1: Download the ZIP**
At the top of the page you will see a bar that shows # of commits, # of branches,
# of releases, and # of contributors. Beneathe this bar is a green button which reads:
"Clone or download." Click that, and choose: "Download ZIP". 

**Step 2: Unzip the ZIP**
Depending on your operating system this may work differently, but it should be pretty
simple to unzip (decompress) the file, which should be in your Downloads folder.
In linux it's a command like:
	cd ~/Downloads; unzip *.zip

**Step 3: Make the game**
Here's where it gets tricky. You'll want to install gbdk into your computer, which can be 
done <a href=https://sourceforge.net/projects/gbdk/files/>here</a>. You'll have to do this 
fully before you can proceed any further, but if this is done properly. You will then be able
to go to the location ~/Downloadsproj/kani_kousen, and run the game by typing the following in
your console:
	make; make play

**Note to reader:**
Notable that this way of making the game might only work in linux. Sorry.
