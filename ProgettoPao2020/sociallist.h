#ifndef SOCIALLIST_H
#define SOCIALLIST_H
#include "account.h"


class SocialList
{
protected:
    std::vector<Account> list;

public:
    SocialList(){}
    virtual ~SocialList()  = 0;
    SocialList(const SocialList& _socialist);
    SocialList(const std::vector<Account>& _list);
    SocialList(const Account& _account);
    virtual void addAccount(const Account& _account);
    virtual void removeAt(u_int _i);
    virtual void removeById(u_int _id);
    bool isEmpty() const;
    u_int size() const ;
    Account &operator[](u_int i);
    const Account& getAccountById(u_int id);
    virtual void setSocialList(const vector<Account> &v){
        for(auto a : v){
            list.push_back(a);
        }
    }
    virtual void print(ostream &_os) const;

};
#endif // SOCIALLIST_H
