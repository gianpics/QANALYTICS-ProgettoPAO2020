#include "graphswindow.h"
#include <QFile>
#include <QDebug>
#include <QCloseEvent>
#include <QPushButton>

GraphsWindow::GraphsWindow(Controller* c): controller(c)
{
    setWidget();

    setWinStyle();

    emit allaccountsBtn->clicked();
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

    btn->setFixedSize(QSize(275,50));
    btn->setIconSize(QSize(30,30));
    btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    connect(btn, SIGNAL(clicked()), this, SLOT(Controller::accountBtnClick()));
    btn->setText("  "+username+"\n "+email);
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

    fillAccountButtons();

    sideLyt->addWidget(accountsLbl);
    sideLyt->addLayout(accountsLyt);
    accountsLyt->addWidget(allaccountsBtn);
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

void GraphsWindow::fillAccountButtons()
{
    int nAccounts=controller->getAccountsNumber();
    account_type type;
    QString email, username;
    int id;
    QToolButton* btn;

    // aggiunge allaccount
    btn=new QToolButton;
    setBtnType(btn, -1, "", "", -1);
    accountsLyt->addWidget(btn);

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

// cambia stylesheet del tasto selezionato
void GraphsWindow::updateAccountButtons(QString objname){

    // risetta tutti i pulsanti account a non selezionati
    QPushButton *btn;
    for(int i=0; i<accountsLyt->count(); i++)
    {
        btn=qobject_cast<QPushButton*>(statsLyt->itemAt(i)->widget());
        btn->setStyleSheet("background-color: white;");
        btn->setDown(false);
    }

    // aggiorna stile del pulsante account premuto
    QPushButton *senderBtn=accountsLyt->findChild<QPushButton*>(objname);
    senderBtn->setStyleSheet("background-color: rgba(60,60,60, 0.3);");
    senderBtn->setDown(true);
}

// richiede al controller di mostrare il grafico della statistica selezionata
// cambia stylesheet del tasto selezionato
void GraphsWindow::statsBtnClick()
{
    cazzo;
    QPushButton *btn;
    for(int i=0; i<statsLyt->count(); i++)
    {
        btn=qobject_cast<QPushButton*>(statsLyt->itemAt(i)->widget());
        btn->setStyleSheet("background-color: white;");
        btn->setDown(false);
    }

    QPushButton *senderBtn=qobject_cast<QPushButton*>(sender());
    senderBtn->setStyleSheet("background-color: rgba(60,60,60, 0.3);");
    senderBtn->setDown(true);
    controller->fillGraphsLyt(this, graphsLyt, sender()->objectName());
}


