#include "model.h"

QChart& Model::setChart(QBarSeries* qbs, const vector<const Stats_account*>& _stats) const
{
    QStringList categories;
    for(auto a : _stats){
        QDateTime date;
        date.setDate(a->getDate().addMonths(-1));
        categories << date.toString("MMM yyyy");
    }

    QChart *chart = new QChart();
    chart->addSeries(qbs);
    chart->legend()->hide();

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    qbs->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    qbs->attachAxis(axisY);
    return *chart;
}

Model::Model(const CreatorList& _list) : list(_list){}

void Model::setSelected(std::string _SSN){selected = &list.getCreatorBySSN(_SSN);}

QChart *Model::graphFollowers(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Followers");
    const vector<const Stats_account*>& stats =selected->getAccountById(_id_account).getStats();
    for(auto a : stats){
        *set<<a->getFollowers();
    }
    series->append(set);
    QChart *chart = &setChart(series, stats);
    chart->setTitle("Followers chart");
    return chart;
}

QChart *Model::graphImpression(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Impression");
    const vector<const Stats_account*>& stats =selected->getAccountById(_id_account).getStats();
    for(auto a : stats){
        *set<<a->getImpression();
    }
    series->append(set);
    QChart *chart = &setChart(series, stats);
    chart->setTitle("Impression chart");
    return chart;
}

QChart *Model::graphCoverage(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Coverage");
    const vector<const Stats_account*>& stats =selected->getAccountById(_id_account).getStats();
    for(auto a : stats){
        *set<<a->getCoverage();
    }
    series->append(set);
    QChart *chart = &setChart(series, stats);
    chart->setTitle("Coverage chart");
    return chart;
}

QChart *Model::graphLike(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Like");
    const vector<const Stats_account*>& stats =selected->getAccountById(_id_account).getStats();
    for(auto a : stats){
        *set<<a->getLike();
    }
    series->append(set);
    QChart *chart = &setChart(series, stats);
    chart->setTitle("Like chart");
    return chart;
}
//ONLY FACEBOOK
QChart *Model::graphPageLikes(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Page Likes");
    const Account &acc = selected->getAccountById(_id_account);
    const vector<const Stats_account*>& stats = acc.getStats();
    if(!(acc.getType()==facebook)) {throw "This account doesn't have Page Like Stats";}
    for(auto a : stats){
        *set<< static_cast<const Stats_facebook*>(a)->getPageLikes();
    }
    series->append(set);
    QChart *chart = &setChart(series, stats);
    chart->setTitle("Page Likes chart");
    return chart;
}
//EXCEPT FACEBOOK
QChart *Model::graphFollowing(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Following");
    const Account &acc = selected->getAccountById(_id_account);
    const vector<const Stats_account*>& stats = acc.getStats();
    if(acc.getType()==facebook) {throw "This account doesn't have Following Stats";}
    for(auto a : stats){
        if(dynamic_cast<const Stats_youtube*>(a))
            *set<<static_cast<const Stats_youtube*>(a)->getFollowing();
        else
            *set<<static_cast<const Stats_instagram*>(a)->getFollowing();
    }
    series->append(set);
    QChart *chart = &setChart(series, stats);
    chart->setTitle("Following chart");
    return chart;
}
//ONLY YOUTUBE
QChart *Model::graphDonators(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Donators");
    const Account &acc = selected->getAccountById(_id_account);
    const vector<const Stats_account*>& stats = acc.getStats();
    if(!(acc.getType()==youtube)) {throw "This account doesn't have Donators Stats";}
    for(auto a : stats){
        *set<<static_cast<const Stats_youtube*>(a)->getDonators();
    }
    series->append(set);
    QChart *chart = &setChart(series, stats);
    chart->setTitle("Donators chart");
    return chart;
}
//ONLY YOUTUBE
QChart *Model::graphTotalViews(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Total Views");
    const Account &acc = selected->getAccountById(_id_account);
    const vector<const Stats_account*>& stats = acc.getStats();
    if(!(acc.getType()==youtube)) {throw "This account doesn't have Total Views Stats";}
    for(auto a : stats){
        *set<<static_cast<const Stats_youtube*>(a)->getTotalViews();
    }
    series->append(set);
    QChart *chart = &setChart(series, stats);
    chart->setTitle("Total Views chart");
    return chart;
}
//ONLY YOUTUBE
QChart *Model::graphAvgWatchtime(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Average Watch Time");
    QStringList categories;
    const Account &acc = selected->getAccountById(_id_account);
    const vector<const Stats_account*>& stats = acc.getStats();
    if(!(acc.getType()==youtube)) {throw "This account doesn't have AVG Watch Time Stats";}
    for(auto a : stats){
        *set<<static_cast<const Stats_youtube*>(a)->getAvgWatchtime();
    }
    series->append(set);
    QChart *chart = &setChart(series, stats);
    chart->setTitle("Average Watch Time chart");
    return chart;
}
