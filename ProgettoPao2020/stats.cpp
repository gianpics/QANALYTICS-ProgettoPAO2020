#include "stats.h"

Stats::Stats(u_int _month, u_int _year, u_int _impression, u_int _coverage, u_int _like) : impression(_impression), coverage(_coverage), like(_like)
{
    month = (_month>0 && _month<13) ? _month : 0;
    year = (_year>2000) ? _month : 0;
}

Stats::~Stats(){}

u_int Stats::getMonth() const {return month;}

u_int Stats::getYear() const {return year;}

u_int Stats::getImpression() const {return impression;}

u_int Stats::getCoverage() const{return coverage;}

u_int Stats::getLike() const{return like;}
