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
        Stats(u_int = 0, u_int = 0, u_int =0 , u_int = 0, u_int =0);
        virtual ~Stats() = default;
        virtual u_int getMonth() const;
        virtual u_int getYear() const;
        virtual u_int getImpression() const;
        virtual u_int getCoverage() const;
        virtual u_int getLike() const;
};

#endif // STATS_H
