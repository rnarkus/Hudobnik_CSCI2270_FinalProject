#include "Class.h"
#include <iostream>
#include <cstring>
#include <time.h>
#include <vector>
#include <sstream>

using namespace std;

Prog::Prog(){
}
/*
deletes function from memory
*/
Prog::~Prog(){
	for (int i = 0; i < tableSize; i++){
		if (hashTable[i] != NULL){
			delete hashTable[i];
		}
	}
}
/*
Function prototype:
int Prog::hashSum(string x)
Function description:
This method calculates the hashcode which is based on the predetermined tablesize in Class.h
Example:
Prog ht;
ht.hashSum("hello");
Precondition: Takes the ascii values of the string x and adds them up. Then using the modulo operator,
finds the hash index with the predetermined tablesize
Post condition: returns the hash index to be used elsewhere
*/
int Prog::hashSum(string x){
	int sum = 0;
    for (int i = 0; i < x.length(); i++){
        sum =sum + x[i]; //ascii value of ith character in the string
    }
    int hash = (sum % tableSize);
    return hash;
}
/*
Function prototype:
void Prog::insertResp(string in_keyword, string in_response)
Function description:
Inserts a keyword and response into the hashtable
Example:
Prog ht;
ht.insertResp("hello", "how are you?")
Precondition: Unused Indexes and linked lists are stored as NULL. Hash code is calculated from the hashSum function and then
inserted. The input names are the keywords and the responses
Post condition: successfully inserts a keyword with matching response. If there is more than one keyword with the same value
it is added to a linked list. If the keyword has multiple occurances, only the response is added to the specific keyword
*/
void Prog::insertResp(string in_keyword, string in_response){
	int index = hashSum(in_keyword);
	if (hashTable[index] == NULL){
		hashTable[index] = new vector<LizaKey>;
		hashTable[index]->push_back(LizaKey(in_keyword,in_response));
	}
	else{
		for (int i = 0; i < hashTable[index]->size(); i++){
			if ((*hashTable[index])[i].keyword == in_keyword){
				((*hashTable[index])[i].response.push_back(in_response));
				return;
			}
		}
		hashTable[index]->push_back(LizaKey(in_keyword, in_response));
	}
	return;
}
/*
Function prototype:
void Prog::displayResp(string in_keyword){
Function description:
This method finds a randomly generated index of a keyword
Example:
Prog ht;
ht.displayResp("hello")
Precondition: srand is calculated using the time to which it loads up numbers to be used. For example,
it would load up 67 and use that for rand(). findKey is used to search the hashtable for the keyword that was entered
Post condition: calculates a random index and prints out the response at that index
*/
void Prog::displayResp(string in_keyword){
	int hash = hashSum(in_keyword);
	srand(time(NULL));
	LizaKey *found = findKey(in_keyword);
	int randomIndex = rand() % found->response.size();
	cout << found->response[randomIndex] << endl;
}
/*
Function prototype:
LizaKey * Prog::findKey(string in_keyword)
Function description:
finds the keyword that was entered
Example:
Prog ht;
ht.findKey("hello")
Precondition: in_keyword is the keywored entered by the user. All unused indexs are set to NULL
Post condition: Finds and stores the keyword in the hashtable and returns this value.
*/
LizaKey * Prog::findKey(string in_keyword){
	int index = hashSum(in_keyword);
	bool found = false;
	LizaKey *foundResp = NULL;

	if (hashTable[index] != NULL){
		for (int i = 0; i < hashTable[index]->size(); i++){
			if ((*hashTable[index])[i].keyword == in_keyword){
				foundResp = &(*hashTable[index])[i];
				found = true;
				break;
			}
		}
	}
	if (found == false){
		cout << "not found" << endl;
	}
	return foundResp;
}
/*
Function prototype:
void Prog::deleteKey(string in_keyword)
Function description:
This method calculates the hashcode for the input keyword name, and deletes the keyword from the hash table.
Handles cases where movie is first, mid, or last node in the chain.
Example:
HashTable ht;
ht.deleteKey("hello")
Precondition: Unused locations in hashTable vector are NULL. Keywords stored using correctly calculated hash
code calculated from the input Keyword. The input string name is the keyword
Post condition: Keyword node deleted from chain and memory freed. Pointers updated to bypass deleted keyword.
*/
void Prog::deleteKey(string in_keyword){
	int index = hashSum(in_keyword);
	bool found = false;
	if (hashTable[index] != NULL){
		for (int i = 0; i < hashTable[index]->size(); i++){
			if ((*hashTable[index])[i].keyword == in_keyword){
				hashTable[index]->erase(hashTable[index]->begin() + i);
				found = true;
				break;
			}
		}
		if (hashTable[index]->size() == 0){
			delete hashTable[index];
			hashTable[index] = NULL;
		}
	}
	if (found == false){
		cout << "not found" << endl;
	}
	return;
}
/*
Function prototype:
void Prog::deleteResp(string in_keyword, int index)
Function description:
This method deletes the response at a certain index
Example:
Prog ht;
ht.deleteResp("hello", 0)
Precondition: Finds the keyword. If the keyword is not found, it should be produced as NULL. If the index is out of range of the
size of the responses, then the code stops
Post condition: successfully deletes the index from memory.
*/
void Prog::deleteResp(string in_keyword, int index){
	LizaKey *found = findKey(in_keyword);

	if (found == NULL){
		cout << "Keyword not found" << endl;
	}
	else if (index > found->response.size() || index < 0){
		cout << "Index not found" << endl;
	}
	else{
		found->response.erase(found->response.begin()+index);   //Used to be index-1
		cout << "Deleted response at index " << index << endl;
	}
}
/*
Function prototype:
void Prog::searchStr(string sentence)
Function description:
Simliar to findKey, this function searches the hashtable for a matching keyowrd with the inputted sentence.
Example:
Prog ht;
ht.searchStr("Hi, how are you today?")
Precondition: string sentence is the input the user enters.
Post condition: Keyword found that matches a word in the sentence, outputs the random response using displayResp()
*/
void Prog::searchStr(string sentence){
	LizaKey *foundResp = NULL;
	for (int i = 0; i < tableSize; i++){
		if (hashTable[i] != NULL){
			for (int j = 0; j < hashTable[i]->size(); j++){
				if (sentence.find((*hashTable[i])[j].keyword) != std::string::npos){
					foundResp = &(*hashTable[i])[j];
					break;
				}
			}
		}
	}
	if (foundResp != NULL){
		displayResp(foundResp->keyword);
	}
	else{
		displayResp("unknown");
	}
}
/*
Function prototype:
string Prog::Replace(string str, string oldStr, string newStr)
Function description:
This method replaces a word with another word in a string
Example:
Prog ht;
ht.Replace("hello hello goodbye world", "goodbye", "hello")
Precondition: str, oldStr, and newStr are all used from the read in file and are all valid ascii strings. Creates a new string
instead of replacing the old one
Post condition: returns the new string
*/
string Prog::Replace(string str, string oldStr, string newStr){
	size_t pos = 0;
	while((pos = str.find(oldStr, pos)) != std::string::npos){
		str.replace(pos, oldStr.length(), newStr);
		pos += newStr.length();
	}
	return str;
}
/*
Function prototype:
void Prog::printResp(string in_keyword)
Function description:
This method prints just the responses at a certain keyword
Example:
Prog ht;
ht.printResp("hello")
Precondition: intput is a keyword
Post condition: prints all the responses by using a for loop for the size of the vector
*/
void Prog::printResp(string in_keyword){
	LizaKey *found = findKey(in_keyword);
	if (found == NULL){
		cout << "Keyword not found" << endl;
	}
	else{
		for (int j = 0; j < (*found).response.size(); j++){
			cout << j <<". "<<(*found).response[j] << endl;
		}
	}
}
/*
Function prototype:
void Prog::printKey()
Function description:
This method print out all the keys in the hashtable
Example:
Prog ht;
ht.printKey()
Precondition: No input, takes the hashtable and skips the NULL
Post condition: prints out the entire keyowrd list.
*/
void Prog::printKey(){
	cout << "Keywords:" << endl;
	bool empty = true;
	for (int i = 0; i < tableSize; i++){
		if (hashTable[i] != NULL){
			for (int j = 0; j < hashTable[i]->size(); j++){
				cout << (*hashTable[i])[j].keyword << endl;
				empty = false;
			}
		}
	}
	if (empty == true)
		cout << "empty" << endl;
	return;
}
/*
Function prototype:
void Prog::printAllResps()
Function description:
This method is a combination of printKey and printResp
Example:
Prog ht;
ht.printAllResps()
Precondition: Uses the hashtable and traverses through it.
Post condition: Prints the keyword and assciated responses
*/
void Prog::printAllResps(){
	bool empty = true;
	for (int i = 0; i < tableSize; i++){
		if (hashTable[i] != NULL){
			for (int j = 0; j < hashTable[i]->size(); j++){
				cout << "~~~" <<(*hashTable[i])[j].keyword << "~~~" << endl;
				for (int k = 0; k < (*hashTable[i])[j].response.size(); k++){
					cout << k <<". "<<(*hashTable[i])[j].response[k] << endl;
				}
				empty = false;
			}
		}
	}
	if (empty == true)
		cout << "empty" << endl;
	return;
}
