#include "controller.h"

Controller::Controller(Model *m, QObject *parent) : QObject(parent), model(m), lw(nullptr), gw(nullptr){}

void Controller::setView(LandingWindow *_lw)
{
    lw=_lw;
}
