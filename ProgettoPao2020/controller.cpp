#include "controller.h"
#include <QPushButton>
#include <QFile>

stats_type Controller::stringToEnum(QString s) const
{
    if(s.toStdString()=="impressions"){
        return impressions;
    }else if(s.toStdString()=="coverage"){
        return coverage;
    }else if(s.toStdString()=="likes"){
        return likes;
    }else if(s.toStdString()=="followers"){
        return followers;
    }else if(s.toStdString()=="following"){
        return following;
    }else if(s.toStdString()=="donators"){
        return donators;
    }else if(s.toStdString()=="totalviews"){
        return totalviews;
    }else if(s.toStdString()=="avgwatchtime"){
        return avgwatchtime;
    }else{
        return pagelikes;
    }
}

Controller::Controller(Model *m, QObject *parent) : QObject(parent), model(m), lw(nullptr), gw(nullptr){}

void Controller::setView(LandingWindow *_lw) { lw=_lw; }

void Controller::setView(GraphsWindow *_gw) { gw=_gw; }

int Controller::getCreatorsNumber() const
{
    return model->getListSize();
}

const Creator *Controller::getCreatorAt(int i) const
{
    return model->getCreatorAt(i);
}

void Controller::restoreLandingWindow()
{
    lw->show();
}

QString Controller::getCreatorName() const
{
    return model->getSelectedFullName();
}

int Controller::getAccountsNumber() const
{
    return model->getSelectedAccountsNumber();
}

QString Controller::getCreatorInfo() const
{
    return model->getSelectedInfo();
}

account_type Controller::getAccountType(int i) const
{
    return model->getSelectedAccountType(i);
}

account_type Controller::getAccountTypeByid(int i) const
{
    return model->getSelectedTypeById(i);
}

QString Controller::getAccountEmail(int i) const
{
    return model->getSelectedAccountEmail(i);
}

QString Controller::getAccountUsername(int i) const
{
    return model->getSelectedAccountUsername(i);
}

int Controller::getAccountId(int i) const
{
    return model->getSelectedAccountId(i);
}


void Controller::accountBtnClick()
{
    gw->updateAccountBtnStyle(sender()->objectName());
    vector<stats_type> stats;

    //Stats all account
    stats.push_back(impressions);
    stats.push_back(coverage);
    stats.push_back(likes);
    stats.push_back(followers);

    int id = sender()->objectName().toInt();
    if(id!=-1){
        //non è all account
        id = model->getSelectedTypeById(sender()->objectName().toInt());

        // switch sul tipo
        switch(id){
            case 0:
                // Youtube
                stats.push_back(following);
                stats.push_back(donators);
                stats.push_back(totalviews);
                stats.push_back(avgwatchtime);
                break;
            case 1:
                // Facebook
                stats.push_back(pagelikes);
                break;
            case 2:
                // Instagram
                stats.push_back(following);
                break;
        }
    }
    gw->insertStatsBtn(&stats, sender()->objectName());
}

void Controller::statsBtnClick()
{
    gw->updateStatsBtnStyle(sender()->objectName());
    QString accountId = gw->getSelectedAccountId();
    QString statType = sender()->objectName();

    //controllo se è all account
    //se true devo fare un vettore con gli id di tutti gli account
    vector<u_int> ids;
    QChart * chart;
    if(accountId.toInt()==-1){
        for(int i = 0; i< getAccountsNumber(); i++){
            ids.push_back(getAccountId(i));
        }
    }else{
        ids.push_back(accountId.toUInt());
    }

    stats_type stat = stringToEnum(statType);
    switch(stat){
        case impressions:
            chart = model->graphImpression(&ids);
            break;
        case coverage:
            chart = model->graphCoverage(&ids);
            break;
        case likes:
            chart = model->graphLike(&ids);
            break;
        case followers:
            chart = model->graphFollowers(&ids);
            break;
        case following:
            chart = model->graphFollowing(&ids);
            break;
        case donators:
            chart = model->graphDonators(&ids);
            break;
        case totalviews:
            chart = model->graphTotalViews(&ids);
            break;
        case avgwatchtime:
            chart = model->graphAvgWatchtime(&ids);
            break;
        case pagelikes:
            chart = model->graphPageLikes(&ids);
            break;
    }
    gw->displayChart(chart);
}

void Controller::importBtnClick()
{

    QString path=QFileDialog::getOpenFileName(gw, "Choose file data to import","","Json (*.json)");
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    settings.setValue("app/datapath",path);

    importData(path);
}

void Controller::importData(QString path) try {

    if(path.isEmpty()) throw runtime_error("Invalid path entered.");
    model->importList(path.toStdString());

    // reset creatorsLyt
    if(lw)
        lw->fillCreatorsLyt();

    // notifica termine operazione
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    QMessageBox wAlert(lw);
    wAlert.setWindowTitle("Success");
    wAlert.setWindowIcon(QIcon(settings.value("app/logo").toString()));
    wAlert.setIcon(QMessageBox::NoIcon);
    wAlert.setStandardButtons(QMessageBox::Ok);
    wAlert.setText("Data have been imported successfully.");
    wAlert.exec();

} catch (runtime_error e) {
    // notifica fallimento dell'import
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    QMessageBox wAlert(lw);
    wAlert.setWindowTitle("Import error");
    wAlert.setWindowIcon(QIcon(settings.value("app/logo").toString()));
    wAlert.setIcon(QMessageBox::Warning);
    wAlert.setStandardButtons(QMessageBox::Ok);
    wAlert.setText("The program will terminate.");
    wAlert.setInformativeText(e.what());
    wAlert.exec();
    abort();
}

void Controller::exportBtnClick()try {

    QString path=QFileDialog::getSaveFileName(gw, "Export Data","","Json (*.json)");
    if(path.isEmpty()) throw runtime_error("Invalid path entered.");
    model->exportList(path.toStdString());

    // notifica termine operazione
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    QMessageBox wAlert(lw);
    wAlert.setWindowTitle("Success");
    wAlert.setWindowIcon(QIcon(settings.value("app/logo").toString()));
    wAlert.setIcon(QMessageBox::NoIcon);
    wAlert.setStandardButtons(QMessageBox::Ok);
    wAlert.setText("Data have been exported successfully.");
    wAlert.exec();

} catch (runtime_error e) {
    // notifica fallimento dell'export
    QSettings settings(QString(":resources/config.ini"), QSettings::IniFormat);
    QMessageBox wAlert(lw);
    wAlert.setWindowTitle("Export error");
    wAlert.setInformativeText(e.what());
    wAlert.setWindowIcon(QIcon(settings.value("app/logo").toString()));
    wAlert.setIcon(QMessageBox::Warning);
    wAlert.setStandardButtons(QMessageBox::Ok);
    wAlert.setText(e.what());
    wAlert.exec();

}

void Controller::infoBtnClick()
{
    QInfoDialog d(qobject_cast<QWidget*>(sender()->parent()));
    d.exec();
}

void Controller::creatorBtnClick()
{
    QString ssn=sender()->objectName();
    model->setSelected(ssn.toStdString());
    setView(new GraphsWindow(this));
    gw->show();
    emit gw->firstAccount->click();
    lw->hide();
}

