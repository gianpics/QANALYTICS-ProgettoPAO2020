#include "creator.h"


Creator::Creator(const std::vector<Account> _sl, std::string _fname, std::string _lname, std::string _ssn, std::string _address, std::string _vat, std::string _nickname):Social(_sl), Persona(_fname,_lname,_ssn, _address, _vat), nickname(_nickname){}

Creator::Creator(const Account _a, std::string _fname, std::string _lname, std::string _ssn, std::string _address, std::string _vat, std::string _nickname): Social(_a), Persona(_fname,_lname,_ssn, _address, _vat), nickname(_nickname){}

Creator::~Creator()=default;
bool Creator::operator==(const Creator& c)
{
    return Persona::getSSN()==c.getSSN();

}

bool Creator::operator!=(const Creator & c)
{
    return Persona::getSSN()!= c.getSSN();
}
