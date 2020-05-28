#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "landingwindow.h"
#include "graphswindow.h"
#include "model.h"
#include <QObject>
#include <vector>

class Controller : public QObject
{
    Q_OBJECT

private:
    Model* model;
    LandingWindow* lw;
    GraphsWindow* gw;
    stats_type stringToEnum(QString s) const;

public:
    explicit Controller(Model* model, QObject *parent = nullptr);
    void setView(LandingWindow* _lw);
    void setView(GraphsWindow* _gw);
    void fillStatsLyt(GraphsWindow*,QVBoxLayout*,QString);
    CreatorList* retrieveCreators();
    void launchCreatorGraphs(QString);
    void restoreLandingWindow();
    QString getCreatorName() const;
    int getAccountsNumber() const;
    QString getCreatorInfo() const;
    account_type getAccountType(int i) const;
    account_type getAccountTypeByid(int i) const;
    QString getAccountEmail(int i) const;
    QString getAccountUsername(int i) const;
    int getAccountId(int i) const;

public slots:
    void accountBtnClick();
    void statsBtnClick();
    void exportBtnClick();
};

#endif // CONTROLLER_H
