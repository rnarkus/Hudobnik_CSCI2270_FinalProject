
#include "Class.h"
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void displayLogo();
void displayOptions(Prog&);
void addRespFromFile(Prog&, string);
void displayOptionsMenu();

int main(){
	Prog resp; 
	string input, name;
	
	displayLogo();
	resp.insertResp("greet", "Welcome, what is your name?");
	resp.insertResp("greet", "Hello, my name is BOB, what is your name?");
	resp.insertResp("greet", "My name is BOB, what is your name?");
	resp.displayResp("greet");
	getline(cin, name);

	addRespFromFile(resp, name);
	resp.displayResp("name");
	while (input != "quit"){
		if (getline(cin >> ws, input)) {
			if (input == "1"){
				displayOptions(resp);
				resp.displayResp("back");
			}
			else{
				resp.searchStr(input);
			}	
		}
	}
	cout << "Goodbye!" << endl;
}

void addRespFromFile(Prog& resp, string name){
	ifstream file;
	string sentence, keyword, response;
	file.open("bobResponses.txt");

	if (file.is_open()){
		while(getline(file, sentence)){
			istringstream iss(sentence);
			getline(iss, keyword, '#');
			getline(iss, response, '#');
			response = resp.Replace(response, "$name", name);
			resp.insertResp(keyword, response);
		}
	file.close();
	}

}

void displayOptions(Prog& resp){
	string input2, in_keyword, in_response;
	int index;
	while(input2 != "5"){
	displayOptionsMenu()
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
				getline(cin, in_keyword);
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

void displayOptionsMenu(){
	cout << "=====Options:=====" << endl;
	cout << "1. Enter in extra responses for BOB to learn" << endl;
	cout << "2. Print all Keywords and their responses" << endl;
	cout << "3. Delete a keyword" << endl;
	cout << "4. Delete a Response" << endl;
	cout << "5. Quit and return to program" << endl;
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