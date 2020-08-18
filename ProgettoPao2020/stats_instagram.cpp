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

void Stats_instagram::print(ostream &_os) const
{
    Stats_account::print(_os);
    _os<<getFollowing()<<endl;

}

void Stats_instagram::getStream(istream &_is, vector<const Stats_account *> &v)
{
    string tmp;
    getline(_is, tmp);
    if(tmp=="[")
        while(tmp!="]"){
            string _date, _impression, _coverage, _like, _followers, _following;
            if(tmp=="[")
                getline(_is, _date);
            else
                _date=tmp;
            getline(_is, _impression);
            getline(_is, _coverage);
            getline(_is, _like);
            getline(_is, _followers);
            getline(_is, _following);
            v.push_back(new Stats_instagram(QDate::fromString(QString::fromStdString(_date)), stoi(_impression), stoi(_coverage), stoi(_like), stoi(_followers), stoi(_following)));
            getline(_is, tmp);
        }
}
void Stats_instagram::read(const QJsonObject &_json)
{
    Stats_account::read(_json);
    if(_json.contains("followers"))
        following = _json.value("followers").toInt();
}

void Stats_instagram::write(QJsonObject &_json) const
{
    Stats_account::write(_json);
    _json["followers"] = qint64(following);
}
