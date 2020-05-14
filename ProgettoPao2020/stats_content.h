#ifndef STATS_CONTENT_H
#define STATS_CONTENT_H
#include <stats.h>

class Stats_content : public Stats
{
private:
    u_int dislike;
    u_int num_comments;
    u_int views;
    u_int watchtime;
public:
    Stats_content(u_int _month, u_int _year, u_int _impression, u_int _coverage, u_int _like, u_int _dislike = 0, u_int _numcomments = 0, u_int _views = 0, u_int _watchtime = 0);
    u_int getDislike() const{ return dislike;}
    u_int getNum_comments() const{return num_comments;}
    u_int getViews() const{return views;}
    u_int getWatchtime() const{return watchtime;}
    virtual ~Stats_content() = default;
};

#endif // STATS_CONTENT_H
