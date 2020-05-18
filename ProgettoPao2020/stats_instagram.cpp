#include "stats_instagram.h"

Stats_instagram::Stats_instagram(u_int _month, u_int _year, u_int _coverage, u_int _impression, u_int _like, u_int _followers, u_int _following) : Stats_account(_month, _year, _coverage, _impression, _like, _followers), following(_following){}

u_int Stats_instagram::getFollowing() const{return following;}

void Stats_instagram::setFollowing(u_int _following)
{
    following=_following;
}
