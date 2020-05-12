#include "stats.h"

Stats::Stats(u_int _month, u_int _year, u_int _impression, u_int _coverage, u_int _like) : Impression(_impression), Coverage(_coverage), Like(_like)
{
    Month = (_month>0 && Month<13) ? _month : 0;
    Year = (_year>2000) ? _month : 0;
}
