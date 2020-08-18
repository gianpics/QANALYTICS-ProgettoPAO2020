#include <QSettings>
#include <QDebug>
#include <QCoreApplication>
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
}
