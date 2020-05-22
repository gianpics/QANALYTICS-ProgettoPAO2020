#include "creator.h"

Creator::Creator(const std::vector<Account> _sl, std::string _fname, std::string _lname, std::string _ssn, std::string _address, std::string _vat, std::string _nickname): Persona(_fname,_lname,_ssn, _address, _vat), SocialList(_sl), nickname(_nickname){}

Creator::Creator(const Account _a, std::string _fname, std::string _lname, std::string _ssn, std::string _address, std::string _vat, std::string _nickname): Persona(_fname,_lname,_ssn, _address, _vat), SocialList(_a), nickname(_nickname){}

bool Creator::operator==(const Creator& c)
{
    return getSSN()==c.getSSN();

}

bool Creator::operator!=(const Creator & c)
{
    return getSSN()!= c.getSSN();
}

string Creator::getNickname() const
{
    return nickname;
}

void Creator::setNickname(string _nickname)
{
    nickname=_nickname;
}

void Creator::print(ostream &_os) const
{
    Persona::print(_os);
    SocialList::print(_os);
    _os<<getNickname()<<";";
}

ostream &operator<<(ostream &_os, const Creator &_c)
{
    _c.print(_os);
    return _os;
}
