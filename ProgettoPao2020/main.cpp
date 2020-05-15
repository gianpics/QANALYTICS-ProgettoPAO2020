#include "mainwindow.h"
#include "stats_instagram.h"
#include "stats_facebook.h"
#include "stats_youtube.h"
#include "creator.h"
#include "content.h"
#include "creatorlist.h"
#include "account.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
    Stats_content sc1(01, 2010, 212, 525, 989);
    Stats_content sc2(02, 2010, 212, 525, 989);
    std::vector<Stats_content*> listsc;
    listsc.push_back(&sc1);
    listsc.push_back(&sc2);
    Content c1("SCHERZO EPIKO FINITO MALE", "asdasdasdasd", *(new QDateTime()), video, listsc);
    Content c2("COME FOSSERO I GIOCATORI SENZA DENTI", "afdsfsdf", *(new QDateTime()), video, listsc);
    std::vector<Content*> lc;
    lc.push_back(&c1);
    lc.push_back(&c2);
    Stats_account *sy1 = new Stats_youtube(01,2010,25282,68168,885,25181,121);
    Stats_account *sy2 = new Stats_youtube(02,2010,25282,68168,885,25181,122);
    std::vector<Stats_account*> listsy;
    listsy.push_back(sy1);
    listsy.push_back(sy2);
    Account acc(0, "panz", "panz@gmail.com", youtube, lc, listsy);
    Account acc1=acc;
    //acc1->getContents()->pop_back();
    acc.getContents()->at(0)->setTitle("asdadsasdasd");
    std::cout << (acc.getContents()->at(0)->getTitle())<< std::endl;
    std::cout << (acc1.getContents()->at(0)->getTitle())<< std::endl;
    //std::cout << dynamic_cast<Stats_youtube*>(acc->getStats()->at(1))->getFollowing() <<std::endl;
    std::cout << acc.getUsername()<<std::endl;

    acc1->getStats()->pop_back();
    std::cout << dynamic_cast<Stats_youtube*>(acc->getStats()->at(1))->getFollowing() <<std::endl;
    std::cout << dynamic_cast<Stats_youtube*>(acc1->getStats()->at(1))->getFollowing() <<std::endl;
}
