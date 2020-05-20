#ifndef MODEL_H
#define MODEL_H
#include "creatorlist.h"
#include <QtCharts>
#include <QLineSeries>

class model
{
private:
    CreatorList list;
    Creator* selected;
public:
    model();
    void setSelected(u_int _SSD);
    QLineSeries *graphFollowers(u_int _SSN) const;
    QLineSeries *graphImpression(u_int _SSN) const;
    QLineSeries *graphCoverage(u_int _SSN) const;
    QLineSeries *graphLike(u_int _SSN) const;
    QLineSeries *graphPageLikes(u_int _SSN) const;  //ONLY FACEBOOK
    QLineSeries *graphFollowing(u_int _SSN) const;  //ONLY YOUTUBE & INSTAGRAM
    QLineSeries *graphDonators(u_int _SSN) const;   //ONLY YOUTUBE
    QLineSeries *graphTotalWatchtime(u_int _SSN) const; //ONLY YOUTUBE
    QLineSeries *graphAvgWatchtime(u_int _SSN) const;   //ONLY YOUTUBE
};

#endif // MODEL_H
