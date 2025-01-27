#ifndef STATS_YOUTUBE_H
#define STATS_YOUTUBE_H
#include <stats_account.h>
#include <vector>

class Stats_youtube : public Stats_account
{
private:
    u_int following;
    u_int donators;
    u_int total_views;
    u_int avg_watchtime;

public:
    Stats_youtube();
    Stats_youtube(QDate _date, u_int _impression = 0,  u_int _coverage = 0, u_int _like = 0, u_int _followers = 0, u_int _following = 0, u_int _donators = 0, u_int _totalviews = 0, u_int _avgwatchtime = 0);
    virtual ~Stats_youtube() = default;
    u_int getFollowing() const;
    u_int getDonators() const;
    u_int getTotalViews() const;
    u_int getAvgWatchtime() const;
    Stats_youtube* clone() const;
    void read(const QJsonObject &_json);
    void write(QJsonObject &_json) const;
};

#endif // STATS_YOUTUBE_H
