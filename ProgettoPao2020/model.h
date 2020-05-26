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
    CreatorList* list;
    Creator* selected;
    void setChart(QBarSeries* qls, QStringList * qsl, QChart* chart) const;
    void setCategories(vector<u_int>* _id, QStringList * categories) const;
    void setQBarSetColor(QBarSet* qbs) const;
public:
    Model();
    void setList(CreatorList * _cl);
    void setSelected(std::string _SSN);
    int getSelectedAccountsNumber() const;
    account_type getSelectedAccountType(int i) const;
    QString getSelectedAccountEmail(int i) const;
    QString getSelectedAccountUsername(int i) const;
    int getSelectedAccountId(int i) const;
    account_type getSelectedTypeById(int i) const;
    QString getSelectedFullName() const;
    QChart *graphFollowers(vector<u_int>* _id) const;
    QChart *graphImpression(vector<u_int>* _id) const;
    QChart *graphCoverage(vector<u_int>* _id) const;
    QChart *graphLike(vector<u_int>* _id) const;
    QChart *graphPageLikes(vector<u_int>* _id) const;  //ONLY FACEBOOK
    QChart *graphFollowing(vector<u_int>* _id) const;  //ONLY YOUTUBE & INSTAGRAM
    QChart *graphDonators(vector<u_int>* _id) const;   //ONLY YOUTUBE
    QChart *graphTotalViews(vector<u_int>* _id) const; //ONLY YOUTUBE
    QChart *graphAvgWatchtime(vector<u_int>* _id) const;   //ONLY YOUTUBE
    void reset();
};

#endif // MODEL_H
