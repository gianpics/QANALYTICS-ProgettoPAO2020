#ifndef STATS_INSTAGRAM_H
#define STATS_INSTAGRAM_H
#include <stats_account.h>

class Stats_instagram : Stats_account
{
private:
    u_int following;
public:
    Stats_instagram(u_int, u_int, u_int, u_int, u_int, u_int, u_int=0);
    u_int getFollowing() const;
};

#endif // STATS_INSTAGRAM_H
