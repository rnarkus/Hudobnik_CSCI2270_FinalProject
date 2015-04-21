Project Summary
A simple c++ program that uses HashTables to display responses for a simple Eliza Chatbot AI.

How to Run
N/A

Dependencies
#include <time.h> // rand() isn’t actually random, you need to set a time using this library to set how long it adds numbers to rand() then it picks from that, is you just use rand() without the library is defaults to 1
#include <unistd.h> to use usleep();

System Requirements
Tested and coded on Mac with C++11 pre installed and Command Line Tools 6.2 installed (version 6.3 has bugs, I will update this if 6.3 is fixed). Using SublimeText2 for my IDE.

Group Members
N/A

Contributors
N/A

Open issues/bugs
When adding in an extra response and the printing out, seg fault. Pretty are it is how I implemented my function in Class.cpp