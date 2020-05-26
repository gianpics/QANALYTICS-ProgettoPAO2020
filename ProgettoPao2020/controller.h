#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "landingwindow.h"
#include "graphswindow.h"
#include "model.h"
#include <QObject>


class Controller : public QObject
{
    Q_OBJECT

private:
    Model* model;
    LandingWindow* lw;
    GraphsWindow* gw;

public:
    explicit Controller(Model* model, QObject *parent = nullptr);
    void setView(LandingWindow* _lw);
    void setView(GraphsWindow* _gw);
    void fillStatsLyt(GraphsWindow*,QVBoxLayout*,QString);
    static void eraseLayout(QLayout*);

public slots:
    static void fillGraphsLyt(GraphsWindow*,QVBoxLayout*,QString);
signals:

};

#endif // CONTROLLER_H
