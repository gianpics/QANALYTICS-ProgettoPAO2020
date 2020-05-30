#include "qsettingdialog.h"
#include "controller.h"
#include <QDialogButtonBox>
#include <QDebug>
#include <QFile>
#include <QFileDialog>


QSettingDialog::QSettingDialog(QWidget *parent):QDialog(parent)
{

    setWindowTitle("Settings");
    setWindowIcon(QIcon(":/resources/gear.png"));
    setFixedSize(270,100);
    move(parent->geometry().center() - rect().center());
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);

    QString datapath=settings.value("app/datapath").toString();
    datapathLbl=new QLabel;

    datapathLbl->setText(datapath.isEmpty() ? "No path set." : datapath);

    importBtn=new QPushButton;
    importBtn->setText("Import data");
    importBtn->setToolTip("Choose file data to view");
    importBtn->setAccessibleDescription("settingbtn");
    connect(importBtn, SIGNAL(clicked()), this, SLOT(importBtnClick()));

    exportBtn=new QPushButton;
    exportBtn->setText("Store data");
    exportBtn->setToolTip("Choose file path to store data");
    exportBtn->setAccessibleDescription("settingbtn");
    connect(exportBtn, SIGNAL(clicked()), this, SLOT(exportBtnClick()));

    topLyt = new QHBoxLayout;
    topLyt->setAlignment(Qt::AlignTop);
    topLyt->addWidget(importBtn);
    topLyt->addWidget(exportBtn);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);

    botLyt=new QHBoxLayout;
    botLyt->setAlignment(Qt::AlignRight);
    botLyt->setAlignment(Qt::AlignBottom);
    botLyt->addWidget(buttonBox);


    mainLyt=new QVBoxLayout(this);
    mainLyt->setAlignment(Qt::AlignTop);
    mainLyt->addWidget(datapathLbl);
    mainLyt->addLayout(topLyt);
    mainLyt->addLayout(botLyt);
}

void QSettingDialog::importBtnClick()
{
    QString path=QFileDialog::getOpenFileName(this, "Choose file data to import","","Text (*.txt)");
    datapathLbl->setText(path);

    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    settings.setValue("app/datapath",path);
}

void QSettingDialog::exportBtnClick()
{
    QString path=QFileDialog::getSaveFileName(this, "Choose file data to import","","Text (*.txt)");
    // lancia export attraverso il controller


}
