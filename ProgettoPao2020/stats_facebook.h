#ifndef STATS_FACEBOOK_H
#define STATS_FACEBOOK_H
#include <stats_account.h>

class Stats_facebook : Stats_account
{
private:
    u_int page_likes;
public:
    Stats_facebook(u_int, u_int, u_int, u_int, u_int, u_int, u_int = 0);
    u_int getPageLikes() const;


};

#endif // STATS_FACEBOOK_H
