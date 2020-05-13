#include "account.h"

Account::Account(u_int _id, string _username, string _email, string _link, vector<Content> _contents, vector<Stats_account> _stats) : id(_id), username(_username), email(_email), link(_link), contents(_contents), stats(_stats){}

u_int Account::getId() const { return id;}

string Account::getUsername() const {return username;}

string Account::getEmail() const {return email;}

string Account::getLink() const {return link;}

vector<Content> *Account::getContents() {return &contents;}

vector<Stats_account> *Account::getStats() {return &stats;}
