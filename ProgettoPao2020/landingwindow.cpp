#include <QObject>
#include <QDebug>
#include <QSettings>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QRegularExpression>
#include "landingwindow.h"
#include "controller.h"

LandingWindow::LandingWindow(Controller* c): controller(c)
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
    connect(settingBtn,SIGNAL(clicked()), controller, SLOT(settingBtnClick()));

    // btn info
    infoBtn=new QPushButton;
    connect(infoBtn, SIGNAL(clicked()), controller, SLOT(infoBtnClick()));

    // inserimento buttons in layout superiore
    buttonsLyt=new QHBoxLayout;
    buttonsLyt->addWidget(infoBtn);
    buttonsLyt->addWidget(settingBtn);


     // - lower layout

    // search box
    searchTxt=new QLineEdit;
    connect(searchTxt,SIGNAL(textChanged(const QString&)), this, SLOT(searchTxtChanged(const QString&)));

    // line
    hLine=new QFrame;


    // inserimento in layout inferiore
    creatorsLyt=new QVBoxLayout;
    creatorsLyt->addWidget(searchTxt);
    creatorsLyt->addWidget(hLine);
    fillCreatorsLyt();

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
    setGeometry(
        QStyle::alignedRect(
            Qt::LayoutDirection::LeftToRight,
            Qt::AlignCenter,
            size(),
            qApp->desktop()->availableGeometry()
        )
    );

    setFixedSize(size());

    // layout pulsanti
    settingBtn->setIcon(QIcon(":/resources/gear.png"));
    settingBtn->setToolTip("Settings");
    settingBtn->setFixedSize(QSize(24,24));

    infoBtn->setIcon(QIcon(":/resources/info.png"));
    infoBtn->setToolTip("Information");
    infoBtn->setFixedSize(QSize(24,24));

    buttonsLyt->setAlignment(Qt::AlignRight);



    // layout creators
    searchTxt->setPlaceholderText("Search");

    hLine->setFixedHeight(1);
    hLine->setObjectName("hline");
    hLine->setFrameShape(QFrame::HLine);
    hLine->setFrameShadow(QFrame::Sunken);

    creatorsLyt->setAlignment(Qt::AlignCenter);

}

void LandingWindow::fillCreatorsLyt()
{
    CreatorList* creators=controller->retrieveCreators();
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
