
#include "Class.h"
#include <iostream>
#include <unistd.h>

using namespace std;

void displayLogo();
void displayOptions(Prog&);

int main(){
	Prog resp = Prog(); 
	string input, name;
	displayLogo();
	resp.insertResp("greet", "Welcome, what is your name?");
	resp.insertResp("greet", "Welcome, what the cluck is your name?");
	resp.insertResp("greet", "Hello, my name is BOB, what is your name?");
	resp.insertResp("greet", "My name is BOB, What can I do for you today?");

	resp.displayResp("greet");
	cin >> name;
	resp.insertResp("name", "Hi, " + name +"! How are you today?");
	resp.insertResp("name", "Hello, " + name +"! What's up?");
	resp.insertResp("name", "Guten Tag, " + name +"! Wie geht's?");
	resp.displayResp("name");
	
	while (input != "quit"){
		cin >> input;
			if (input == "1"){
			displayOptions(resp);
		
	}
		
	}
	cout << "Goodbye!" << endl;
}

void displayOptions(Prog& resp){
	string input2, in_keyword, in_response;

	while(input2 != "3"){
	cout << "=====Options:=====" << endl;
	cout << "1. Enter in extra responses for BOB to learn" << endl;
	cout << "2. Print all Keywords and their responses" << endl;
	cout << "3. Quit and return to program" << endl;
		cin >> input2;
		if (input2 == "1"){
			cin.ignore();
			cout << "(Each keyword can have multiple responses)" << endl;
			cout << "Type in keyword:" << endl;
			getline(cin, in_keyword);
			cout << "Type in a response:" << endl;
			getline(cin, in_response);
			resp.insertResp(in_keyword, in_response);
		}
		else if (input2 == "2"){
			resp.printAllResps();
		}
	}
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
	cout << endl;
	cout <<"Coded by: Dieter Markus Hudobnik	   "<<endl;
	cout <<"Class: CSCI_2270	   "<< endl;
	cout << endl;
	cout <<"(type in '1' after greeting to access options menu)	   " << endl;
	cout << endl;
}