#include "stats.h"

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

