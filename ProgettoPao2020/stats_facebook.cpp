#include "stats_facebook.h"

Stats_facebook::Stats_facebook()
{

}

Stats_facebook::Stats_facebook(QDate _date, u_int _impression, u_int _coverage, u_int _like, u_int _followers, u_int _pagelikes) : Stats_account(_date, _impression, _coverage, _like, _followers), page_likes(_pagelikes){}

u_int Stats_facebook::getPageLikes() const {return page_likes;}

void Stats_facebook::setPageLikes(u_int _page_likes)
{
    page_likes = _page_likes;
}

Stats_facebook *Stats_facebook::clone() const
{
    return new Stats_facebook(*this);
}

void Stats_facebook::print(ostream &_os) const
{
    Stats_account::print(_os);
    _os<<getPageLikes()<<endl;
}

void Stats_facebook::getStream(istream &_is, vector<const Stats_account *> &v)
{
    string tmp;
    getline(_is, tmp);
    if(tmp=="[")
        while(tmp!="]"){
            string _date, _impression, _coverage, _like, _followers, _pagelikes;
            if(tmp=="[")
                getline(_is, _date);
            else
                _date=tmp;
            getline(_is, _impression);
            getline(_is, _coverage);
            getline(_is, _like);
            getline(_is, _followers);
            getline(_is, _pagelikes);
            v.push_back(new Stats_facebook(QDate::fromString(QString::fromStdString(_date)), stoi(_impression), stoi(_coverage), stoi(_like), stoi(_followers), stoi(_pagelikes)));
            getline(_is, tmp);
        }
}

void Stats_facebook::read(const QJsonObject &_json)
{
    Stats_account::read(_json);
    if(_json.contains("page_likes"))
        page_likes = _json.value("page_likes").toInt();
}

void Stats_facebook::write(QJsonObject &_json) const
{
    Stats_account::write(_json);
    _json["page_likes"] = qint64(page_likes);
}
