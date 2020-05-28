#ifndef QINFODIALOG_H
#define QINFODIALOG_H
#include <QDialog>
#include <QSettings>
#include <QLayout>
#include <QLabel>
#include <QListWidget>

class QInfoDialog : public QDialog
{
    Q_OBJECT
public:
    QInfoDialog(QWidget *parent);
};

#endif // QINFODIALOG_H
