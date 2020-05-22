#include "stats_youtube.h"

Stats_youtube::Stats_youtube(QDate _date, u_int _impression,  u_int _coverage, u_int _like, u_int _followers, u_int _following, u_int _donators, u_int _totalviews, u_int _avgwatchtime) : Stats_account(_date, _impression, _coverage, _like, _followers), following(_following), donators(_donators), total_views(_totalviews), avg_watchtime(_avgwatchtime){}

u_int Stats_youtube::getFollowing() const{ return following;}

u_int Stats_youtube::getDonators() const {return donators;}

u_int Stats_youtube::getTotalViews() const {return total_views;}

u_int Stats_youtube::getAvgWatchtime() const {return avg_watchtime;}

void Stats_youtube::setFollowing(u_int _following)
{
    following = _following;
}

void Stats_youtube::setDonators(u_int _donators)
{
    donators = _donators;
}

void Stats_youtube::setTotalViews(u_int _total_watchtime)
{
    total_views = _total_watchtime;
}

void Stats_youtube::setAvgWatchtime(u_int _avg_watchtime)
{
    avg_watchtime = _avg_watchtime;
}
ostream &operator<<(ostream &_os, const Stats_youtube &_sy)
{
    _sy.print(_os);
    _os<<_sy.getFollowing()<<","<<_sy.getDonators()<<","<<_sy.getTotalWatchtime()<<","<<_sy.getAvgWatchtime()<<";";
    return _os;
}
