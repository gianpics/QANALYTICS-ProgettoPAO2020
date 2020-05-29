#ifndef QSETTINGDIALOG_H
#define QSETTINGDIALOG_H
#include <QDialog>
#include <QSettings>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

class QSettingDialog : public QDialog
{
    Q_OBJECT
private:
    QVBoxLayout *mainLyt;
    QLabel* datapathLbl;
    QPushButton *importBtn, *exportBtn;

    QHBoxLayout *topLyt, *botLyt;

private slots:
    void importBtnClick();
    void exportBtnClick();

public:
    QSettingDialog(QWidget *parent);

};

#endif // QSETTINGDIALOG_H
