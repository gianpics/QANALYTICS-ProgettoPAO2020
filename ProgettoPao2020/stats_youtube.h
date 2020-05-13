#ifndef STATS_YOUTUBE_H
#define STATS_YOUTUBE_H
#include <stats_account.h>

class Stats_youtube : Stats_account
{
private:
    u_int following;
    u_int donators;
    u_int total_watchtime;
    u_int avg_watchtime;

public:
    Stats_youtube(u_int, u_int, u_int, u_int, u_int, u_int, u_int = 0, u_int = 0, u_int = 0, u_int = 0);
    u_int getFollowing() const;
    u_int getDonators() const;
    u_int getTotalWatchtime() const;
    u_int getAvgWatchtime() const;
};

#endif // STATS_YOUTUBE_H
