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

    LizaKey(std::string in_keyword, std::string in_reponse){
        response.push_back(in_reponse);
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
    LizaKey* findResp(std::string);
    void deleteKey(std::string);
    void deleteResp(std::string, int);
    void displayResp(std::string);
    int randNum(std::string);
    void printAllResps();
protected:
private:
    LizaKey **hashResp;
    int ARRAY_SIZE;
};

#endif // PROG_H
