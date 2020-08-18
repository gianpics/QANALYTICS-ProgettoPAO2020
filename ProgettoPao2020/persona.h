#ifndef PERSONA_H
#define PERSONA_H
#include<string>
#include <iostream>
#include <QJsonObject>
using namespace std;
class Persona
{
    private:
        std::string fname;  //first name
        std::string lname;  //last name
        std::string ssn;    //social security number
        std::string address;//address
        std::string vat;    //VAT number (partita iva)

    public:
        Persona(std::string ="", std::string ="" , std::string ="", std::string ="", std::string ="");
        Persona(const Persona& p);
        virtual ~Persona() = 0;
        virtual std::string getName() const;
        virtual std::string getLastName() const;
        virtual std::string getFullName() const;
        virtual std::string getSSN() const;
        virtual std::string getAddress() const;
        virtual std::string getVAT() const;
        virtual void setName(std::string _fname);
        virtual void setLastName(std::string _lname);
        virtual void setSSN(std::string _ssn);
        virtual void setAddress(std::string _vat);
        virtual void setVat(std::string _address);
        virtual void read(const QJsonObject &json);
        virtual void write(QJsonObject &json) const;

};


#endif // PERSONA_H

