#include "stats_instagram.h"

Stats_instagram::Stats_instagram(QDate _date, u_int _impression,  u_int _coverage, u_int _like, u_int _followers, u_int _following) : Stats_account(_date, _impression, _coverage, _like, _followers), following(_following){}

u_int Stats_instagram::getFollowing() const{return following;}

void Stats_instagram::setFollowing(u_int _following)
{
    following=_following;
}

ostream &operator<<(ostream &_os, const Stats_instagram &_si)
{
    _si.print(_os);
    _os<<_si.getFollowing()<<";";
}
