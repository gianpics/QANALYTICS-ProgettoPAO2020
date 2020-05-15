#ifndef STATS_ACCOUNT_H
#define STATS_ACCOUNT_H
#include <stats.h>

class Stats_account : public Stats
{
private:
    u_int followers;
public:
    Stats_account(u_int _month, u_int _year, u_int _coverage, u_int _impression, u_int _like, u_int _followers);
    virtual u_int getFollowers() const;
    virtual ~Stats_account()  = 0 ;
};

#endif // STATS_ACCOUNT_H
