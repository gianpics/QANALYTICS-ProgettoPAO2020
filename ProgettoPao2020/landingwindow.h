#ifndef LANDINGWINDOW_H
#define LANDINGWINDOW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QListView>
#include <QSettings>

class LandingWindow: public QWidget
{
    Q_OBJECT
private:
    QPushButton *infoBtn, *settingBtn;
    QTextEdit *searchTxt;
    QListView *creatorsLvw;

    void setWidgets();
    void setStyle();


public:
    LandingWindow();

public slots:
    void settingBtnClick();
    void infoBtnClick();
};

#endif // LANDINGWINDOW_H
