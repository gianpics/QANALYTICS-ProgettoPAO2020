#ifndef GRAPHSWINDOW_H
#define GRAPHSWINDOW_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <QSplitter>

class GraphsWindow: public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout *mainLyt;
    QVBoxLayout *sideLyt, *graphsLyt, *accountsLyt, *statsLyt;
    QLabel *accountsLbl, *statsLbl;
    QFrame *hLine, *vLine;
    QToolButton *allaccountsBtn, *fbBtn, *igBtn, *ytBtn;

    void setWidget();
    void setSideWidget();
    void setGraphsWidget();
    void setWinStyle();
    void fillStatsLyt(int);

private slots:
    void accountBtnClick();

public:
    GraphsWindow();
};

#endif // GRAPHSWINDOW_H
