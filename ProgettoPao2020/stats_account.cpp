#include "stats_account.h"

Stats_account::Stats_account(QDate _date, u_int _impression, u_int _coverage, u_int _like, u_int _followers) :  Stats(_date, _impression, _coverage, _like), followers(_followers){}

u_int Stats_account::getFollowers() const {return followers;}

Stats_account::~Stats_account(){}

void Stats_account::setFollowers(u_int _followers)
{
    followers=_followers;
}


void Stats_account::print(ostream &_os) const
{
    Stats::print(_os);
    _os<<followers<<endl;
}

ostream &operator<<(ostream &_os, const Stats_account &_sa)
{
    _sa.print(_os);
    return _os;
}
