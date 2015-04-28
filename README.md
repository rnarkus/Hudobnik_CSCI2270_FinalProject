**Project Summary** :tada: :fireworks:

This program is an example of how to use Hashtables with an AI. it is very simple but uses your name and keywords that you type to get tailored responses back. Comes with an options menu to add in your own responses or just use the preloaded responses that come with the project. 

**How to Run**

To start, make sure you have all the latest software available. Next, check to see if you have an update terminal that includes C++11 if not, to run type this command into the terminal where the files are stored: “g++ -std=c++11 FinalProject.cpp Class.cpp”, otherwise type in “g++ FinalProject.cpp Class.cpp”. This will compile the project. If it throws any errors, fix them now before moving on. Next type in “./a.out” to get the program to run.

**Program:**

Instructions should be on screen.

* Start by typing in your name (it can be your full name if you want).

* then you can try out different responses

* Type in “I am very very sick today bob!” as an example. The keyword here is “sick”

* You should get back a randomly generated response. Try this a few times and see the other responses for this keyword

* Next try accessing the options menu by typing in “1”

* You should see this

	=====Options:=====
	1. Enter in extra responses for BOB to learn
	2. Print all Keywords and their responses
	3. Delete a keyword
	4. Delete a Response
	5. Quit and return to program

* Try out different options

for example, number 4 will print a list of the keywords:

	Keywords:
	back
	thank
	unknown
	greet
	happy
	sick
	tired
	homework
	no problem
	stress
	name
	Type in keyword to find the response you want to delete:

The type in one of the keywords

	sick 
	0. Awwwwww I am so sorry you're sick! Hope you feel better Markus!!!
	1. Should I call the doctor for you? Just kidding! I can't do that for you.
	2. Don't die on me.
	Type in the number of the response you would like to delete:

then type in a number. For this example, we will pick 0

when you see the options display again, type in “2” to see the list of all keywords and responses. The one you deleted should not be there anymore.

* Go back to the main program by typing “5”

* Try out the program again using the keyword “sick”

* You should not see that response you deleted in the random outputs. 

* Type in “quit” to quit the program.

**Dependencies**

time.h

-rand() isn’t actually random, you need to set a time using this library to set how long it adds numbers to rand() then it picks from that, if you just use rand() without the library is defaults to 1

unistd.h 

-to use usleep();

iostream, fstream, and sstream, vector

**System Requirements**

Tested and coded on Mac with C++11 pre installed and Command Line Tools 6.2 installed (version 6.3 has bugs, I will update this if 6.3 is fixed). Using SublimeText2 for my IDE.

**Group Members**

N/A

**Contributors**

N/A

**Open issues/bugs**

Requests: more responses added to the file, 

bugs: issues while using getline(cin) in some cases, or when typing in a response, missing the first letter, not clean and not optimized, not a true driver file