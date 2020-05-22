#include "model.h"

QChart& Model::setChart(QBarSeries *qbs, const QStringList& _cat) const
{
    QChart *chart = new QChart();
    chart->addSeries(qbs);
    chart->legend()->hide();

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(_cat);
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
    QStringList categories;
    const Account &acc = selected->getAccountById(_id_account);
    const vector<Stats_account*>& stats = acc.getStats();
    for(auto a : stats){
        QDateTime date;
        date.setDate(a->getDate().addMonths(-1));
        *set<<a->getFollowers();
        categories << date.toString("MMM yyyy");
    }
    series->append(set);
    QChart *chart = &setChart(series, categories);
    chart->setTitle("Followers chart");
    return chart;
}

QChart *Model::graphImpression(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Impression");
    QStringList categories;
    const Account &acc = selected->getAccountById(_id_account);
    const vector<Stats_account*>& stats = acc.getStats();
    for(auto a : stats){
        QDateTime date;
        date.setDate(a->getDate());
        *set<<a->getImpression();
        categories << date.toString("MMM yyyy");
    }
    series->append(set);
    QChart *chart = &setChart(series, categories);
    chart->setTitle("Impression chart");
    return chart;
}

QChart *Model::graphCoverage(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Coverage");
    QStringList categories;
    const Account &acc = selected->getAccountById(_id_account);
    const vector<Stats_account*>& stats = acc.getStats();
    for(auto a : stats){
        QDateTime date;
        date.setDate(a->getDate());
        *set<<a->getCoverage();
        categories << date.toString("MMM yyyy");
    }
    series->append(set);
    QChart *chart = &setChart(series, categories);
    chart->setTitle("Coverage chart");
    return chart;
}

QChart *Model::graphLike(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Like");
    QStringList categories;
    const Account &acc = selected->getAccountById(_id_account);
    const vector<Stats_account>* stats = acc.getStats();
    for(auto a : *stats){
        QDateTime date;
        date.setDate(a->getDate());
        *set<<a->getLike();
        categories << date.toString("MMM yyyy");
    }
    series->append(set);
    QChart *chart = &setChart(series, categories);
    chart->setTitle("Like chart");
    return chart;
}
//ONLY FACEBOOK
QChart *Model::graphPageLikes(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Page Likes");
    QStringList categories;
    const Account &acc = selected->getAccountById(_id_account);
    const vector<Stats_account*>& stats = acc.getStats();
    if(!(acc.getType()==facebook)) {throw "This account doesn't have Page Like Stats";}
    for(auto a : stats){
        Stats_facebook* b = dynamic_cast<Stats_facebook*>(a);
        QDateTime date;
        date.setDate(a->getDate());
        *set<<b->getPageLikes();
        categories << date.toString("MMM yyyy");
    }
    series->append(set);
    QChart *chart = &setChart(series, categories);
    chart->setTitle("Page Likes chart");
    return chart;
}
//EXCEPT FACEBOOK
QChart *Model::graphFollowing(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Following");
    QStringList categories;
    const Account &acc = selected->getAccountById(_id_account);
    const vector<Stats_account*>& stats = acc.getStats();
    if(acc.getType()==facebook) {throw "This account doesn't have Following Stats";}
    for(auto a : stats){
        QDateTime date;
        date.setDate(a->getDate());
        categories << date.toString("MMM yyyy");
        if(dynamic_cast<Stats_youtube*>(a))
            *set<<dynamic_cast<Stats_youtube*>(a)->getFollowing();
        else
            *set<<dynamic_cast<Stats_instagram*>(a)->getFollowing();
    }
    series->append(set);
    QChart *chart = &setChart(series, categories);
    chart->setTitle("Following chart");
    return chart;
}
//ONLY YOUTUBE
QChart *Model::graphDonators(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Donators");
    QStringList categories;
    const Account &acc = selected->getAccountById(_id_account);
    const vector<Stats_account*>& stats = acc.getStats();
    if(!(acc.getType()==youtube)) {throw "This account doesn't have Donators Stats";}
    for(auto a : stats){
        Stats_youtube* b = dynamic_cast<Stats_youtube*>(a);
        QDateTime date;
        date.setDate(a->getDate());
        *set<<b->getDonators();
        categories << date.toString("MMM yyyy");
    }
    series->append(set);
    QChart *chart = &setChart(series, categories);
    chart->setTitle("Donators chart");
    return chart;
}
//ONLY YOUTUBE
QChart *Model::graphTotalViews(u_int _id_account) const
{
    QBarSeries * series = new QBarSeries();
    QBarSet *set = new QBarSet("Total Views");
    QStringList categories;
    const Account &acc = selected->getAccountById(_id_account);
    const vector<Stats_account*>& stats = acc.getStats();
    if(!(acc.getType()==youtube)) {throw "This account doesn't have Total Views Stats";}
    for(auto a : stats){
        Stats_youtube* b = dynamic_cast<Stats_youtube*>(a);
        QDateTime date;
        date.setDate(a->getDate());
        *set<<b->getTotalViews();
        categories << date.toString("MMM yyyy");
    }
    series->append(set);
    QChart *chart = &setChart(series, categories);
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
    const vector<Stats_account*>& stats = acc.getStats();
    if(!(acc.getType()==youtube)) {throw "This account doesn't have AVG Watch Time Stats";}
    for(auto a : stats){
        Stats_youtube* b = dynamic_cast<Stats_youtube*>(a);
        QDateTime date;
        date.setDate(a->getDate());
        *set<<b->getAvgWatchtime();
        categories << date.toString("MMM yyyy");
    }
    series->append(set);
    QChart *chart = &setChart(series, categories);
    chart->setTitle("Average Watch Time chart");
    return chart;
}
