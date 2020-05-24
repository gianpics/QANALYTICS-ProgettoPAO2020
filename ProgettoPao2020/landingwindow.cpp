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

    // - upper layout

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


     // - lower layout

    // search box
    searchTxt=new QLineEdit;
    connect(searchTxt,SIGNAL(textChanged(const QString&)),SLOT(searchTxtChanged(const QString&)));

    // line
    line=new QFrame;

    // creator list
    creatorsLvw=new QListView;

    // inserimento in layout inferiore
    creatorsLyt=new QVBoxLayout;
    creatorsLyt->addWidget(searchTxt);
    creatorsLyt->addWidget(line);
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

    // layout pulsanti
    settingBtn->setIcon(QIcon(":/resources/gear.png"));
    settingBtn->setFlat(true);
    settingBtn->setToolTip("Settings");
    settingBtn->setFixedSize(QSize(26,26));

    infoBtn->setIcon(QIcon(":/resources/info.png"));
    infoBtn->setFlat(true);
    infoBtn->setToolTip("Information");
    infoBtn->setFixedSize(QSize(26,26));

    buttonsLyt->setAlignment(Qt::AlignRight);



    // layout creators
    searchTxt->setPlaceholderText("Search");
    searchTxt->setFixedWidth(300);

    line->setFixedHeight(1);
    line->setObjectName("line");
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    creatorsLvw->setFixedSize(QSize(300,300));

    creatorsLyt->setAlignment(Qt::AlignCenter);

}

void LandingWindow::settingBtnClick(){
    // visualizza settingsWindow

}

void LandingWindow::infoBtnClick(){
    // visualizza infoWindow

}

void LandingWindow::searchTxtChanged(const QString &text){
    // filtra elementi creatorsLyt

    if(text=="")
    {
        // mostra tutti risultati
    }
    else
    {
        // regex su nome creator
    }
}
