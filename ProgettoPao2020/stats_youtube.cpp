#include "stats_youtube.h"

Stats_youtube::Stats_youtube()
{

}

Stats_youtube::Stats_youtube(QDate _date, u_int _impression,  u_int _coverage, u_int _like, u_int _followers, u_int _following, u_int _donators, u_int _totalviews, u_int _avgwatchtime) : Stats_account(_date, _impression, _coverage, _like, _followers), following(_following), donators(_donators), total_views(_totalviews), avg_watchtime(_avgwatchtime){}

u_int Stats_youtube::getFollowing() const{ return following;}

u_int Stats_youtube::getDonators() const {return donators;}

u_int Stats_youtube::getTotalViews() const {return total_views;}

u_int Stats_youtube::getAvgWatchtime() const {return avg_watchtime;}

void Stats_youtube::setFollowing(u_int _following)
{
    following = _following;
}

void Stats_youtube::setDonators(u_int _donators)
{
    donators = _donators;
}

void Stats_youtube::setTotalViews(u_int _total_watchtime)
{
    total_views = _total_watchtime;
}

void Stats_youtube::setAvgWatchtime(u_int _avg_watchtime)
{
    avg_watchtime = _avg_watchtime;
}

Stats_youtube *Stats_youtube::clone() const
{
    return new Stats_youtube(*this);
}
void Stats_youtube::print(ostream &_os) const
{
    Stats_account::print(_os);
    _os<<getFollowing()<<endl<<getDonators()<<endl<<getTotalViews()<<endl<<getAvgWatchtime()<<endl;

}

void Stats_youtube::getStream(istream &_is, vector<const Stats_account*> &v)
{
    string tmp;
    getline(_is, tmp);
    if(tmp=="[")
        while(tmp!="]"){
            string _date, _impression, _coverage, _like, _followers, _following, _donators, _totalviews, _avgtime;
            if(tmp=="[")
                getline(_is, _date);
            else
                _date=tmp;
            getline(_is, _impression);
            getline(_is, _coverage);
            getline(_is, _like);
            getline(_is, _followers);
            getline(_is, _following);
            getline(_is, _donators);
            getline(_is, _totalviews);
            getline(_is, _avgtime);
            v.push_back(new Stats_youtube(QDate::fromString(QString::fromStdString(_date)), stoi(_impression), stoi(_coverage), stoi(_like), stoi(_followers), stoi(_following), stoi(_donators), stoi(_totalviews), stoi(_avgtime)));
            getline(_is, tmp);
        }
}
void Stats_youtube::read(const QJsonObject &_json)
{
    Stats_account::read(_json);
    if(_json.contains("followers"))
        following = _json["followers"].toInt();
    if(_json.contains("donators"))
        donators = _json["donators"].toInt();
    if(_json.contains("total_views"))
        total_views = _json["total_views"].toInt();
    if(_json.contains("avg_watchtime"))
        avg_watchtime = _json["avg_watchtime"].toInt();
}

void Stats_youtube::write(QJsonObject &_json) const
{
    Stats_account::write(_json);
    _json["followers"] = qint64(following);
    _json["donators"] = qint64(donators);
    _json["total_views"] = qint64(total_views);
    _json["avg_watchtime"] = qint64(avg_watchtime);
}
ostream &operator<<(ostream &_os, const Stats_youtube &_sy)
{
    _sy.print(_os);
    return _os;
}
