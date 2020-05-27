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

    //emit allaccountsBtn->clicked();
}

// chiede di visualizzare la landingwindow e termina la finestra
void GraphsWindow::closeEvent(QCloseEvent *event)
{
    controller->restoreLandingWindow();
    event->accept();
}

void GraphsWindow::setAccountBtnType(QToolButton *btn, int type, QString email, QString username, int id)
{
    // account_type{youtube = 0, facebook = 1, instagram = 2};

    btn->setFixedSize(QSize(275,50));
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

QString GraphsWindow::enumToString(stats_type s) const
{
    switch(s){
        case impressions:
            return QString::fromStdString("impressions");
        case coverage:
            return QString::fromStdString("coverage");
        case likes:
            return QString::fromStdString("likes");
        case followers:
            return QString::fromStdString("followers");
        case following:
            return QString::fromStdString("following");
        case donators:
            return QString::fromStdString("donators");
        case totalviews:
            return QString::fromStdString("totalviews");
        case avgwatchtime:
            return QString::fromStdString("avgwatchtime");
        case pagelikes:
            return QString::fromStdString("pagelikes");
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

    insertAccountBtn();

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
    //qInfo()<<"style: "<<QLatin1String(file.readAll());

    // titolo finestra da nome creator
    setWindowTitle(controller->getCreatorName()+"'s stats");
    setMinimumSize(QSize(1000,700));

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

void GraphsWindow::insertAccountBtn()
{
    int nAccounts=controller->getAccountsNumber();
    account_type type;
    QString email, username;
    int id;
    QToolButton* btn;

    // aggiunge allaccount
    btn=new QToolButton;
    setAccountBtnType(btn, -1, "", "", -1);
    allaccountsBtn = btn;
    accountsLyt->addWidget(btn);

    for(int i=0; i<nAccounts; i++)
    {
        // tipo, email, id, username
        type=controller->getAccountType(i);
        email=controller->getAccountEmail(i);
        username=controller->getAccountUsername(i);
        id=controller->getAccountId(i);

        btn=new QToolButton;
        setAccountBtnType(btn, type, email, username, id);
        accountsLyt->addWidget(btn);
    }
}

// cambia stylesheet dopo avere selezionato un account
void GraphsWindow::updateAccountBtnStyle(QString objname){

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
void GraphsWindow::updateStatsBtnStyle(QString objname)
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

void GraphsWindow::insertStatsBtn(std::vector<stats_type>* stats, QString accountId)
{
    eraseLayout(statsLyt);
    eraseLayout(graphsLyt);
    //mi salvo l'id dell'account selezionato
    selectedAccountId = accountId;
    QPushButton* btn;
    for(auto stat : *stats){
        btn=new QPushButton;
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), controller, SLOT(statsBtnClick()));
        btn->setObjectName(enumToString(stat));
        switch(stat){
            case impressions:
                btn->setText("Impressions");
                btn->setToolTip("Compare socials' impressions");
                break;
            case coverage:
                btn->setText("Coverage");
                btn->setToolTip("Compare socials' coverage");
                break;
            case likes:
                btn->setText("Likes");
                btn->setToolTip("Compare socials likes");
                break;
            case followers:
                btn->setText("Followers");
                btn->setToolTip("Compare socials' followers");
                break;
            case following:
                btn->setText("Following");
                btn->setToolTip("View following monthly growth");
                break;
            case donators:
                btn->setText("Donators");
                btn->setToolTip("View donators monthly growth");
                break;
            case totalviews:
                btn->setText("Total Views");
                btn->setToolTip("View total views monthly growth");
                break;
            case avgwatchtime:
                btn->setText("Average Watch Time");
                btn->setToolTip("View average watch time monthly growth");
                break;
            case pagelikes:
                btn->setText("Page Likes");
                btn->setToolTip("View page's likes monthly growth");
                break;
        }
        statsLyt->addWidget(btn);
    }
    delete stats;
}

void GraphsWindow::displayChart(QChart *chart)
{
    eraseLayout(graphsLyt);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    graphsLyt->addWidget(chartView);
}

QString GraphsWindow::getSelectedAccountId() const
{
    return selectedAccountId;
}



