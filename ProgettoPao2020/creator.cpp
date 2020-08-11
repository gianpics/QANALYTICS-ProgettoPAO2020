#include "creator.h"

Creator::Creator(const std::vector<Account> _sl, std::string _fname, std::string _lname, std::string _ssn, std::string _address, std::string _vat, std::string _nickname): Persona(_fname,_lname,_ssn, _address, _vat), SocialList(_sl), nickname(_nickname){}

Creator::Creator(const Account _a, std::string _fname, std::string _lname, std::string _ssn, std::string _address, std::string _vat, std::string _nickname): Persona(_fname,_lname,_ssn, _address, _vat), SocialList(_a), nickname(_nickname){}

bool Creator::operator==(const Creator& c)
{
    cout << getSSN();
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
    /*Persona::print(_os);
    SocialList::print(_os);
    _os<<getNickname()<<"\n";*/
}

ostream &operator<<(ostream &_os, const Creator &_c)
{
    //_c.print(_os);
    return _os;
}

istream &operator>>(istream &_is, Creator &_c)
{
    /*string _fname, _lname, _ssn, _address, _vat, _nick;
    _is.ignore();
    getline(_is, _fname);

    getline(_is, _lname);
    getline(_is, _ssn);
    getline(_is, _address);
    getline(_is, _vat);
    vector<Account> v;
    _is >> v;
    getline(_is, _nick);
    _c.setName(_fname);
    _c.setLastName(_lname);
    _c.setAddress(_address);
    _c.setSSN(_ssn);
    _c.setVat(_vat);
    _c.setSocialList(v);
    _c.setNickname(_nick);*/
    return _is;
}
