#include "Class.h"
#include <iostream>
#include <cstring>
#include <time.h>
#include <vector>
#include <sstream>

using namespace std;

Prog::Prog(){
}

Prog::~Prog(){
	for (int i = 0; i < tableSize; i++){
		if (hashTable[i] != NULL){
			delete hashTable[i];
		}
	}
}

int Prog::hashSum(string x){
	int sum = 0;
    for (int i = 0; i < x.length(); i++){
        sum =sum + x[i]; //ascii value of ith character in the string
    }
    int hash = (sum % tableSize);
    return hash;
}

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

void Prog::displayResp(string in_keyword){
	int hash = hashSum(in_keyword);
	srand(time(NULL));
	LizaKey *found = findKey(in_keyword);
	int randomIndex = rand() % found->response.size();
	cout << found->response[randomIndex] << endl;
}

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

void Prog::deleteResp(string in_keyword, int index){
	LizaKey *found = findKey(in_keyword);
	if (found == NULL){
		cout << "Keyword not found" << endl;
	}
	else if (index > found->response.size() || index < 0){
		cout << "Index not found" << endl;
	}
	else{
		found->response.erase(found->response.begin()+index-1);
		cout << "Deleted response at index " << index << endl;
	}
}

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

string Prog::Replace(string str, string oldStr, string newStr){
	size_t pos = 0;
	while((pos = str.find(oldStr, pos)) != std::string::npos){
		str.replace(pos, oldStr.length(), newStr);
		pos += newStr.length();
	}
	return str;
}

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