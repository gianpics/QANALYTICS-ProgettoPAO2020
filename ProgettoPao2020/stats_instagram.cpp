#include "stats_instagram.h"

Stats_instagram::Stats_instagram(){

}

Stats_instagram::Stats_instagram(QDate _date, u_int _impression,  u_int _coverage, u_int _like, u_int _followers, u_int _following) : Stats_account(_date, _impression, _coverage, _like, _followers), following(_following){}

u_int Stats_instagram::getFollowing() const{return following;}

void Stats_instagram::setFollowing(u_int _following)
{
    following=_following;
}

Stats_instagram *Stats_instagram::clone() const
{
    return new Stats_instagram(*this);
}

void Stats_instagram::read(const QJsonObject &_json)
{
    Stats_account::read(_json);
    if(_json.contains("followers") && _json.value("followers").isDouble())
        following = _json.value("followers").toInt();
    else
        throw runtime_error("Followers format or value is not valid.");
}

void Stats_instagram::write(QJsonObject &_json) const
{
    Stats_account::write(_json);
    _json["followers"] = qint64(following);
}
