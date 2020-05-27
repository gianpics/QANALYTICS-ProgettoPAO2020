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

    Controller *controller;

    void setWidget();
    void setSideWidget();
    void setGraphsWidget();
    void setWinStyle();
    void insertAccountButtons();
    void closeEvent(QCloseEvent *event);
    void setBtnType(QToolButton *btn, int type, QString email, QString username, int id);
    static void eraseLayout(QLayout* layout);

private slots:

public:
    GraphsWindow(Controller* c);
    void updateAccountButtonsStyle(QString objname);
    void updateStatsButtonsStyle(QString objname);
    void insertStatsButtons(QStringList* stats, QString accountId);
};

#endif // GRAPHSWINDOW_H
