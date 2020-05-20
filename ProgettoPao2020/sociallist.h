#ifndef SOCIALLIST_H
#define SOCIALLIST_H
#include "account.h"


class SocialList
{
private:
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
    bool isEmpty();
    u_int size();
    Account &operator[](u_int i);
    const Account& getAccountById(u_int id);

};

#endif // SOCIALLIST_H
