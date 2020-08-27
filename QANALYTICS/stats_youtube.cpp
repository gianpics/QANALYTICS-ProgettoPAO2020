#include "stats_youtube.h"

Stats_youtube::Stats_youtube()
{

}

Stats_youtube::Stats_youtube(QDate _date, u_int _impression,  u_int _coverage, u_int _like, u_int _followers, u_int _following, u_int _donators, u_int _totalviews, u_int _avgwatchtime) : Stats_account(_date, _impression, _coverage, _like, _followers), following(_following), donators(_donators), total_views(_totalviews), avg_watchtime(_avgwatchtime){}

u_int Stats_youtube::getFollowing() const{ return following;}

u_int Stats_youtube::getDonators() const {return donators;}

u_int Stats_youtube::getTotalViews() const {return total_views;}

u_int Stats_youtube::getAvgWatchtime() const {return avg_watchtime;}

Stats_youtube *Stats_youtube::clone() const
{
    return new Stats_youtube(*this);
}

void Stats_youtube::read(const QJsonObject &_json)
{
    Stats_account::read(_json);
    if(_json.contains("following") && _json["following"].isDouble())
        following = _json["following"].toInt();
    else
        throw runtime_error("Followers format or value not valid.");

    if(_json.contains("donators") && _json["donators"].isDouble())
        donators = _json["donators"].toInt();
    else
        throw runtime_error("Donators format or value not valid.");

    if(_json.contains("total_views") && _json["total_views"].isDouble())
        total_views = _json["total_views"].toInt();
    else
        throw runtime_error("Total_views format or value not valid.");

    if(_json.contains("avg_watchtime") && _json["avg_watchtime"].isDouble())
        avg_watchtime = _json["avg_watchtime"].toInt();
    else
        throw runtime_error("Avg_watchtime format or value not valid.");
}

void Stats_youtube::write(QJsonObject &_json) const
{
    Stats_account::write(_json);
    _json["following"] = qint64(following);
    _json["donators"] = qint64(donators);
    _json["total_views"] = qint64(total_views);
    _json["avg_watchtime"] = qint64(avg_watchtime);
}
