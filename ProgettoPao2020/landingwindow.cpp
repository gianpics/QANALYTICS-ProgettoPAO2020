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
    // btn impostazioni
    importBtn=new QPushButton;
    connect(importBtn,SIGNAL(clicked()), controller, SLOT(settingBtnClick()));
    // btn info
    infoBtn=new QPushButton;
    connect(infoBtn, SIGNAL(clicked()), controller, SLOT(infoBtnClick()));
    //export
    exportBtn=new QPushButton;

    // inserimento buttons in layout superiore
    buttonsLyt->addWidget(infoBtn);
    buttonsLyt->addWidget(importBtn);
    buttonsLyt->addWidget(exportBtn);

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

    importBtn->setIcon(QIcon(":/resources/gear.png"));
    importBtn->setToolTip("Settings");
    importBtn->setAccessibleName("sidebtn");
    importBtn->setFixedSize(QSize(25,25));

    exportBtn->setIcon(QIcon(":/resources/info.png"));
    exportBtn->setToolTip("Information");
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
    CreatorList* creators = nullptr;
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    if(settings.value("app/datapath").toString().isEmpty()){
        emit exportBtn->click();
    }
    else{
         creators = controller->retrieveCreators();
         QToolButton* btn;

         for(int i=0; i<creators->size(); i++)
         {
             btn=new QToolButton;
             btn->setIcon(QIcon(":/resources/user.png"));
             btn->setText(" "+QString::fromStdString(" "+creators->operator[](i).getFullName())+"\n  "+QString::fromStdString(creators->operator[](i).getSSN()));
             // text format
             btn->setToolTip("Load "+QString::fromStdString(creators->operator[](i).getFullName())+" information");
             btn->setIconSize(QSize(40,40));
             btn->setObjectName(QString::fromStdString(creators->operator[](i).getSSN()));
             btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
             connect(btn, SIGNAL(clicked()), controller, SLOT(creatorBtnClick()));
             creatorsLyt->addWidget(btn);
         }
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
