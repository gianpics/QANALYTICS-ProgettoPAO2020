#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "landingwindow.h"
#include "graphswindow.h"
#include "model.h"
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(Model* model, QObject *parent = nullptr);
    void setView(LandingWindow* lw);
signals:

private:
    Model* model;
    LandingWindow* lw;
    GraphsWindow* gw;
};

#endif // CONTROLLER_H
