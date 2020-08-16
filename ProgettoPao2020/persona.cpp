#include "persona.h"
#include"string"
Persona::Persona(std::string _fname, std::string _lname, std::string _ssn, std::string _address, std::string _vat):fname(_fname),lname(_lname),ssn(_ssn),address(_address), vat(_vat){}

Persona::Persona(const Persona &p):fname(p.fname), lname(p.lname), ssn(p.ssn), address(p.address), vat(p.vat){}

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

void Persona::print(ostream &_os) const
{
    _os<<getName()<<"\n"<<getLastName()<<"\n"<<getSSN()<<"\n"<<getAddress()<<"\n"<<getVAT()<<"\n";

}

void Persona::read(const QJsonObject & _json)
{
    if (_json.contains("first_name"))
        fname = _json["first_name"].toString().toStdString();

    if (_json.contains("last_name"))
        lname = _json["last_name"].toString().toStdString();

    if (_json.contains("SSN"))
        ssn = _json["SSN"].toString().toStdString();

    if (_json.contains("address"))
        address = _json["address"].toString().toStdString();

    if (_json.contains("VAT"))
        vat = _json["VAT"].toString().toStdString();

}

void Persona::write(QJsonObject &_json) const
{
    _json["first_name"] = QString::fromStdString(fname);
    _json["last_name"] = QString::fromStdString(lname);
    _json["SSN"] = QString::fromStdString(ssn);
    _json["address"] = QString::fromStdString(address);
    _json["VAT"] = QString::fromStdString(vat);
}

