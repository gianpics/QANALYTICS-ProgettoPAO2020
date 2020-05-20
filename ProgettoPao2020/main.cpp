#include <QSettings>
#include <QDebug>
#include <QCoreApplication>
#include "mainwindow.h"
#include "stats_instagram.h"
#include "stats_facebook.h"
#include "stats_youtube.h"
#include "creator.h"
#include "content.h"
#include "creatorlist.h"
#include "account.h"
#include "landingwindow.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LandingWindow w;
    w.show();
    return a.exec();

    /*Stats_content sc1(01, 2010, 212, 525, 989);
    Stats_content sc2(02, 2010, 212, 525, 989);
    std::vector<Stats_content> listsc;
    listsc.push_back(sc1);
    listsc.push_back(sc2);
    Content c1("SCHERZO EPIKO FINITO MALE", "asdasdasdasd", *(new QDateTime()), video, listsc);
    Content c2("COME FOSSERO I GIOCATORI SENZA DENTI", "afdsfsdf", *(new QDateTime()), video, listsc);
    std::vector<Content> lc;
    lc.push_back(c1);
    lc.push_back(c2);
    Stats_youtube sy1(01,2010,25282,68168,885,25181,121);
    Stats_youtube sy2(02,2010,25282,68168,885,25181,122);
    std::vector<Stats_account> listsy;
    listsy.push_back(sy1);
    listsy.push_back(sy2);
    Account acc(0, "panz", "panz@gmail.com", youtube, lc, listsy);
    Account acc1=acc;
    acc.getContents()->pop_back();
    std::cout << acc.getContents()->at(0).getType() <<std::endl;
    std::cout << acc1.getContents()->size() <<std::endl;*/

}
