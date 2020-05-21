#include <QSettings>
#include <QDebug>
#include <QCoreApplication>
#include "mainwindow.h"
#include "model.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //INSERIMENTO DATI
    Stats_content sc1(*new QDate(2010, 01, 1), 212, 525, 989);
    Stats_content sc2(*new QDate(2010, 02, 1), 212, 525, 989);

    std::vector<Stats_content> listsc;
    listsc.push_back(sc1);
    listsc.push_back(sc2);
    Content c1("SCHERZO EPIKO FINITO MALE", "asdasdasdasd", *(new QDateTime()), video, listsc);
    Content c2("COME FOSSERO I GIOCATORI SENZA DENTI", "afdsfsdf", *(new QDateTime()), video, listsc);
    std::vector<Content> lc;
    lc.push_back(c1);
    lc.push_back(c2);
    //STATS         QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS
    //STATS_FB      QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, PAGE_LIKES
    //STATS_YT      QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, FOLLOWING, DONATORS, TOTAL_VIEWS, AVG_WATCHTIME
    //STATS_INSTA   QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, FOLLOWING
    Stats_youtube sy1(*new QDate(2010, 01, 1),500,200,1200,110100,125, 10, 198000, 300);
    Stats_youtube sy2(*new QDate(2010, 02, 1),800,500,1300,120000,122, 25, 200000, 312);
    Stats_youtube sy3(*new QDate(2010, 03, 1),1200,1000,1250,125000, 126, 31, 201000, 308);
    std::vector<Stats_account*> listsy;
    listsy.push_back(&sy1);
    listsy.push_back(&sy2);
    listsy.push_back(&sy3);
    Account acc(0, "panz", "panz@gmail.com", youtube, lc, listsy);
    Stats_facebook sf1(*new QDate(2010, 01, 1),600,200,1200,110100, 2000);
    Stats_facebook sf2(*new QDate(2010, 02, 1),900,700,1300,120000, 2200);
    Stats_facebook sf3(*new QDate(2010, 03, 1),1300,2220,1250,125000, 3000);
    listsy.clear();
    listsy.push_back(&sf1);
    listsy.push_back(&sf2);
    listsy.push_back(&sf3);
    Account acc1(1, "panz", "panz@gmail.com", facebook, lc, listsy);
    Stats_instagram si1(*new QDate(2010, 01, 1),200,300,1200,110100, 125);
    Stats_instagram si2(*new QDate(2010, 02, 1),300,800,1300,120000, 130);
    Stats_instagram si3(*new QDate(2010, 03, 1),900,3000,1250,125000, 200);
    listsy.clear();
    listsy.push_back(&si1);
    listsy.push_back(&si2);
    listsy.push_back(&si3);
    Account acc2(2, "panz", "panz@gmail.com", instagram, lc, listsy);
    Creator c(acc, "Giacomo", "Sassaro", "SSSGCM", "Via roma", "000012562", "Panz");
    c.addAccount(acc1);
    c.addAccount(acc2);
    CreatorList cl(c);

    //MODELLO
    Model m(cl);
    m.setSelected("SSSGCM");
    QChart *chart = m.graphImpression(2);
    //QChart *chart = m.graphCoverage(2);
    //QChart *chart = m.graphLike(2);
    //QChart *chart = m.graphFollowers(1);
    //QChart *chart = m.graphFollowing(0);
    //QChart *chart = m.graphDonators(0);
    //QChart *chart = m.graphTotalViews(0);
    //QChart *chart = m.graphAvgWatchtime(0);
    //QChart *chart = m.graphPageLikes(1);
    //VISTA
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    w.setCentralWidget(chartView);
    w.resize(400, 300);
    w.show();
    return a.exec();
}
