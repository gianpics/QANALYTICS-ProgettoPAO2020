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

void Persona::read(const QJsonObject & _json)
{
    if (_json.contains("first_name") && _json["first_name"].isString())
        fname = _json["first_name"].toString().toStdString();
    else
        throw runtime_error("First_name format or value not valid.");

    if (_json.contains("last_name") && _json["last_name"].isString())
        lname = _json["last_name"].toString().toStdString();
    else
        throw runtime_error("Last_name format or value not valid.");

    if (_json.contains("SSN") && _json["SSN"].isString())
        ssn = _json["SSN"].toString().toStdString();
    else
        throw runtime_error("SSN format or value not valid.");

    if (_json.contains("address") && _json["address"].isString())
        address = _json["address"].toString().toStdString();
    else
        throw runtime_error("Address format or value not valid.");

    if (_json.contains("VAT") && _json["VAT"].isString())
        vat = _json["VAT"].toString().toStdString();
    else
        throw runtime_error("VAT format or value not valid.");

}

void Persona::write(QJsonObject &_json) const
{
    _json["first_name"] = QString::fromStdString(fname);
    _json["last_name"] = QString::fromStdString(lname);
    _json["SSN"] = QString::fromStdString(ssn);
    _json["address"] = QString::fromStdString(address);
    _json["VAT"] = QString::fromStdString(vat);
}

