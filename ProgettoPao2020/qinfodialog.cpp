#include "qinfodialog.h"

QInfoDialog::QInfoDialog(QWidget *parent):QDialog(parent)
{
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    setWindowTitle("About "+settings.value("app/title").toString());
    setFixedSize(300,200);
    QHBoxLayout* mainLyt = new QHBoxLayout();
    QLabel *lbl = new QLabel();
    QPixmap image(":/resources/youtube.png");
    image = image.scaled(100,100,Qt::IgnoreAspectRatio);
    lbl->setPixmap(image);
    lbl->setFixedSize(100,100);
    mainLyt->addWidget(lbl);
    QString title(settings.value("app/title").toString()+" "+settings.value("app/version").toString());
    QString based("Based on Qt "+settings.value("app/qt_version").toString());
    QString build("Built on "+settings.value("app/last_build").toString());
    QString copyleft(settings.value("app/copyleft").toString());
    QString desc(settings.value("app/description").toString());
    QVBoxLayout* textLyt = new QVBoxLayout();
    textLyt->setAlignment(Qt::AlignRight);
    QLabel *l1 = new QLabel(title+"<hr>"+based+"<hr>"+build+"<hr>"+copyleft+"<hr>"+desc);
    l1->setTextFormat(Qt::RichText);
    l1->setFixedSize(150,200);
    textLyt->addWidget(l1);
    mainLyt->addLayout(textLyt);
    /*QListWidget *qlw=new QListWidget();
    qlw->addItem(settings.value("app/title").toString()+" "+settings.value("app/version").toString());
    qlw->addItem("Based on Qt "+settings.value("app/qt_version").toString());
    qlw->addItem("Built on "+settings.value("app/last_build").toString());
    qlw->setFixedSize(150, 200);
    mainLyt->addWidget(qlw);*/
    setLayout(mainLyt);
}
