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

void Stats::read(const QJsonObject &_json)
{
    if(_json.contains("date") && _json.value("date").isString())
        date = QDate::fromString(_json.value("date").toString(), Qt::ISODate);
    else
        throw runtime_error("Date format or value not valid.");

    if(_json.contains("impression") && _json.value("impression").isDouble())
        impression = (u_int)_json.value("impression").toInt();
    else
        throw runtime_error("Impression format or value not valid.");

    if(_json.contains("coverage") && _json.value("coverage").isDouble())
        coverage = (u_int) _json.value("coverage").toInt();
    else
        throw runtime_error("Coverage format or value not valid.");

    if(_json.contains("like") && _json.value("like").isDouble())
        like = (u_int) _json.value("like").toInt();
    else
        throw runtime_error("Like format or value not valid.");
}

void Stats::write(QJsonObject &_json) const
{
    _json["date"] = date.toString(Qt::ISODate);
    _json["coverage"] = qint64(coverage);
    _json["impression"] = qint64(impression);
    _json["like"] = qint64(like);
}

