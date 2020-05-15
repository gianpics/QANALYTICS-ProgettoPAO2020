#ifndef STATS_INSTAGRAM_H
#define STATS_INSTAGRAM_H
#include <stats_account.h>

class Stats_instagram : public Stats_account
{
private:
    u_int following;
public:
    Stats_instagram(u_int _month, u_int _year, u_int _coverage, u_int _impression, u_int _like, u_int _followers, u_int _following = 0);
    u_int getFollowing() const;
    virtual ~Stats_instagram() = default;
};

#endif // STATS_INSTAGRAM_H
