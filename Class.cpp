#include "Class.h"
#include <iostream>
#include <cstring>
#include <time.h>
#include <vector>
#include <sstream>

using namespace std;

Prog::Prog(){
	ARRAY_SIZE = 10;
	hashResp = new LizaKey*[ARRAY_SIZE];
	for(int i = 0; i < ARRAY_SIZE; i++){
		hashResp[i] = NULL;
	}
}
Prog::~Prog(){
	for (int i = 0; i < ARRAY_SIZE; i++)
        if (hashResp[i] != NULL) {
        LizaKey *prevEntry = NULL;
        LizaKey *entry = hashResp[i];
        while (entry != NULL) {
            prevEntry = entry;
            entry = entry->next;
            delete prevEntry;
        }
    }
    delete[] hashResp;
}

int Prog::hashSum(string x){
	int sum = 0;
    for (int i = 0; i < x.length(); i++){
        sum =sum + x[i]; //ascii value of ith character in the string
    }
    int hash = (sum % ARRAY_SIZE);
    return hash;
}

void Prog::insertResp(string in_keyword, string in_response){
	int hash = hashSum(in_keyword);
	LizaKey* entry = hashResp[hash];
	LizaKey* newNode = new LizaKey(in_keyword, in_response);
	if (hashResp[hash] == NULL){
		hashResp[hash] = newNode;
	}
	else if (entry != NULL && entry->keyword == in_keyword){
		entry->response.push_back(in_response);
	}
	else{
    	while (entry->next !=NULL){
    		entry = entry->next;
    	}
    	newNode->next = entry->next;
    	entry->next= newNode;
    }
}

int Prog::randNum(string in_keyword){
	int hash = hashSum(in_keyword);
	srand(time(NULL));
	int randomIndex = rand() % hashResp[hash]->response.size();
	return randomIndex;
}

void Prog::displayResp(string in_keyword){
	int index = randNum(in_keyword);
	LizaKey *found = findKey(in_keyword);
	cout << found->response[index] << endl;
}

LizaKey * Prog::findKey(string in_keyword){
	int i = hashSum(in_keyword);
	LizaKey* found = NULL;
	LizaKey* entry = hashResp[i];
	if (entry != NULL){
		if(entry->keyword == in_keyword){
			found = &(*entry);
		}
		if(entry->next != NULL){
			while(entry->next != NULL){
				if((*entry).next->keyword == in_keyword){
					found = (*entry).next;
				}
				entry = (*entry).next;
			}
		}
	}
	return found;
}

void Prog::deleteKey(string keyword){
	int hash = hashSum(keyword);
	bool check = true;
	LizaKey *entry = hashResp[hash];
	while(entry->next != NULL){
		check = false;
		if (entry->next->keyword == keyword){
			LizaKey *temp = entry->next;
			entry->next = entry->next->next;
			delete temp;
		}
		else{
			entry = entry->next;
		}
	}
	if (entry->next == NULL  && check == true){
		hashResp[hash] = NULL;
	}
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
	// search through each word in sentence 
	// output response based on keyword found
	istringstream iss (sentence);
	getline(iss, ranks, ' ');
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
	for (int i = 0; i < ARRAY_SIZE; i++){
		LizaKey *entry = hashResp[i];
		if (entry != NULL){
			cout <<(*entry).keyword <<endl;
			empty = false;
			if(entry->next != NULL){
				while(entry->next != NULL){
					cout << (*entry).next->keyword << endl;
					empty = false;
					entry = (*entry).next;
				}
			}
		}
	}
	if (empty == true){
		cout << "empty" << endl;
	}
}

void Prog::printAllResps(){
	bool empty = true;
	for (int i = 0; i < ARRAY_SIZE; i++){
		LizaKey *entry = hashResp[i];
		if (entry != NULL){
			cout << "~~~" <<(*entry).keyword << "~~~" << endl;
			for (int j = 0; j < (*entry).response.size(); j++){
				cout << j <<". "<<(*entry).response[j] << endl;
			}
			empty = false;
			if(entry->next != NULL){
				while(entry->next != NULL){
					cout << "~~~" <<(*entry).next->keyword << "~~~" << endl;
					for (int k = 0; i < (*entry).next->response.size(); k++){
						cout << k <<". "<<(*entry).next->response[k] << endl;
					}
					empty = false;
					entry = (*entry).next;
				}
			}
		}
	}
	if (empty == true){
		cout << "empty" << endl;
	}
}