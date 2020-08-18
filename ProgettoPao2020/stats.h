#ifndef STATS_H
#define STATS_H
#include <QDate>
#include <iostream>
#include <QJsonObject>
using namespace std;
typedef unsigned int u_int;
class Stats
{
    private:
        QDate date;
        u_int impression;
        u_int coverage;
        u_int like;
    public:
        Stats();
        Stats(QDate _date, u_int _impression, u_int _coverage, u_int _like);
        virtual ~Stats()  = 0;
        virtual QDate getDate() const;
        virtual u_int getImpression() const;
        virtual u_int getCoverage() const;
        virtual u_int getLike() const;
        virtual void setDate(QDate _date);
        virtual void setImpression(u_int _impression);
        virtual void setCoverage(u_int _coverage);
        virtual void setLike(u_int _like);
        virtual Stats* clone() const = 0;
        virtual void read(const QJsonObject &_json);
        virtual void write(QJsonObject &_json) const;
};

#endif // STATS_H
