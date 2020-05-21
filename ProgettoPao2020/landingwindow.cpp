#include <QObject>
#include <QDebug>
#include <QSettings>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include "landingwindow.h"

LandingWindow::LandingWindow()
{
    // carica titolo finestra dal file config
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    setWindowTitle(settings.value("app/title").toString());

    // spawn widget
    setWidgets();

    // stile
    setWinStyle();
}

void LandingWindow::setWidgets(){

    // btn impostazioni
    settingBtn=new QPushButton;
    connect(settingBtn,SIGNAL(clicked()), this, SLOT(settingBtnClick()));

    // btn info
    infoBtn=new QPushButton;
    connect(infoBtn, SIGNAL(clicked()), SLOT(infoBtnClick()));

    // inserimento buttons in layout superiore
    buttonsLyt=new QHBoxLayout;
    buttonsLyt->addWidget(infoBtn);
    buttonsLyt->addWidget(settingBtn);
    buttonsLyt->setAlignment(Qt::AlignRight);

    // search box
    searchTxt=new QLineEdit;
    connect(searchTxt,SIGNAL(textChanged(const QString&)),SLOT(searchTxtChanged(const QString&)));

    // creator list
    creatorsLvw=new QListView;

    // inserimento in layout inferiore
    creatorsLyt=new QVBoxLayout;
    creatorsLyt->addWidget(searchTxt);
    creatorsLyt->addWidget(creatorsLvw);

    mainLyt=new QVBoxLayout(this);
    mainLyt->addLayout(buttonsLyt);
    mainLyt->addLayout(creatorsLyt);
}

void LandingWindow::setWinStyle(){

    // imposta foglio di stile
    QFile file(":/resources/stylesheet.css");
    file.open(QFile::ReadOnly);
    setStyleSheet(QLatin1String(file.readAll()));

    // finestra
    setFixedSize(QSize(800,600));
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            size(),
            qApp->desktop()->availableGeometry()
        )
    );

    // pulsanti
    settingBtn->setIcon(QIcon(":/resources/gear.png"));
    settingBtn->setFlat(true);
    settingBtn->setToolTip("Settings");
    settingBtn->setFixedSize(QSize(26,26));

    infoBtn->setIcon(QIcon(":/resources/info.png"));
    infoBtn->setFlat(true);
    infoBtn->setToolTip("Information");
    infoBtn->setFixedSize(QSize(26,26));

    searchTxt->setPlaceholderText("Search");

}

void LandingWindow::settingBtnClick(){
    // visualizza settingsWindow
    qInfo()<<"click btnsetting";
}

void LandingWindow::infoBtnClick(){
    // visualizza infoWindow
    qInfo()<<"click btninfo";
}

void LandingWindow::searchTxtChanged(const QString &text){
    // filtra elementi creatorsLyt
    qInfo()<<"txt: "<<text;
    if(text=="")
    {
        // mostra tutti risultati
    }
    else
    {
        // regex su nome creator
    }
}
