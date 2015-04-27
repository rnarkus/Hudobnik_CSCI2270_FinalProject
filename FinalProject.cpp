
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
	resp.insertResp("greet", "My name is BOB, what is your name?");

	resp.displayResp("greet");
	cin >> name;
	resp.insertResp("name", "Hi, " + name +"! How are you today?");
	resp.insertResp("name", "Hello, " + name +"! What's up?");
	resp.insertResp("name", "Guten Tag, " + name +"! Wie geht's?");
	resp.displayResp("name");
	
	while (input != "quit"){
		cin.ignore();
		getline(cin, input);
		if (input == "1"){
			displayOptions(resp);
		}
		else{
			resp.searchStr(input);
		}
	}
	cout << "Goodbye!" << endl;
}

void displayOptions(Prog& resp){
	string input2, in_keyword, in_response;
	int index;
	while(input2 != "5"){
	cout << "=====Options:=====" << endl;
	cout << "1. Enter in extra responses for BOB to learn" << endl;
	cout << "2. Print all Keywords and their responses" << endl;
	cout << "3. Delete a keyword" << endl;
	cout << "4. Delete a Response" << endl;
	cout << "5. Quit and return to program" << endl;
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
		else if (input2 == "3"){
			cin.ignore();
			cout << "Type in keyword to delete:" << endl;
			getline(cin, in_keyword);
			resp.deleteKey(in_keyword);
		}
		else if (input2 == "4"){
			cin.ignore();
			resp.printKey();
			cout << "Type in keyword to find the response you want to delete:" << endl;
			cin >> in_keyword;
			LizaKey *found = resp.findKey(in_keyword);
			while (found == NULL){
				cout << "Try a different keyword" << endl;
				cin >> in_keyword;
				found = resp.findKey(in_keyword);
			}
			if (found != NULL){
				resp.printResp(in_keyword);
				cout << "Type in the number of the response you would like to delete" << endl;
				cin >> index;
				resp.deleteResp(in_keyword, index);
			}
		}
			
	}
}

void displayLogo(){
	int DELAY = 100000;
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