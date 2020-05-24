#include "graphswindow.h"
#include <QFile>
#include <QDebug>

GraphsWindow::GraphsWindow()
{
    setWidget();

    setWinStyle();
}

void GraphsWindow::setWidget()
{
    setSideWidget();

    vLine=new QFrame;

    setGraphsWidget();

    mainLyt=new QHBoxLayout(this);
    mainLyt->addLayout(sideLyt);
    mainLyt->addWidget(vLine);
    mainLyt->addLayout(graphsLyt);
}

void GraphsWindow::setSideWidget()
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

void GraphsWindow::setGraphsWidget()
{
    graphsLvw=new QListView;

    graphsLyt=new QVBoxLayout;
    graphsLyt->addWidget(graphsLvw);
}

void GraphsWindow::setWinStyle()
{
    // imposta foglio di stile
    QFile file(":/resources/stylesheet.css");
    file.open(QFile::ReadOnly);
    setStyleSheet(QLatin1String(file.readAll()));
    //qInfo()<<"style: "<<QLatin1String(file.readAll());

    // titolo finestra da nome creator
    setWindowTitle("temp");
    setMinimumSize(QSize(900,600));

    accountsLbl->setText("Accounts");
    accountsLbl->setObjectName("section");
    statsLbl->setText("Stats");
    statsLbl->setObjectName("section");

    mainLyt->setSpacing(0);
    mainLyt->setMargin(0);

    accountsLbl->setMargin(8);
    statsLbl->setMargin(8);

    accountsLvw->setFixedWidth(270);
    statsLvw->setFixedWidth(270);
    hLine->setFixedWidth(270);

    hLine->setFixedHeight(1);
    hLine->setObjectName("line");
    hLine->setFrameShape(QFrame::HLine);
    hLine->setFrameShadow(QFrame::Sunken);

    vLine->setFixedWidth(1);
    vLine->setObjectName("line");
    vLine->setFrameShape(QFrame::VLine);
    vLine->setFrameShadow(QFrame::Sunken);
}
