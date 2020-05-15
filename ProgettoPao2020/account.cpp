#include "account.h"

Account::Account(u_int _id, string _username, string _email, account_type _type, vector<Content> _contents, vector<Stats_account*> _stats) : id(_id), username(_username), email(_email), type(_type), contents(_contents), stats(_stats){}

u_int Account::getId() const { return id;}

string Account::getUsername() const {return username;}

string Account::getEmail() const {return email;}

vector<Content> *Account::getContents() {return &contents;}

vector<Stats_account*> *Account::getStats() {return &stats;}
