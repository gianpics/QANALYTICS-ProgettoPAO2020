#ifndef STATS_ACCOUNT_H
#define STATS_ACCOUNT_H
#include <stats.h>

class Stats_account : Stats
{
private:
    u_int followers;
public:
    Stats_account(u_int, u_int, u_int, u_int, u_int, u_int);
    virtual u_int getFollowers() const;
    virtual ~Stats_account() = default;
};

#endif // STATS_ACCOUNT_H
