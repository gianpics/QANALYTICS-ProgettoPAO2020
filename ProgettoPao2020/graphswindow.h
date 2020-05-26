#ifndef GRAPHSWINDOW_H
#define GRAPHSWINDOW_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QToolButton>

class Controller;

class GraphsWindow: public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout *mainLyt;
    QVBoxLayout *sideLyt, *graphsLyt, *accountsLyt, *statsLyt;
    QLabel *accountsLbl, *statsLbl;
    QFrame *hLine, *vLine;
    QToolButton *allaccountsBtn, *fbBtn, *igBtn, *ytBtn;

    Controller *controller;

    void setWidget();
    void setSideWidget();
    void setGraphsWidget();
    void setWinStyle();


private slots:
    void accountBtnClick();
    void statsBtnClick();

public:
    GraphsWindow(Controller* c);
};

#endif // GRAPHSWINDOW_H
