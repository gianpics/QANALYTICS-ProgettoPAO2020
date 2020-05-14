#include "persona.h"
#include"string"
Persona::Persona(std::string _fname, std::string _lname, std::string _ssn, std::string _address, std::string _vat):fname(_fname),lname(_lname),ssn(_ssn),address(_address), vat(_vat){}

Persona::Persona(const Persona &p):fname(p.fname),lname(p.lname), address(p.address), vat(p.vat){}

Persona::~Persona()=default;

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

Persona* Persona::operator=(const Persona &p)
{
    return new Persona(p.fname, p.lname, p.ssn, p.address, p.vat);
}

