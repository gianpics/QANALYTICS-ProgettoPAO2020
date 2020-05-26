#ifndef GRAPHSWINDOW_H
#define GRAPHSWINDOW_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QToolButton>
#include "controller.h"

class Controller;

class GraphsWindow: public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout *mainLyt;
    QVBoxLayout *sideLyt, *graphsLyt, *accountsLyt, *statsLyt;
    QLabel *accountsLbl, *statsLbl;
    QFrame *hLine, *vLine;
    QToolButton *allaccountsBtn;

    Controller *controller;

    void setWidget();
    void setSideWidget();
    void setGraphsWidget();
    void setWinStyle();
    void fillAccountButtons();
    void closeEvent(QCloseEvent *event);
    void setBtnType(QToolButton *btn, int type, QString email, QString username, int id);

private slots:
    void statsBtnClick();

public:
    GraphsWindow(Controller* c);
    void updateAccountButtons(QString objname);
};

#endif // GRAPHSWINDOW_H
