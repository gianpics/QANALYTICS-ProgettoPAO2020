#ifndef STATS_FACEBOOK_H
#define STATS_FACEBOOK_H
#include <stats_account.h>

class Stats_facebook : public Stats_account
{
private:
    u_int page_likes;
public:
    Stats_facebook(u_int _month, u_int _year, u_int _coverage, u_int _impression, u_int _like, u_int _followers, u_int _pagelikes = 0);
    u_int getPageLikes() const;
    virtual ~Stats_facebook() = default;

};

#endif // STATS_FACEBOOK_H
