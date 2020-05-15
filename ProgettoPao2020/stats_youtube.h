#ifndef STATS_YOUTUBE_H
#define STATS_YOUTUBE_H
#include <stats_account.h>

class Stats_youtube : public Stats_account
{
private:
    u_int following;
    u_int donators;
    u_int total_watchtime;
    u_int avg_watchtime;

public:
    Stats_youtube(u_int _month, u_int _year, u_int _coverage, u_int _impression, u_int _like, u_int _followers, u_int _following = 0, u_int _donators = 0, u_int _totalwatchtime = 0, u_int _avgwatchtime = 0);
    u_int getFollowing() const;
    u_int getDonators() const;
    u_int getTotalWatchtime() const;
    u_int getAvgWatchtime() const;
    virtual ~Stats_youtube() = default;
};

#endif // STATS_YOUTUBE_H
