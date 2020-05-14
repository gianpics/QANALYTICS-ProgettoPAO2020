#ifndef CREATOR_H
#define CREATOR_H
#include "social.h"
#include "persona.h"
#include "vector"
class Creator : public Social, public Persona
{
private:
    std::string nickname;

public:
    Creator():Social(),Persona(){}
    Creator(const std::vector<Account>, std::string, std::string, std::string, std::string, std::string, std::string ="" );
    Creator(const Account, std::string, std::string, std::string, std::string, std::string, std::string ="" );
    ~Creator();
    bool operator==(const Creator&);
    bool operator!=(const Creator&);
};

#endif // CREATOR_H
