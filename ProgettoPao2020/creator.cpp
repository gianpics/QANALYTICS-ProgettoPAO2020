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

void Creator::read(const QJsonObject &_json)
{
    Persona::read(_json);
    if(_json.contains("nickname") && _json["nickname"].isString())
        nickname = _json["nickname"].toString().toStdString();
    else
        throw runtime_error("Nickname format or value not valid.");

    SocialList::read(_json);
}

void Creator::write(QJsonObject &_json) const
{
    Persona::write(_json);
    _json["nickname"] = QString::fromStdString(nickname);
    SocialList::write(_json);
}
