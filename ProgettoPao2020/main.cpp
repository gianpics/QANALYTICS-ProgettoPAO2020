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
    Stats_youtube sy1(*new QDate(2010, 01, 1),500,68168,885,500,121);
    Stats_youtube sy2(*new QDate(2010, 02, 1),800,68168,885,800,122);
    Stats_youtube sy3(*new QDate(2010, 03, 1),5659,6262,324,600);
    std::vector<Stats_account> listsy;
    listsy.push_back(sy1);
    listsy.push_back(sy2);
    listsy.push_back(sy3);
    Account acc(0, "panz", "panz@gmail.com", youtube, lc, listsy);
    Creator c(acc, "Giacomo", "Sassaro", "SSSGCM", "Via roma", "000012562", "Panz");
    CreatorList cl(c);

    //MODELLO
    Model m(cl);
    m.setSelected("SSSGCM");
    QChart *chart = m.graphFollowers(0);
    //VISTA
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    w.setCentralWidget(chartView);
    w.resize(400, 300);
    w.show();
    return a.exec();

    /*acc.getContents()->pop_back();
    std::cout << acc.getContents()->at(0).getType() <<std::endl;
    std::cout << acc1.getContents()->size() <<std::endl;*/

}
