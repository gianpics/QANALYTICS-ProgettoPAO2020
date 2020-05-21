#ifndef LANDINGWINDOW_H
#define LANDINGWINDOW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QSettings>
#include <QHBoxLayout>
#include <QVBoxLayout>

class LandingWindow: public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *mainLyt;
    QHBoxLayout *buttonsLyt;
    QVBoxLayout *creatorsLyt;
    QPushButton *infoBtn, *settingBtn;
    QLineEdit *searchTxt;
    QListView *creatorsLvw;

    void setWidgets();
    void setWinStyle();

private slots:
    void settingBtnClick();
    void infoBtnClick();
    void searchTxtChanged(const QString&);

public:
    LandingWindow();


};

#endif // LANDINGWINDOW_H
