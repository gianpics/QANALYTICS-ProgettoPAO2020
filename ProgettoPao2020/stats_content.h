#ifndef STATS_CONTENT_H
#define STATS_CONTENT_H
#include <stats.h>

class Stats_content : Stats
{
private:
    u_int dislike;
    u_int num_comments;
    u_int views;
    u_int watchtime;
public:
    Stats_content(u_int = 0, u_int = 0, u_int =0 , u_int = 0, u_int =0, u_int = 0, u_int =0 , u_int = 0, u_int =0);
    u_int getDislike() const{ return dislike;}
    u_int getNum_comments() const{return num_comments;}
    u_int getViews() const{return views;}
    u_int getWatchtime() const{return watchtime;}
};

#endif // STATS_CONTENT_H
