#include "qinfodialog.h"

QInfoDialog::QInfoDialog(QWidget *parent):QDialog(parent)
{
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    setWindowTitle("About "+settings.value("app/title").toString());
    setFixedSize(400,200);
    move(parent->geometry().center() - rect().center());
    QHBoxLayout* mainLyt = new QHBoxLayout();
    mainLyt->setAlignment(Qt::AlignVCenter);

    //Logo
    QLabel *lbl = new QLabel();
    QPixmap image(":/resources/youtube.png");
    image = image.scaled(80,80,Qt::IgnoreAspectRatio);
    lbl->setPixmap(image);
    lbl->setFixedSize(100,100);
    lbl->setMargin(5);
    lbl->setAlignment(Qt::AlignCenter);
    mainLyt->addWidget(lbl);

    //Vertical Line
    QFrame *vLine = new QFrame();
    mainLyt->addWidget(vLine);
    vLine->setAccessibleName("vline");
    vLine->setFrameShape(QFrame::VLine);
    vLine->setFrameShadow(QFrame::Sunken);
    //Text
    QString text=   "<p><b>"+settings.value("app/title").toString()+" "+settings.value("app/version").toString()+"</b></p>"+
                    "<p>Based on Qt "+settings.value("app/qt_version").toString()+"</p>"+
                    "<p>Built on "+settings.value("app/last_build").toString()+"</p>"+
                    "<p>"+settings.value("app/copyleft").toString()+"</p>"+
                    "<p>"+settings.value("app/description").toString()+"<p>";

    QLabel *textLbl = new QLabel();
    textLbl->setText(text);
    textLbl->setWordWrap(true);
    textLbl->setTextFormat(Qt::RichText);
    textLbl->setMargin(5);
    textLbl->setAlignment(Qt::AlignVCenter);
    textLbl->setFixedHeight(160);
    mainLyt->addWidget(textLbl);
    setLayout(mainLyt);
}
