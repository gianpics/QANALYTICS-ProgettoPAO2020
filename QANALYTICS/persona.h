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
        std::string getName() const;
        std::string getLastName() const;
        std::string getFullName() const;
        std::string getSSN() const;
        std::string getAddress() const;
        std::string getVAT() const;
        virtual void read(const QJsonObject &json);
        virtual void write(QJsonObject &json) const;

};


#endif // PERSONA_H

