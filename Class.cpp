#include "Class.h"
#include <iostream>
#include <cstring>
#include <time.h>
#include <vector>

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
	LizaKey *found = findResp(in_keyword);
	cout << found->response[index] << endl;
}

LizaKey * Prog::findResp(string in_keyword){
	int i = hashSum(in_keyword);
	LizaKey* found = NULL;
	LizaKey* front = hashResp[i];
	if (hashResp[i] != NULL){
		if(hashResp[i]->keyword == in_keyword){
			found = &(*hashResp[i]);
		}
		if(hashResp[i]->next != NULL){
			while(hashResp[i]->next != NULL){
				if((*hashResp[i]).next->keyword == in_keyword){
					found = (*hashResp[i]).next;
				}
				hashResp[i] = (*hashResp[i]).next;
			}
		}
	}
	else{
		cout << "not found" << endl;
	}
	hashResp[i]= front;
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