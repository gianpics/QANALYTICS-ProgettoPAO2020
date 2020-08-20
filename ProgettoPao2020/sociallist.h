#ifndef SOCIALLIST_H
#define SOCIALLIST_H
#include "account.h"
#include "QJsonObject"
#include "QJsonArray"


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
    const Account &operator[](u_int i) const;
    const Account& getAccountById(u_int id) const;
    virtual void read(const QJsonObject &_json);
    virtual void write(QJsonObject &_json) const;

};
#endif // SOCIALLIST_H
