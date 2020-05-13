#include "stats_youtube.h"

Stats_youtube::Stats_youtube(u_int _month, u_int _year, u_int _coverage, u_int _impression, u_int _like, u_int _followers, u_int _following, u_int _donators, u_int _totalwatchtime, u_int _avgwatchtime) : Stats_account(_month, _year, _coverage, _impression, _like, _followers), following(_following), donators(_donators), total_watchtime(_totalwatchtime), avg_watchtime(_avgwatchtime){}

u_int Stats_youtube::getFollowing() const{ return following;}

u_int Stats_youtube::getDonators() const {return donators;}

u_int Stats_youtube::getTotalWatchtime() const {return total_watchtime;}

u_int Stats_youtube::getAvgWatchtime() const {return avg_watchtime;}
