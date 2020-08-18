#include <QObject>
#include <QDebug>
#include <QSettings>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QRegularExpression>
#include <QDesktopWidget>
#include "landingwindow.h"
#include "controller.h"

LandingWindow::LandingWindow(Controller* c): controller(c)
{
    // carica titolo finestra dal file config
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    setWindowTitle(settings.value("app/title").toString());
    setWindowIcon(QIcon(settings.value("app/logo").toString()));

    // spawn widget
    setWidgets();

    setWinStyle();
    //centra la finestra
    adjustSize();
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    setFixedSize(size());
}

void LandingWindow::setWidgets(){
    // Layout buttons
    buttonsLyt=new QHBoxLayout;

    // btn import
    importBtn=new QPushButton;
    connect(importBtn, SIGNAL(clicked()), controller, SLOT(importBtnClick()));
    // btn export
    exportBtn=new QPushButton;
    connect(exportBtn, SIGNAL(clicked()), controller, SLOT(exportBtnClick()));
    // btn info
    infoBtn=new QPushButton;
    connect(infoBtn, SIGNAL(clicked()), controller, SLOT(infoBtnClick()));

    // inserimento buttons in layout superiore
    buttonsLyt->addWidget(importBtn);
    buttonsLyt->addWidget(exportBtn);
    buttonsLyt->addWidget(infoBtn);

    // Layout creators
    creatorsLyt=new QVBoxLayout;
    // search box
    searchTxt=new QLineEdit;
    connect(searchTxt,SIGNAL(textChanged(const QString&)), this, SLOT(searchTxtChanged(const QString&)));
    // HLine
    hLine=new QFrame;
    // inserimento widget in layout creator
    creatorsLyt->addWidget(searchTxt);
    creatorsLyt->addWidget(hLine);

    fillCreatorsLyt();

    mainLyt=new QHBoxLayout(this);
    mainLyt->addLayout(creatorsLyt);
    mainLyt->addLayout(buttonsLyt);

}

void LandingWindow::setWinStyle(){
    QFile file(":/resources/stylesheet.css");
    file.open(QFile::ReadOnly);
    setStyleSheet(QLatin1String(file.readAll()));

    importBtn->setIcon(QIcon(":/resources/down.png"));
    importBtn->setToolTip("Import data");
    importBtn->setAccessibleName("sidebtn");
    importBtn->setFixedSize(QSize(25,25));

    exportBtn->setIcon(QIcon(":/resources/up.png"));
    exportBtn->setToolTip("Export data");
    exportBtn->setAccessibleName("sidebtn");
    exportBtn->setFixedSize(QSize(25,25));

    infoBtn->setIcon(QIcon(":/resources/info.png"));
    infoBtn->setToolTip("Information");
    infoBtn->setAccessibleName("sidebtn");
    infoBtn->setFixedSize(QSize(25,25));

    buttonsLyt->setAlignment(Qt::AlignTop);

    searchTxt->setPlaceholderText("Search");

    hLine->setAccessibleName("hline");
    hLine->setFrameShape(QFrame::HLine);
    hLine->setFrameShadow(QFrame::Sunken);

    creatorsLyt->setAlignment(Qt::AlignTop);
    creatorsLyt->setContentsMargins(90, 5, 0, 0);
}

void LandingWindow::fillCreatorsLyt()
{
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    controller->retrieveCreators();
    QToolButton* btn;
    const Creator* c;

    for(int i=0; i<controller->getCreatorsNumber(); i++)
    {
        c=controller->getCreatorAt(i);
        btn=new QToolButton;
        btn->setIcon(QIcon(":/resources/user.png"));
        btn->setText(" "+QString::fromStdString(" "+c->getFullName())+"\n  "+QString::fromStdString(c->getSSN()));
        // text format
        btn->setToolTip("Load "+QString::fromStdString(c->getFullName())+" information");
        btn->setIconSize(QSize(40,40));
        btn->setObjectName(QString::fromStdString(c->getSSN()));
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        connect(btn, SIGNAL(clicked()), controller, SLOT(creatorBtnClick()));
        creatorsLyt->addWidget(btn);
    }
}

void LandingWindow::searchTxtChanged(const QString &text){
    // regex su attributo Text (sia nome che SSN) dei ToolButton di CreatorsLyt
    QRegularExpression pattern("\\w*"+text+"\\w*",QRegularExpression::CaseInsensitiveOption);

    // cicla ogni tasto e visualizzalo se il regex dà risultati
    QToolButton* btn;
    for(int i=0; i<creatorsLyt->count(); i++)
    {
        // controllo tipo (creatorsLyt contiene anche QLineEdit e QFrame)
        if((btn=qobject_cast<QToolButton*>(creatorsLyt->itemAt(i)->widget())))
        {
            if(pattern.match(btn->text()).hasMatch())
                btn->show();
            else
                btn->hide();
        }
    }
}
