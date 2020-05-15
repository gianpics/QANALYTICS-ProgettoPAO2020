#include "account.h"

Account::Account(u_int _id, string _username, string _email, account_type _type, const vector<Content*>& _contents, const vector<Stats_account*>& _stats) : id(_id), username(_username), email(_email), type(_type), contents(_contents), stats(_stats){}

Account::Account(const Account& _account)
{
    id=_account.id;
    username=_account.username;
    email=_account.email;
    type=_account.type;
    for(auto a : _account.contents){
        contents.push_back(new Content(*a));
    }
    for(auto a : _account.stats){
        if (auto *b = dynamic_cast<Stats_youtube*>(a)) {
            stats.push_back(new Stats_youtube(*b));
        }else if(auto *b = dynamic_cast<Stats_facebook*>(a)){
            stats.push_back(new Stats_facebook(*b));
        }else if(auto *b = dynamic_cast<Stats_instagram*>(a)){
            stats.push_back(new Stats_instagram(*b));
        }
    }
}

Account& Account::operator=(const Account& _account)
{
    if(this != &_account){
        id=_account.id;
        username=_account.username;
        email=_account.email;
        type=_account.type;
        for(auto a : _account.contents){
            contents.push_back(new Content(*a));
        }
        for(auto a : _account.stats){
            if (auto *b = dynamic_cast<Stats_youtube*>(a)) {
                stats.push_back(new Stats_youtube(*b));
            }else if(auto *b = dynamic_cast<Stats_facebook*>(a)){
                stats.push_back(new Stats_facebook(*b));
            }else if(auto *b = dynamic_cast<Stats_instagram*>(a)){
                stats.push_back(new Stats_instagram(*b));
            }
        }
    }
    return *this;
}

u_int Account::getId() const { return id;}

//void Account::setId(u_int _id){id=_id;}

string Account::getUsername() const {return username;}

string Account::getEmail() const {return email;}

vector<Content*> *Account::getContents() {return &contents;}

vector<Stats_account*> *Account::getStats() {return &stats;}
