#ifndef PERSONA_H
#define PERSONA_H
#include<string>
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
        ~Persona();
        std::string getName() const;
        std::string getLastName() const;
        std::string getFullName() const;
        std::string getSSN() const;
        std::string getAddress() const;
        std::string getVAT() const;
        Persona* operator=(const Persona&);

};


#endif // PERSONA_H

