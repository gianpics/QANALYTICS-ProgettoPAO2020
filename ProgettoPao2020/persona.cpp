#include "persona.h"
#include"string"
Persona::Persona(std::string _fname, std::string _lname, std::string _ssn, std::string _address, std::string _vat):fname(_fname),lname(_lname),ssn(_ssn),address(_address), vat(_vat){}

Persona::Persona(const Persona &p):fname(p.fname),lname(p.lname), address(p.address), vat(p.vat){}

Persona::~Persona(){}

std::string Persona::getName()const
{
    return fname;
}

std::string Persona::getLastName() const
{
    return lname;
}

std::string Persona::getFullName() const
{
    return fname +" "+lname;
}

std::string Persona::getSSN() const
{
    return ssn;
}

std::string Persona::getAddress() const
{
    return address;
}

std::string Persona::getVAT() const
{
    return vat;
}

void Persona::setName(std::string _fname)
{
    fname=_fname;
}

void Persona::setLastName(std::string _lname)
{
    lname=_lname;
}

void Persona::setSSN(std::string _ssn)
{
    ssn=_ssn;
}

void Persona::setAddress(std::string _address)
{
    address=_address;
}

void Persona::setVat(std::string _vat)
{
    vat=_vat;
}

ostream &operator<<(ostream &_os, const Persona &_p)
{
    _os<<_p.getName()<<","<<_p.getLastName()<<","<<_p.getSSN()<<","<<_p.getAddress()<<","<<_p.getVAT();
    return _os;
}
