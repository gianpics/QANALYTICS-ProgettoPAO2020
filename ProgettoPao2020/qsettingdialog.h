#ifndef QSETTINGDIALOG_H
#define QSETTINGDIALOG_H
#include <QDialog>
#include <QSettings>
#include <QWidget>

class qsettingdialog : public QDialog
{
    Q_OBJECT
public:
    qsettingdialog(QWidget *parent);
};

#endif // QSETTINGDIALOG_H
