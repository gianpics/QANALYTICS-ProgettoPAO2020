#include "stats_account.h"

Stats_account::Stats_account()
{

}

Stats_account::Stats_account(QDate _date, u_int _impression, u_int _coverage, u_int _like, u_int _followers) :  Stats(_date, _impression, _coverage, _like), followers(_followers){}

u_int Stats_account::getFollowers() const {return followers;}

Stats_account::~Stats_account(){}

void Stats_account::read(const QJsonObject &_json)
{
    Stats::read(_json);
    if(_json.contains("followers") && _json["followers"].isDouble())
        followers = _json["followers"].toInt();
    else
        throw runtime_error("Followers format or value not valid.");
}

void Stats_account::write(QJsonObject &_json) const
{
    Stats::write(_json);
    _json["followers"] = qint64(followers);
}

