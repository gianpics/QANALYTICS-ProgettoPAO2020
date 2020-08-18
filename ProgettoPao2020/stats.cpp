#include "stats.h"

Stats::Stats()
{

}

Stats::Stats(QDate _date, u_int _impression, u_int _coverage, u_int _like) : date(_date), impression(_impression), coverage(_coverage), like(_like){}

QDate Stats::getDate() const{ return date;}

Stats::~Stats(){}

u_int Stats::getImpression() const {return impression;}

u_int Stats::getCoverage() const{return coverage;}

u_int Stats::getLike() const{return like;}

void Stats::setDate(QDate _date)
{
    date = _date;
}

void Stats::setImpression(u_int _impression)
{
    impression = _impression;
}

void Stats::setCoverage(u_int _coverage)
{
    coverage = _coverage;
}

void Stats::setLike(u_int _like)
{
    like = _like;
}

void Stats::print(ostream &_os) const
{
    _os<<date.toString().toStdString()<<endl<<impression<<endl<<coverage<<endl<<like<<endl;
}

void Stats::read(const QJsonObject &_json)
{
    if(_json.contains("date") && _json.value("date").isString())
        date = QDate::fromString(_json.value("date").toString(), Qt::ISODate);

    if(_json.contains("impression"))
        impression = (u_int)_json.value("impression").toInt();

    if(_json.contains("coverage"))
        coverage = (u_int) _json.value("coverage").toInt();

    if(_json.contains("like"))
        like = (u_int) _json.value("like").toInt();
}

void Stats::write(QJsonObject &_json) const
{
    _json["date"] = date.toString(Qt::ISODate);
    _json["coverage"] = qint64(coverage);
    _json["impression"] = qint64(impression);
    _json["like"] = qint64(like);
}

