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
    Creator(const std::vector<Account>, std::string _fname, std::string _lname, std::string _ssn, std::string _address, std::string _vat, std::string _nickname = "" );
    Creator(const Account, std::string _fname, std::string _lname, std::string _ssn, std::string _address, std::string _vat, std::string _nickname = "" );
    virtual ~Creator() = default;
    bool operator==(const Creator&);
    bool operator!=(const Creator&);
    string getNickname() const;
    void setNickname(string _nickname);
    void print(ostream &_os) const override;
};
ostream &operator<<(ostream& _os, const Creator& _c);
#endif // CREATOR_H
