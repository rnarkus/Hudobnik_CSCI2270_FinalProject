#ifndef PROG_H
#define PROG_H
#include <iostream>
#include <vector>

struct LizaKey
{
    std::vector<std::string> response;
    std::string keyword;
    LizaKey *next;

    LizaKey(){};

    LizaKey(std::string in_keyword, std::string in_response){
        response.push_back(in_response);
        keyword = in_keyword;
    }
};


class Prog{
public:
    Prog();
    ~Prog();
    int hashSum(std::string);
    void insertResp(std::string, std::string);
    void insertName(std::string);
    LizaKey* findKey(std::string);
    void deleteKey(std::string);
    void deleteResp(std::string, int);
    void displayResp(std::string);
    void searchStr(std::string);
    std::string Replace(std::string a, std::string b, std::string c);
    void printResp(std::string);
    void printKey();
    void printAllResps();
protected:
private:
    std::vector<LizaKey> *hashTable[10] = {NULL};
    int tableSize = 10;
};

#endif // PROG_H
