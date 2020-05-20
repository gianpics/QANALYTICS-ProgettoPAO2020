#include "stats_youtube.h"

Stats_youtube::Stats_youtube(QDate _date, u_int _coverage, u_int _impression, u_int _like, u_int _followers, u_int _following, u_int _donators, u_int _totalwatchtime, u_int _avgwatchtime) : Stats_account(_date, _coverage, _impression, _like, _followers), following(_following), donators(_donators), total_watchtime(_totalwatchtime), avg_watchtime(_avgwatchtime){}

u_int Stats_youtube::getFollowing() const{ return following;}

u_int Stats_youtube::getDonators() const {return donators;}

u_int Stats_youtube::getTotalWatchtime() const {return total_watchtime;}

u_int Stats_youtube::getAvgWatchtime() const {return avg_watchtime;}

void Stats_youtube::setFollowing(u_int _following)
{
    following = _following;
}

void Stats_youtube::setDonators(u_int _donators)
{
    donators = _donators;
}

void Stats_youtube::setTotalWatchtime(u_int _total_watchtime)
{
    total_watchtime = _total_watchtime;
}

void Stats_youtube::setAvgWatchtime(u_int _avg_watchtime)
{
    avg_watchtime = _avg_watchtime;
}
