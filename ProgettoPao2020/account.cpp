#include "account.h"


Account::Account(u_int _id, string _username, string _email, account_type _type, const vector<Content>& _contents, const vector<const Stats_account*>& _stats) : id(_id), username(_username), email(_email), type(_type), contents(_contents), stats(_stats){}

Account::Account(const Account& _account)
{
    id=_account.id;
    username=_account.username;
    email=_account.email;
    type=_account.type;
    contents=_account.contents;
    //stats=_account.stats;
    /*for(auto a : _account.contents){
        contents.push_back(new Content(*a));
    }*/
    for(auto a : _account.stats){
        if (auto *b = dynamic_cast<const Stats_youtube*>(a)) {
            stats.push_back(new Stats_youtube(*b));
        }else if(auto *b = dynamic_cast<const Stats_facebook*>(a)){
            stats.push_back(new Stats_facebook(*b));
        }else if(auto *b = dynamic_cast<const Stats_instagram*>(a)){
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
        contents=_account.contents;
        //stats=_account.stats;
        /*for(auto a : _account.contents){
            contents.push_back(new Content(*a));
        }*/
        for(auto a : _account.stats){
            if (auto *b = dynamic_cast<const Stats_youtube*>(a)) {
                stats.push_back(new Stats_youtube(*b));
            }else if(auto *b = dynamic_cast<const Stats_facebook*>(a)){
                stats.push_back(new Stats_facebook(*b));
            }else if(auto *b = dynamic_cast<const Stats_instagram*>(a)){
                stats.push_back(new Stats_instagram(*b));
            }
        }
    }
    return *this;
}

u_int Account::getId() const { return id;}

void Account::setId(u_int _id)
{
    id=_id;
}

//void Account::setId(u_int _id){id=_id;}

string Account::getUsername() const {return username;}

void Account::setUsername(string _username)
{
    username=_username;
}

string Account::getEmail() const {return email;}

void Account::setEmail(string _email)
{
    email=_email;
}

account_type Account::getType() const
{
    return type;
}

void Account::setType(account_type _type)
{
    type=_type;
}

const vector<Content>& Account::getContents() const {return contents;}

void Account::setContents(vector<Content> &_contents)
{
    contents=_contents;
}

const vector<const Stats_account*>& Account::getStats() const {return stats;}

void Account::setStats(vector<const Stats_account*> &_stats)
{
    for(auto a : _stats){
        if (auto *b = dynamic_cast<const Stats_youtube* const>(a)) {
            stats.push_back(new Stats_youtube(*b));
        }else if(auto *b = dynamic_cast<const Stats_facebook* const>(a)){
            stats.push_back(new Stats_facebook(*b));
        }else if(auto *b = dynamic_cast<const Stats_instagram* const>(a)){
            stats.push_back(new Stats_instagram(*b));
        }
    }
}

string Account::getStringType() const
{
    switch (type) {
        case instagram: return "Instagram";
        case facebook: return "Facebook";
        case youtube: return "Youtube";
    }
}

ostream &operator<<(ostream &_os, const Account &_a)
{
    _os<<_a.getId()<<","<<_a.getUsername()<<","<<_a.getEmail()<<","<<_a.getType()<<",";
    _os<<&_a.getContents();
    _os<<&_a.getStats();
    return _os;
}
