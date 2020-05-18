#ifndef STATS_H
#define STATS_H

typedef unsigned int u_int;
class Stats
{
    private:
        u_int month;
        u_int year;
        u_int impression;
        u_int coverage;
        u_int like;
    public:
        Stats(u_int _month, u_int _year, u_int _impression, u_int _coverage, u_int _like);
        virtual ~Stats()  = 0;
        virtual u_int getMonth() const;     
        virtual u_int getYear() const;
        virtual u_int getImpression() const;
        virtual u_int getCoverage() const;
        virtual u_int getLike() const;
        virtual void setMonth(u_int _month);
        virtual void setYear(u_int _year);
        virtual void setImpression(u_int _impression);
        virtual void setCoverage(u_int _coverage);
        virtual void setLike(u_int _like);
};

#endif // STATS_H
