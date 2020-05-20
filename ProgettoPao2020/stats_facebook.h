#ifndef STATS_FACEBOOK_H
#define STATS_FACEBOOK_H
#include <stats_account.h>

class Stats_facebook : public Stats_account
{
private:
    u_int page_likes;
public:
    Stats_facebook(QDate _date, u_int _coverage = 0, u_int _impression = 0, u_int _like = 0, u_int _followers = 0, u_int _pagelikes = 0);
    virtual ~Stats_facebook() = default;
    u_int getPageLikes() const;
    void setPageLikes(u_int _page_likes);


};

#endif // STATS_FACEBOOK_H
