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
    accountsLyt=new QVBoxLayout;
    hLine=new QFrame;
    statsLbl=new QLabel;
    statsLyt=new QVBoxLayout;
    sideLyt=new QVBoxLayout;

    allaccountsBtn=new QToolButton;
    connect(allaccountsBtn, SIGNAL(clicked()), this, SLOT(accountBtnClick()));
    fbBtn=new QToolButton;
    connect(fbBtn, SIGNAL(clicked()), this, SLOT(accountBtnClick()));
    igBtn=new QToolButton;
    connect(igBtn, SIGNAL(clicked()), this, SLOT(accountBtnClick()));
    ytBtn=new QToolButton;
    connect(ytBtn, SIGNAL(clicked()), this, SLOT(accountBtnClick()));

    emit allaccountsBtn->clicked();

    sideLyt->addWidget(accountsLbl);
    sideLyt->addLayout(accountsLyt);
    accountsLyt->addWidget(allaccountsBtn);
    accountsLyt->addWidget(fbBtn);
    accountsLyt->addWidget(igBtn);
    accountsLyt->addWidget(ytBtn);
    sideLyt->addWidget(hLine);
    sideLyt->addWidget(statsLbl);
    sideLyt->addLayout(statsLyt);
}

void GraphsWindow::setGraphsWidget()
{
    graphsLyt=new QVBoxLayout;
}

void GraphsWindow::setWinStyle()
{
    // imposta foglio di stile
    QFile file(":/resources/stylesheet.css");
    file.open(QFile::ReadOnly);
    setStyleSheet(QLatin1String(file.readAll()));
    //qInfo()<<"style: "<<QLatin1String(file.readAll());

    // titolo finestra da nome creator
    setWindowTitle("Creator's stats");
    setMinimumSize(QSize(900,600));

    accountsLbl->setText("Accounts");
    accountsLbl->setObjectName("section");
    statsLbl->setText("Stats");
    statsLbl->setObjectName("section");

    accountsLyt->setAlignment(Qt::AlignTop);
    sideLyt->setAlignment(Qt::AlignTop);


    // pulsanti accounts
    allaccountsBtn->setFixedSize(QSize(275,60));
    allaccountsBtn->setObjectName("0");
    allaccountsBtn->setToolTip("View all accounts statistics");
    allaccountsBtn->setIcon(QIcon(":/resources/users.png"));
    allaccountsBtn->setIconSize(QSize(30,30));
    allaccountsBtn->setText("  All accounts");
    allaccountsBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    fbBtn->setFixedSize(QSize(275,60));
    fbBtn->setObjectName("1");
    fbBtn->setToolTip("View Facebook statistics");
    fbBtn->setIcon(QIcon(":/resources/facebook.png"));
    fbBtn->setIconSize(QSize(30,30));
    fbBtn->setText("  Facebook username\n  E-mail");
    fbBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    igBtn->setFixedSize(QSize(275,60));
    igBtn->setObjectName("2");
    igBtn->setToolTip("View Instagram statistics");
    igBtn->setIcon(QIcon(":/resources/instagram.png"));
    igBtn->setIconSize(QSize(30,30));
    igBtn->setText("  Instagram username\n  E-mail");
    igBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ytBtn->setFixedSize(QSize(275,60));
    ytBtn->setObjectName("3");
    ytBtn->setToolTip("View YouTube statistics");
    ytBtn->setIcon(QIcon(":/resources/youtube.png"));
    ytBtn->setIconSize(QSize(30,30));
    ytBtn->setText("  YouTube username\n  E-mail");
    ytBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    accountsLyt->setMargin(3);
    mainLyt->setSpacing(0);
    mainLyt->setMargin(0);

    accountsLbl->setMargin(8);
    statsLbl->setMargin(8);

    hLine->setFixedWidth(allaccountsBtn->width()+accountsLyt->margin());

    hLine->setFixedHeight(1);
    hLine->setObjectName("line");
    hLine->setFrameShape(QFrame::HLine);
    hLine->setFrameShadow(QFrame::Sunken);

    vLine->setFixedWidth(1);
    vLine->setObjectName("line");
    vLine->setFrameShape(QFrame::VLine);
    vLine->setFrameShadow(QFrame::Sunken);
}

void GraphsWindow::accountBtnClick(){
    allaccountsBtn->setStyleSheet("background-color: white;");
    allaccountsBtn->setDown(false);
    fbBtn->setStyleSheet("background-color: white;");
    fbBtn->setDown(false);
    igBtn->setStyleSheet("background-color: white;");
    igBtn->setDown(false);
    ytBtn->setStyleSheet("background-color: white;");
    ytBtn->setDown(false);

    QToolButton *senderBtn=qobject_cast<QToolButton*>(sender());
    senderBtn->setStyleSheet("background-color: rgba(60,60,60, 0.3);");
    senderBtn->setDown(true);

    // richiama statistiche account selezionato
    fillStatsLyt((senderBtn->objectName()).toInt());
}

void GraphsWindow::fillStatsLyt(int s){
    switch(s){
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    }

}


