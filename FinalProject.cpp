
#include "Class.h"
#include <iostream>

using namespace std;

void displayWelcome();

int main(){
	Prog resp = Prog(); 
	string in_keyword, in_response, input;

	displayWelcome();
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

void displayWelcome(){
	cout << "welcome" << endl;
}