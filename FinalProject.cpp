
#include "Class.h"
#include <iostream>
#include <unistd.h>

using namespace std;

void displayLogo();

int main(){
	Prog resp = Prog(); 
	string in_keyword, in_response, input, name;
	displayLogo();
	resp.insertResp("greet", "Welcome, what is your name?");
	resp.insertResp("greet", "Welcome, what the cluck is your name?");
	resp.insertResp("greet", "Hello, my name is Bob, what is your name?");
	resp.insertResp("greet", "My name is Bob, What can I do for you today?");

	resp.displayResp("greet");
	cin >> name;
	resp.insertResp("name", "Hi, " + name +"! How are you today?");
	resp.insertResp("name", "Hello, " + name +"! What's up?");
	resp.insertResp("name", "Guten Tag, " + name +"! Wie geht's?");
	resp.displayResp("name");
	
	while (in_keyword != "quit"){
		cin >> input;
			if (input == "1"){
			cin.ignore();
			getline(cin, in_keyword);
			getline(cin, in_response);
			resp.insertResp(in_keyword, in_response);
			resp.printAllResps();
		
	}
		
	}
	cout << "Goodbye!" << endl;
}

void displayLogo(){
	int DELAY = 300000;
	cout<<"	   BBBBBBB   OOOOOOOO   BBBBBBB	   "<<endl;
	usleep(DELAY);
	cout<<"	   B     B   O      O   B     B	   "<<endl;
	usleep(DELAY);
	cout<<"	   B     B   O      O   B     B	   "<<endl;
	usleep(DELAY);
	cout<<"	   BBBBBBB   O      O   BBBBBBB 	   "<<endl;
	usleep(DELAY);
	cout<<"	   B      B  O      O   B      B	   "<<endl;
	usleep(DELAY);
	cout<<"	   B      B  O      O   B      B	   "<<endl;
	usleep(DELAY);
	cout<<"	   BBBBBBBB  OOOOOOOO   BBBBBBBB	   "<<endl;
}