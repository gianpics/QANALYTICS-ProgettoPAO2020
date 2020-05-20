#include <QObject>
#include <QSettings>
#include <QCoreApplication>
#include "landingwindow.h"

LandingWindow::LandingWindow()
{
    //QSettings settings(QString(":/config.ini"), QSettings::IniFormat);
    setWindowTitle("title");

    // spawn widget
    setWidgets();

    // imposta stili
    setStyle();
}

void LandingWindow::setWidgets(){
    // btn impostazioni
    settingBtn=new QPushButton(this);
    settingBtn->setIcon(QIcon(":/resources/gear.png"));
    settingBtn->setFlat(true);
    connect(settingBtn,SIGNAL(QPushButton::clicked), this, SLOT(settingBtnClick()));

    // btn info
    infoBtn=new QPushButton(this);
    infoBtn->setIcon(QIcon(":/resources/info.png"));
    infoBtn->setFlat(true);
    connect(infoBtn,SIGNAL(QPushButton::clicked), this, SLOT(infoBtnClick()));
}

void LandingWindow::setStyle(){}

void LandingWindow::settingBtnClick(){
    // visualizza settingsWindow
}

void LandingWindow::infoBtnClick(){
    // visualizza infoWindow
}
