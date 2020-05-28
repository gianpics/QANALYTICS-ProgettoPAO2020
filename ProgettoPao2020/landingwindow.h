#ifndef LANDINGWINDOW_H
#define LANDINGWINDOW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSettings>
#include <QToolBar>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Controller;

class LandingWindow: public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *mainLyt, *creatorsLyt;
    QHBoxLayout *buttonsLyt;
    QPushButton *infoBtn, *settingBtn;
    QLineEdit *searchTxt;
    QFrame *hLine;
    Controller* controller;

    void setWidgets();
    void setWinStyle();
    void fillCreatorsLyt();

private slots:
    void searchTxtChanged(const QString&);

public:
    LandingWindow(Controller*);

};

#endif // LANDINGWINDOW_H
