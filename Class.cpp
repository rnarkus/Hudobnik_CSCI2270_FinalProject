#include "Class.h"
#include <iostream>
#include <cstring>
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
/*LizaKey * Prog::findResp(string in_keyword){
	int i = hashSum(in_keyword);
	LizaKey* found = NULL;
	LizaKey* front = hashResp[i];
	if (hashResp[i] != NULL){
		if(hashResp[i]->keyword == in_keyword){
			found = &(*hashResp[i]);
		}
		if(hashResp[i]->next != NULL){
			while(hashResp[i]->next != NULL){
				if((*hashResp[i]).next->title == in_title){
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
void Prog::deleteMovie(string in_title){
	int hash = hashSum(in_title);
	bool check = true;
	Movie *entry = hashResp[hash];
	while(entry->next != NULL){
		check = false;
		if (entry->next->title == in_title){
			Movie * temp = entry->next;
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
}*/
void Prog::printAllResps(){
	bool empty = true;
	for (int i = 0; i < ARRAY_SIZE; i++){
		LizaKey *head = hashResp[i];
		if (hashResp[i] != NULL){
			cout << "~~~" <<(*hashResp[i]).keyword << "~~~" << endl;
			for (int j = 0; j < (*hashResp[i]).response.size(); j++){
				cout << (*hashResp[i]).response[j] << endl;
			}
			empty = false;
			if(hashResp[i]->next != NULL){
				while(hashResp[i]->next != NULL){
					cout << "~~~" <<(*hashResp[i]).next->keyword << "~~~" << endl;
					for (int k = 0; i < (*hashResp[i]).next->response.size(); k++){
						cout << (*hashResp[i]).next->response[k] << endl;
					}
					empty = false;
					hashResp[i] = (*hashResp[i]).next;
				}
				hashResp[i] = head;
			}
		}
	}
	if (empty == true){
		cout << "empty" << endl;
	}
}