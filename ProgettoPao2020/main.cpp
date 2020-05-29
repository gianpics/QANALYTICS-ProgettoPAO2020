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

CreatorList* addCreator();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    Controller c(&m);
    LandingWindow lw(&c);
    c.setView(&lw);
    lw.show();
    return a.exec();
}
