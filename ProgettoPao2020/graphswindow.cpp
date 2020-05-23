#include "graphswindow.h"
#include <QFile>
#include <QDebug>

Graphswindow::Graphswindow()
{
    setWidget();

    setWinStyle();
}

void Graphswindow::setWidget()
{
    setSideWidget();

    vLine=new QFrame;

    setGraphsWidget();

    mainLyt=new QHBoxLayout(this);
    mainLyt->addLayout(sideLyt);
    mainLyt->addWidget(vLine);
    mainLyt->addLayout(graphsLyt);
}

void Graphswindow::setSideWidget()
{
    accountsLbl=new QLabel;
    accountsLvw=new QListView;
    hLine=new QFrame;
    statsLbl=new QLabel;
    statsLvw=new QListView;
    sideLyt=new QVBoxLayout;
    sideLyt->addWidget(accountsLbl);
    sideLyt->addWidget(accountsLvw);
    sideLyt->addWidget(hLine);
    sideLyt->addWidget(statsLbl);
    sideLyt->addWidget(statsLvw);
}

void Graphswindow::setGraphsWidget()
{
    graphsLvw=new QListView;

    graphsLyt=new QVBoxLayout;
    graphsLyt->addWidget(graphsLvw);
}

void Graphswindow::setWinStyle()
{
    // imposta foglio di stile
    QFile file(":/resources/stylesheet.css");
    file.open(QFile::ReadOnly);
    setStyleSheet(QLatin1String(file.readAll()));
    //qInfo()<<"style: "<<QLatin1String(file.readAll());

    // titolo finestra da nome creator
    setWindowTitle("temp");
    setMinimumSize(QSize(600,400));

    accountsLbl->setText("Accounts");
    accountsLbl->setObjectName("section");
    statsLbl->setText("Stats");
    statsLbl->setObjectName("section");

    hLine->setFixedHeight(1);
    hLine->setObjectName("line");
    hLine->setFrameShape(QFrame::HLine);
    hLine->setFrameShadow(QFrame::Sunken);

    vLine->setFixedWidth(1);
    vLine->setObjectName("line");
    vLine->setFrameShape(QFrame::VLine);
    vLine->setFrameShadow(QFrame::Sunken);
}
