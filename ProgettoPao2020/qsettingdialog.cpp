#include "qsettingdialog.h"

qsettingdialog::qsettingdialog(QWidget *parent):QDialog(parent)
{
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    setWindowTitle("About "+settings.value("app/title").toString());
    setFixedSize(400,200);
    move(parent->geometry().center() - rect().center());
}
