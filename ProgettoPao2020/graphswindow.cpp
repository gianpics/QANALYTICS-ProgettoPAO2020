#include "graphswindow.h"
#include <QFile>
#include <QDebug>
#include <QCloseEvent>
#include <QPushButton>
#include "controller.h"

GraphsWindow::GraphsWindow(Controller* c): controller(c)
{
    setWidget();

    setWinStyle();

    // visualizza statistiche del primo account nel layout
    //emit qobject_cast<QToolButton*>(accountsLyt->itemAt(0)->widget())->click();
}

// chiede di visualizzare la landingwindow e termina la finestra
void GraphsWindow::closeEvent(QCloseEvent *event)
{
    controller->restoreLandingWindow();
    event->accept();
}

void GraphsWindow::setBtnType(QToolButton *btn, int type, QString email, QString username, int id)
{
    // account_type{youtube = 0, facebook = 1, instagram = 2};

    btn->setIconSize(QSize(30,30));
    btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    connect(btn, SIGNAL(clicked()), controller, SLOT(accountBtnClick()));
    btn->setText("  "+username+"\n  "+email);
    btn->setObjectName(QString::number(id));

    switch(type){
        case 0:
            // youtube
            btn->setIcon(QIcon(":/resources/youtube.png"));
            btn->setToolTip("View YouTube statistics");
            break;
        case 1:
            // facebook
            btn->setIcon(QIcon(":/resources/facebook.png"));
            btn->setToolTip("View Facebook statistics");
            break;
        case 2:
            // instagram
            btn->setIcon(QIcon(":/resources/instagram.png"));
            btn->setToolTip("View Instagram statistics");
            break;
        default:
            // allaccounts
            btn->setText("  All accounts");
            btn->setIcon(QIcon(":/resources/users.png"));
            btn->setToolTip("View all accounts statistics");
            break;
    }
}

void GraphsWindow::eraseLayout(QLayout* layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
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

    insertAccountButtons();

    sideLyt->addWidget(accountsLbl);
    sideLyt->addLayout(accountsLyt);
    sideLyt->addWidget(hLine);
    sideLyt->addWidget(statsLbl);
    sideLyt->addLayout(statsLyt);
}

void GraphsWindow::setGraphsWidget()
{
    graphsLyt=new QVBoxLayout;
    graphsLyt->setAlignment(Qt::AlignRight);
}

void GraphsWindow::setWinStyle()
{
    // imposta foglio di stile
    QFile file(":/resources/stylesheet.css");
    file.open(QFile::ReadOnly);
    setStyleSheet(QLatin1String(file.readAll()));

    // finestra
    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            size(),
            qApp->desktop()->availableGeometry()
        )
    );

    // titolo finestra da nome creator
    setWindowTitle(controller->getCreatorName()+"'s stats");

    accountsLbl->setText("Accounts");
    accountsLbl->setObjectName("section");
    statsLbl->setText("Stats");
    statsLbl->setObjectName("section");

    sideLyt->setAlignment(Qt::AlignTop);
    accountsLyt->setAlignment(Qt::AlignTop);
    statsLyt->setAlignment(Qt::AlignLeft);

    accountsLyt->setMargin(3);
    statsLyt->setMargin(3);
    mainLyt->setSpacing(0);
    mainLyt->setMargin(0);

    accountsLbl->setMargin(8);
    statsLbl->setMargin(8);

    hLine->setFixedWidth(278);

    hLine->setFixedHeight(1);
    hLine->setObjectName("line");
    hLine->setFrameShape(QFrame::HLine);
    hLine->setFrameShadow(QFrame::Sunken);

    vLine->setFixedWidth(1);
    vLine->setObjectName("line");
    vLine->setFrameShape(QFrame::VLine);
    vLine->setFrameShadow(QFrame::Sunken);
}

void GraphsWindow::insertAccountButtons()
{
    int nAccounts=controller->getAccountsNumber();
    account_type type;
    QString email, username;
    int id;
    QToolButton* btn;

    btn=new QToolButton;
    // aggiunge allaccount se esiste il creator ne ha più di uno
    if(nAccounts>1)
    {
        setBtnType(btn, -1, "", "", -1);
        accountsLyt->addWidget(btn);
     }

    for(int i=0; i<nAccounts; i++)
    {
        // tipo, email, id, username
        type=controller->getAccountType(i);
        email=controller->getAccountEmail(i);
        username=controller->getAccountUsername(i);
        id=controller->getAccountId(i);

        btn=new QToolButton;
        setBtnType(btn, type, email, username, id);
        accountsLyt->addWidget(btn);
    }
}

// cambia stylesheet dopo avere selezionato un account
void GraphsWindow::updateAccountButtonsStyle(QString objname){

    QToolButton *btn;
    for(int i=0; i<accountsLyt->count(); i++)
    {
        btn=qobject_cast<QToolButton*>(accountsLyt->itemAt(i)->widget());
        if(btn->objectName() == objname){
            btn->setStyleSheet("background-color: rgba(60,60,60, 0.3);");
            btn->setDown(true);
        }else{
            btn->setStyleSheet("background-color: white;");
            btn->setDown(false);
        }
    }
}
// cambia stylesheet dopo avere selezionato una stats
void GraphsWindow::updateStatsButtonsStyle(QString objname)
{
    QPushButton *btn;
    for(int i=0; i<statsLyt->count(); i++)
    {
        btn=qobject_cast<QPushButton*>(statsLyt->itemAt(i)->widget());
        if(btn->objectName() == objname){
            btn->setStyleSheet("background-color: rgba(60,60,60, 0.3);");
            btn->setDown(true);
        }else{
            btn->setStyleSheet("background-color: white;");
            btn->setDown(false);
        }
    }
}

void GraphsWindow::insertStatsButtons(QStringList *stats, QString accountId)
{
    eraseLayout(statsLyt);
    QPushButton* btn;
    for(auto a : *stats){
        btn=new QPushButton;
        btn->setObjectName(accountId);
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        if(a.compare("followers")==0){
            btn->setText("Followers");
            btn->setToolTip("Compare socials' followers");
            //connect(btn, SIGNAL(clicked()), controller, SLOT(statsBtnClick()));
        }else if(a.compare("impression")==0){
            btn->setText("Impressions");
            btn->setToolTip("Compare socials' impression");
        }else if(a.compare("coverage")==0){
            btn->setText("Coverage");
            btn->setToolTip("Compare socials' coverage");
        }else if(a.compare("likes")==0){
            btn->setText("Likes");
            btn->setToolTip("Compare socials likes");
        }else if(a.compare("following")==0){
            btn->setText("Following");
            btn->setToolTip("View following monthly growth");
        }else if(a.compare("donators")==0){
            btn->setText("Donators");
            btn->setToolTip("View donators monthly growth");
        }else if(a.compare("totalviews")==0){
            btn->setText("Total Views");
            btn->setToolTip("View total views monthly growth");
        }else if(a.compare("avgwatchtime")==0){
            btn->setText("Average Watch Time");
            btn->setToolTip("View average watch time monthly growth");
        }else if(a.compare("pagelikes")==0){
            btn->setText("Page likes");
            btn->setToolTip("View page's likes monthly growth");
        }
        statsLyt->addWidget(btn);
    }
    delete stats;
}



