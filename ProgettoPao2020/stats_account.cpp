#include "stats_account.h"

Stats_account::Stats_account(u_int _month, u_int _year, u_int _coverage, u_int _impression, u_int _like, u_int _followers) :  Stats(_month, _year, _coverage, _impression, _like), followers(_followers){}

u_int Stats_account::getFollowers() const {return followers;}

Stats_account::~Stats_account(){}

void Stats_account::setFollowers(u_int _followers)
{
    followers=_followers;
}
