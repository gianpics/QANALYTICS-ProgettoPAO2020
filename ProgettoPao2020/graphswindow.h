#ifndef GRAPHSWINDOW_H
#define GRAPHSWINDOW_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <QtCharts>
#include <vector>

class Controller;
enum stats_type{ impressions = 0, coverage = 1, likes = 2, followers = 3, following = 4, donators = 5, totalviews = 6, avgwatchtime = 7, pagelikes = 8};
class GraphsWindow: public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout *mainLyt;
    QVBoxLayout *sideLyt, *graphsLyt, *accountsLyt, *statsLyt;
    QLabel *accountsLbl, *statsLbl;
    QFrame *hLine, *vLine;
    QToolButton *allaccountsBtn;
    QString selectedAccountId;

    Controller *controller;

    void setWidget();
    void setSideWidget();
    void setGraphsWidget();
    void setWinStyle();
    void closeEvent(QCloseEvent *event);
    void insertAccountBtn();
    void setAccountBtnType(QToolButton *btn, int type, QString email, QString username, int id);
    static void eraseLayout(QLayout* layout);
    QString enumToString(stats_type) const;

public:
    GraphsWindow(Controller* c);
    void updateAccountBtnStyle(QString objname);
    void updateStatsBtnStyle(QString objname);
    void insertStatsBtn(std::vector<stats_type>* stats, QString accountId);
    void displayChart(QChart * chart);
    QString getSelectedAccountId() const;
};

#endif // GRAPHSWINDOW_H
