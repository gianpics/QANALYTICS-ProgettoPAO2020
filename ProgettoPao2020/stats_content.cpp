#include "stats_content.h"

Stats_content::Stats_content()
{

}

Stats_content::Stats_content(QDate _date, u_int _impression, u_int _coverage, u_int _like, u_int _dislike, u_int _numcomments, u_int _views, u_int _watchtime) : Stats(_date, _impression, _coverage, _like), dislike(_dislike), num_comments(_numcomments), views(_views), watchtime(_watchtime){}

void Stats_content::setDislike(u_int _dislike)
{
    dislike=_dislike;
}

void Stats_content::setNum_comments(u_int _numcomments)
{
    num_comments = _numcomments;
}

void Stats_content::setViews(u_int _views)
{
    views = _views;
}

void Stats_content::setWatchtime(u_int _watchtime)
{
    watchtime = _watchtime;
}

Stats_content *Stats_content::clone() const
{
    return new Stats_content(*this);
}

void Stats_content::read(const QJsonObject &_json)
{
    Stats::read(_json);
    if(_json.contains("dislike"))
        dislike = _json.value("dislike").toInt();
    if(_json.contains("n_comments"))
        num_comments = _json.value("n_comments").toInt();
    if(_json.contains("views"))
        views = _json.value("views").toInt();
    if(_json.contains("watchtime"))
        watchtime = _json.value("watchtime").toInt();
}

void Stats_content::write(QJsonObject &_json) const
{
    Stats::write(_json);
    _json["dislike"] = qint64(dislike);
    _json["n_comments"] = qint64(num_comments);
    _json["views"] = qint64(views);
    _json["watchtime"] = qint64(watchtime);
}
