#ifndef STATS_CONTENT_H
#define STATS_CONTENT_H
#include <stats.h>
#include <vector>

class Stats_content : public Stats
{
private:
    u_int dislike;
    u_int num_comments;
    u_int views;
    u_int watchtime;
public:
    Stats_content();
    Stats_content(QDate _date, u_int _impression = 0, u_int _coverage = 0, u_int _like = 0, u_int _dislike = 0, u_int _numcomments = 0, u_int _views = 0, u_int _watchtime = 0);
    virtual ~Stats_content() = default;
    u_int getDislike() const{ return dislike;}
    u_int getNum_comments() const{return num_comments;}
    u_int getViews() const{return views;}
    u_int getWatchtime() const{return watchtime;}
    void setDislike(u_int _dislike);
    void setNum_comments(u_int _numcomments);
    void setViews(u_int _views);
    void setWatchtime(u_int _watchtime);
    Stats_content* clone() const;
    virtual void read(const QJsonObject &_json);
    virtual void write(QJsonObject &_json) const;

};
ostream &operator<<(ostream &_os, const Stats_content &_sa);
istream &operator>>(istream &_is, vector<const Stats_content *> &_v);

#endif // STATS_CONTENT_H
