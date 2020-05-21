#ifndef MODEL_H
#define MODEL_H
#include "creatorlist.h"
#include <typeinfo>
#include <QtCharts>
#include <QLineSeries>
#include <QDateTime>

class Model
{
private:
    CreatorList list;
    Creator* selected;
    QChart& setChart(QBarSeries * qls, const QStringList& _cat) const;
public:
    Model(const CreatorList& _cl);
    void setSelected(std::string _SSD);
    QChart *graphFollowers(u_int _id) const;
    QChart *graphImpression(u_int _id) const;
    QChart *graphCoverage(u_int _id) const;
    QChart *graphLike(u_int _id) const;
    QChart *graphPageLikes(u_int _id) const;  //ONLY FACEBOOK
    QChart *graphFollowing(u_int _id) const;  //ONLY YOUTUBE & INSTAGRAM
    QChart *graphDonators(u_int _id) const;   //ONLY YOUTUBE
    QChart *graphTotalViews(u_int _id) const; //ONLY YOUTUBE
    QChart *graphAvgWatchtime(u_int _id) const;   //ONLY YOUTUBE
};

#endif // MODEL_H
