#include "model.h"

QChart *Model::setChart(QLineSeries *qls) const
{
    /*QChart *chart = new QChart();
    chart->addSeries(qls);
    chart->legend()->hide();

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("dd MMM yyyy");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    qls->attachAxis(axisX);


    return chart;*/
}

Model::Model(const CreatorList& _list) : list(_list)
{
}

void Model::setSelected(std::string _SSN)
{
    selected = &list.getCreatorBySSN(_SSN);
}

QChart *Model::graphFollowers(u_int _id_account) const
{
    //QLineSeries *series = new QLineSeries();
    QBarSeries * series = new QBarSeries();
    QBarSet *s = new QBarSet("Followers");
    QStringList categories;
    const Account &acc = selected->getAccountById(_id_account);
    const vector<Stats_account>& stats = acc.getStats();
    for(auto a : stats){
        QDateTime date;
        date.setDate(a.getDate());
        *s<<a.getFollowers();
        categories << date.toString("MMM yyyy");
        //series->append(date.toMSecsSinceEpoch(), a.getFollowers());
    }
    series->append(s);
    //QChart * qc = setChart(series);
    QChart *qc = new QChart();
    qc->addSeries(series);
    qc->setTitle("Followers chart");
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    qc->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    QValueAxis *axisY = new QValueAxis();
    qc->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    /*QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Followers");
    qc->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);*/
    return qc;
}
