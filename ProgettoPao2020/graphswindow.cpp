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

void GraphsWindow::setAccountBtnType(QToolButton *btn, int type, QString email, QString username, int id)
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

   return "";
}

void GraphsWindow::setWidget()
{
    setTopLayout();

    setSideWidget();

    vLine=new QFrame;

    setGraphsWidget();

    mainLyt=new QHBoxLayout;
    mainLyt->addLayout(sideLyt);
    mainLyt->addWidget(vLine);
    mainLyt->addLayout(graphsLyt);

    outerLyt=new QVBoxLayout(this);
    outerLyt->setAlignment(Qt::AlignTop);
    outerLyt->setMargin(0);
    outerLyt->addLayout(topLyt);
    outerLyt->addLayout(mainLyt);
}

void GraphsWindow::setTopLayout()
{
    // frecciaback, export, info

    backBtn=new QPushButton;
    backBtn->setIcon(QIcon(":/resources/back.png"));
    backBtn->setToolTip("Go back");
    backBtn->setFixedSize(QSize(25,25));
    connect(backBtn, SIGNAL(clicked()), this, SLOT(close()));

    exportBtn=new QPushButton;
    exportBtn->setIcon(QIcon(":/resources/save.png"));
    exportBtn->setToolTip("Export chart");
    exportBtn->setFixedSize(QSize(25,25));
    connect(exportBtn, SIGNAL(clicked()), controller, SLOT(exportBtnClick())); // disabilita quando no chart

    infoBtn=new QPushButton;
    infoBtn->setIcon(QIcon(":/resources/info.png"));
    infoBtn->setToolTip("Information");
    infoBtn->setFixedSize(QSize(25,25));
    connect(infoBtn, SIGNAL(clicked()), this, SLOT());

    topLyt=new QHBoxLayout;
    topLyt->setAlignment(Qt::AlignLeft);
    topLyt->setContentsMargins(2,0,0,0);
    topLyt->addWidget(backBtn);
    topLyt->addWidget(exportBtn);
    topLyt->addWidget(infoBtn);
}

void GraphsWindow::setSideWidget()
{
    infoLbl=new QLabel;
    creatorInfoLbl=new QLabel;
    accountsLbl=new QLabel;
    accountsLyt=new QVBoxLayout;
    hLineA=new QFrame;
    hLineB=new QFrame;
    statsLbl=new QLabel;
    statsLyt=new QVBoxLayout;
    sideLyt=new QVBoxLayout;

    insertAccountBtn();

    sideLyt->addWidget(infoLbl);
    sideLyt->addWidget(creatorInfoLbl);
    sideLyt->addWidget(hLineA);
    sideLyt->addWidget(accountsLbl);
    sideLyt->addLayout(accountsLyt);
    sideLyt->addWidget(hLineB);
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
            Qt::LayoutDirection::LayoutDirectionAuto,
            Qt::AlignCenter,
            size(),
            qApp->desktop()->availableGeometry()
        )
    );

    // titolo finestra da nome creator
    setWindowTitle(controller->getCreatorName()+"'s stats");

    infoLbl->setText("Creator");
    infoLbl->setObjectName("section");
    creatorInfoLbl->setText(controller->getCreatorInfo());
    creatorInfoLbl->setTextFormat(Qt::RichText);
    accountsLbl->setText("Accounts");
    accountsLbl->setObjectName("section");
    statsLbl->setText("Stats");
    statsLbl->setObjectName("section");

    sideLyt->setAlignment(Qt::AlignTop);
    accountsLyt->setAlignment(Qt::AlignTop);
    statsLyt->setAlignment(Qt::AlignLeft);

    statsLyt->setMargin(3);
    accountsLyt->setMargin(3);
    mainLyt->setSpacing(0);
    mainLyt->setMargin(0);

    infoLbl->setFixedWidth(270);
    infoLbl->setMargin(8);
    creatorInfoLbl->setMargin(8);
    statsLbl->setMargin(8);
    accountsLbl->setMargin(8);


    hLineA->setFixedHeight(1);
    hLineA->setFixedWidth(281);

    hLineA->setFixedHeight(1);
    hLineA->setObjectName("line");
    hLineA->setFrameShape(QFrame::HLine);
    hLineA->setFrameShadow(QFrame::Sunken);

    hLineB->setFixedHeight(1);
    hLineB->setFixedWidth(281);

    hLineB->setFixedHeight(1);
    hLineB->setObjectName("line");
    hLineB->setFrameShape(QFrame::HLine);
    hLineB->setFrameShadow(QFrame::Sunken);

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

    btn=new QToolButton;
  
    // aggiunge allaccount se esiste il creator ne ha più di uno
    if(nAccounts>1)
    {
        setAccountBtnType(btn, -1, "", "", -1);
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



