#include <QSettings>
#include <QDebug>
#include <QCoreApplication>
#include "mainwindow.h"
#include "model.h"
#include "graphswindow.h"
#include "landingwindow.h"
#include "controller.h"
#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("QANALYTICS");
    QCoreApplication::setApplicationName("QANALYTICS");
    QSettings settings("QANALYTICS", "QANALYTICS");
    QApplication a(argc, argv);
    Model m;
    Controller c(&m);
    LandingWindow lw(&c);
    c.setView(&lw);
    lw.show();
    return a.exec();


/*---------------------------------------------------------------------------------------------------------------------
    //INSERIMENTO DATI CREATOR 2
    //STATS_CONTENT     QDATE, IMPRESSION, COVERAGE, LIKE, DISLIKE, NUMCOMMENTS, VIEWS, WATCHTIME
    Stats_content sc7a(*new QDate(2020, 02, 1), 40, 200, 45, 0, 10, 150, 0);      //IMAGE
    Stats_content sc7b(*new QDate(2020, 03, 1), 30, 190, 65, 0, 12, 180, 0);      //IMAGE

    Stats_content sc8a(*new QDate(2020, 02, 1), 30, 250, 80, 0, 25, 200, 0);      //IMAGE
    Stats_content sc8b(*new QDate(2020, 03, 1), 25, 220, 90, 0, 29, 220, 0);      //IMAGE

    Stats_content sc9a(*new QDate(2020, 02, 1), 20, 800, 25, 150, 200, 500, 0);      //TEXT
    Stats_content sc9b(*new QDate(2020, 03, 1), 10, 900, 28, 190, 220, 800, 0);      //TEXT

    listsc.clear(); listsc.push_back(&sc7a); listsc.push_back(&sc7b);
    Content c4a(*(new QDateTime(*new QDate(2020, 01, 26))), image, listsc, "", "Nuovi acquisti");
    listsc.clear(); listsc.push_back(&sc8a); listsc.push_back(&sc8b);
    Content c4b(*(new QDateTime(*new QDate(2020, 01, 10))), image, listsc, "", "Non smettere mai di lottare, sei una leonessa.");
    listsc.clear(); listsc.push_back(&sc9a); listsc.push_back(&sc9b);
    Content c5a(*(new QDateTime(*new QDate(2020, 01, 11))), text, listsc, "", "Quanto mi piacciono i bambini XD");

    //STATS_INSTA   QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, FOLLOWING
    Stats_instagram si2a(*new QDate(2020, 02, 1),400,600,125,500, 1250);
    Stats_instagram si2b(*new QDate(2020, 03, 1),500,800,155,550, 1300);
    lc.clear(); lc.push_back(c4a);lc.push_back(c4b);
    listsa.clear(); listsa.push_back(&si2a); listsa.push_back(&si2b);
    Account acc2a(10, "yubiINSTA", "yubi@gmail.com", instagram, lc, listsa);
    //STATS_FB      QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, PAGE_LIKES
    Stats_facebook sf2a(*new QDate(2020, 02, 1),50,1000,25,200, 150);
    Stats_facebook sf2b(*new QDate(2020, 03, 1),60,1100,28,202, 160);
    lc.clear(); lc.push_back(c5a);
    listsa.clear(); listsa.push_back(&sf2a); listsa.push_back(&sf2b);
    Account acc2b(11, "yubiFB", "yubi@gmail.com", facebook, lc, listsa);

    la.clear(); la.push_back(acc2a);la.push_back(acc2b);
    Creator c2(la, "Ayoub", "MAHER", "AYBMHR", "Via napoli", "000026598", "Yubi");

//---------------------------------------------------------------------------------------------------------------------------
    //INSERIMENTO DATI CREATOR 3

    //STATS_CONTENT     QDATE, IMPRESSION, COVERAGE, LIKE, DISLIKE, NUMCOMMENTS, VIEWS, WATCHTIME
    Stats_content sc10a(*new QDate(2020, 02, 1), 30000, 600000, 150000, 1000, 10000, 800000, 800);      //VIDEO
    Stats_content sc10b(*new QDate(2020, 03, 1), 40000, 800000, 200000, 1500, 12000, 1000000, 787);      //VIDEO

    listsc.clear(); listsc.push_back(&sc10a); listsc.push_back(&sc10b);
    Content c6a(*(new QDateTime(*new QDate(2020, 01, 1))), video, listsc, "FREE CATS <3", "descxxx 4catlover");

    //STATS_YT      QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, FOLLOWING, DONATORS, TOTAL_VIEWS, AVG_WATCHTIME
    Stats_youtube sy3a(*new QDate(2020, 02, 1), 70000, 650000, 150000, 200000, 1, 500, 800000, 800);
    Stats_youtube sy3b(*new QDate(2020, 03, 1), 80000, 700000, 200000, 300000, 1, 550, 1000000, 787);
    lc.clear(); lc.push_back(c6a);
    listsa.clear(); listsa.push_back(&sy3a); listsa.push_back(&sy3b);
    Account acc3a(20, "gianpicsYT", "gianpics@gmail.com", youtube, lc, listsa);
    la.clear(); la.push_back(acc3a);
    Creator c3(la, "Gianpiero Giuseppe", "TOVO", "GNPTVO", "Via milano", "000098562", "Gianpics");
//----------------------------------------------------------------------------------------------------------------------------*/
    //CreatorList *cl = new CreatorList(c1);
    //cl->InsertBack(c2);
    //cl->InsertBack(c3);
    //model->setList(cl);
    //return cl;

    return 0;
}
