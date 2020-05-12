#ifndef STATS_H
#define STATS_H

typedef unsigned int u_int;
class Stats
{
private:
    u_int Month;
    u_int Year;
    u_int Impression;
    u_int Coverage;
    u_int Like;
public:
    Stats(u_int = 0, u_int = 0, u_int =0 , u_int = 0, u_int =0);
    virtual ~Stats() = default;
    virtual u_int getMonth() const {return Month;}
    virtual u_int getYear() const {return Year;}
    virtual u_int getImpression() const {return Impression;}
    virtual u_int getCoverage() const{return Coverage;}
    virtual u_int getLike() const{return Like;}
};

#endif // STATS_H
