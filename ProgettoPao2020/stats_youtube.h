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
    Stats_youtube(u_int _month = 0, u_int _year = 0, u_int _coverage = 0, u_int _impression = 0, u_int _like = 0, u_int _followers = 0, u_int _following = 0, u_int _donators = 0, u_int _totalwatchtime = 0, u_int _avgwatchtime = 0);
    virtual ~Stats_youtube() = default;
    u_int getFollowing() const;
    u_int getDonators() const;
    u_int getTotalWatchtime() const;
    u_int getAvgWatchtime() const;
    void setFollowing(u_int _following);
    void setDonators(u_int _donators);
    void setTotalWatchtime(u_int _total_watchtime);
    void setAvgWatchtime(u_int _avg_watchtime);

};

#endif // STATS_YOUTUBE_H
