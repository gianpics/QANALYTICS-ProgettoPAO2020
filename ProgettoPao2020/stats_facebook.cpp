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

void Stats_facebook::read(const QJsonObject &_json)
{
    Stats_account::read(_json);
    if(_json.contains("page_likes") && _json.value("page_likes").isDouble())
        page_likes = _json.value("page_likes").toInt();
    else
        throw runtime_error("Page_likes format or value not valid.");
}

void Stats_facebook::write(QJsonObject &_json) const
{
    Stats_account::write(_json);
    _json["page_likes"] = qint64(page_likes);
}
