#ifndef GRAPHSWINDOW_H
#define GRAPHSWINDOW_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListView>
#include <QLabel>
#include <QSplitter>

class GraphsWindow: public QWidget
{
    Q_OBJECT

private:
    QHBoxLayout *mainLyt;
    QVBoxLayout *sideLyt, *graphsLyt;
    QListView *accountsLvw, *statsLvw, *graphsLvw;
    QLabel *accountsLbl, *statsLbl;
    QFrame *hLine, *vLine;

    void setWidget();
    void setSideWidget();
    void setGraphsWidget();
    void setWinStyle();

public:
    GraphsWindow();
};

#endif // GRAPHSWINDOW_H
