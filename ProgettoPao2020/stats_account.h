#ifndef STATS_ACCOUNT_H
#define STATS_ACCOUNT_H
#include <stats.h>

class Stats_account : public Stats
{
private:
    u_int followers;
public:
    Stats_account();
    Stats_account(QDate _date, u_int _impression, u_int _coverage, u_int _like, u_int _followers);
    virtual u_int getFollowers() const;
    virtual ~Stats_account() = 0;
    virtual void setFollowers(u_int _followers);
    virtual void print(ostream& _os) const;
    virtual Stats_account* clone() const = 0;
    virtual void read(const QJsonObject &_json);
    virtual void write(QJsonObject &_json) const;
};
ostream& operator<<(ostream& _os, const Stats_account &_sa);

#endif // STATS_ACCOUNT_H
