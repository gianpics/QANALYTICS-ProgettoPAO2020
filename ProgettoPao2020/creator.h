#ifndef CREATOR_H
#define CREATOR_H
#include "sociallist.h"
#include "persona.h"
#include "vector"
class Creator : public Persona, public SocialList
{
private:
    std::string nickname;

public:
    Creator(){}
    Creator(const std::vector<Account>, std::string, std::string, std::string, std::string, std::string, std::string ="" );
    Creator(const Account, std::string, std::string, std::string, std::string, std::string, std::string ="" );
    virtual ~Creator() = default;
    bool operator==(const Creator&);
    bool operator!=(const Creator&);
    string getNickname() const;
    void setNickname(string _nickname);
};
ostream &operator<<(ostream& _os, const Creator& _c);
#endif // CREATOR_H
