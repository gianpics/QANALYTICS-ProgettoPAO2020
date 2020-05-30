#include "model.h"

void Model::setChart(QBarSeries* qbs, QStringList* qsl, QChart* chart) const
{
    chart->addSeries(qbs);
    QFont font;
    font.setBold(true);
    font.setPointSize(12);
    chart->setTitleFont(font);
    if(qbs->count()<2)
        chart->legend()->setVisible(false);
    chart->legend()->setAlignment(Qt::AlignBottom);


    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(*qsl);
    chart->addAxis(axisX, Qt::AlignBottom);
    qbs->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    qbs->attachAxis(axisY);
}

void Model::setCategories(vector<u_int> *_id, QStringList * categories) const
{
    QDate min(3000,12,30), max(0,0,0);
    for(auto a : *_id){
        for(auto s : selected->getAccountById(a).getStats()){
            if(s->getDate().addMonths(-1)<min)
                min = s->getDate().addMonths(-1);
            if(s->getDate().addMonths(-1)>max)
                max = s->getDate().addMonths(-1);
        }
    }
    QDate q;
    int m=min.month(), y=min.year();
    do{
        q.setDate(y,m,1);
        categories->append(q.toString("MMM yyyy"));
        m++;
        if(m>12){
            y++;
            m=1;
        }
    }while(!(m==max.month() && y==max.year()));
    q.setDate(max.year(),max.month(),1);
    categories->append(q.toString("MMM yyyy"));
}

void Model::setQBarSetColor(QBarSet *qbs) const
{
    if(qbs->label().toLower().toStdString() == "youtube"){
        //qbs->setObjectName("Youtube");
        qbs->setColor(*new QColor(255, 51, 0));
    }else if (qbs->label().toLower().toStdString() == "facebook") {
        //qbs->setObjectName("Facebook");
        qbs->setColor(*new QColor(0, 102, 255));
    }else{
        //qbs->setObjectName("Instagram");
        qbs->setColor(*new QColor(255, 51, 204));
    }
}

Model::Model(){reset();}

void Model::setList(CreatorList *_cl){ list=_cl;}

Creator* Model::getCreatorAt(int i) const
{
    return &(list->operator[](i));
}

int Model::getListSize() const
{
    return list->size();
}


void Model::setSelected(std::string _SSN){selected = &list->getCreatorBySSN(_SSN);}

int Model::getSelectedAccountsNumber() const
{
    return selected->size();
}

account_type Model::getSelectedAccountType(int i) const
{
    return selected->operator[](i).getType();
}

QString Model::getSelectedAccountEmail(int i) const
{
    return QString::fromStdString(selected->operator[](i).getEmail());
}

QString Model::getSelectedAccountUsername(int i) const
{
    return QString::fromStdString(selected->operator[](i).getUsername());
}

int Model::getSelectedAccountId(int i) const
{
    return selected->operator[](i).getId();
}

account_type Model::getSelectedTypeById(int i) const
{
    return selected->getAccountById(i).getType();
}

QString Model::getSelectedInfo() const
{
    return QString::fromStdString("<div style=\"line-height:160%\"><b>Name</b>  "+selected->getFullName()+"<br><b>Address  </b>"+selected->getAddress()+"<br><b>SSN</b>  "+selected->getSSN()+"<br><b>VAT </b>"+selected->getVAT())+"</div>";
}

QString Model::getSelectedFullName() const
{
    return QString::fromStdString(selected->getFullName());
}

QChart *Model::graphFollowers(vector<u_int>* _id_account) const
{
    //Imposto i mesi delle stats che devo analizzare
    QStringList categories;
    setCategories(_id_account, &categories);
    //Creo il puntatore a la serie di stats, conterrà followers, impression, ecc
    QBarSeries* series = new QBarSeries();
    //Puntatore all'account del sociale che mi interessa(fb, instagram, yt)
    const Account *acc;
    //Puntatore al vettore di stats dell'account(stats_fb, stats_instagram, stats_yt)
    const vector<const Stats_account*>* stats;
    //Ciclo su tutti gli account social di un creator di cui l'utente vuole sapere le stats
    for(auto a : *_id_account){
        //imposto l'account
        acc = &selected->getAccountById(a);
        //nuovo set di stats per quell'account con label "Nome_social"
        QBarSet *set = new QBarSet(QString::fromStdString(acc->getStringType()));
        //metodo per impostare il colore del set: yt = rosso, fb=blue, instagram=?
        setQBarSetColor(set);
        //imposto le stats per prendere ciò che mi serve
        stats = &acc->getStats();
        //ciclo per riempire il set di 0 nei mesi precedenti alla creazione dell'account
        for(auto i = 0; i<categories.size() && categories.at(i) != stats->at(0)->getDate().addMonths(-1).toString("MMM yyyy") ; i++){
            *set << 0;
        }
        //ciclo per riempire il set con le stats di mio interesse
        for(auto s : *stats){
            *set<<s->getFollowers();
        }
        //aggiungo il set alla serie(serie conterrà i set di tutti i vari account social)
        series->append(set);
    }
    //Serie contiente tutti i set, creo il chart
    QChart* chart = new QChart();
    //Collego serie, mesi, assi al chart
    setChart(series, &categories, chart);
    //Metto un titolo al chart
    chart->setTitle("Followers chart");
    //Restituisco puntatore al chart
    return chart;
}

QChart *Model::graphImpression(vector<u_int>* _id_account) const
{
    QStringList categories;
    setCategories(_id_account, &categories);
    QBarSeries* series = new QBarSeries();
    const Account *acc;
    const vector<const Stats_account*>* stats;
    for(auto a : *_id_account){
        acc = &selected->getAccountById(a);
        QBarSet *set = new QBarSet(QString::fromStdString(acc->getStringType()));
        setQBarSetColor(set);
        stats = &acc->getStats();
        for(auto i = 0; i<categories.size() && categories.at(i) != stats->at(0)->getDate().addMonths(-1).toString("MMM yyyy") ; i++){
            *set << 0;
        }
        for(auto s : *stats){
            *set<<s->getImpression();
        }
        series->append(set);
    }
    QChart* chart = new QChart();
    setChart(series, &categories, chart);
    chart->setTitle("Impression chart");
    return chart;
}

QChart *Model::graphCoverage(vector<u_int>* _id_account) const
{
    QStringList categories;
    setCategories(_id_account, &categories);
    QBarSeries* series = new QBarSeries();
    const Account *acc;
    const vector<const Stats_account*>* stats;
    for(auto a : *_id_account){
        acc = &selected->getAccountById(a);
        QBarSet *set = new QBarSet(QString::fromStdString(acc->getStringType()));
        setQBarSetColor(set);
        stats = &acc->getStats();
        for(auto i = 0; i<categories.size() && categories.at(i) != stats->at(0)->getDate().addMonths(-1).toString("MMM yyyy") ; i++){
            *set << 0;
        }
        for(auto s : *stats){
            *set<<s->getCoverage();
        }
        series->append(set);
    }
    QChart* chart = new QChart();
    setChart(series, &categories, chart);
    chart->setTitle("Coverage chart");
    return chart;
}

QChart *Model::graphLike(vector<u_int>* _id_account) const
{
    QStringList categories;
    setCategories(_id_account, &categories);
    QBarSeries* series = new QBarSeries();
    const Account *acc;
    const vector<const Stats_account*>* stats;
    for(auto a : *_id_account){
        acc = &selected->getAccountById(a);
        QBarSet *set = new QBarSet(QString::fromStdString(acc->getStringType()));
        setQBarSetColor(set);
        stats = &acc->getStats();
        for(auto i = 0; i<categories.size() && categories.at(i) != stats->at(0)->getDate().addMonths(-1).toString("MMM yyyy") ; i++){
            *set << 0;
        }
        for(auto s : *stats){
            *set<<s->getLike();
        }
        series->append(set);
    }
    QChart* chart = new QChart();
    setChart(series, &categories, chart);
    chart->setTitle("Like chart");
    return chart;
}
//ONLY FACEBOOK
QChart *Model::graphPageLikes(vector<u_int>* _id_account) const
{
    QStringList categories;
    setCategories(_id_account, &categories);
    QBarSeries* series = new QBarSeries();
    const Account *acc;
    const vector<const Stats_account*>* stats;
    for(auto a : *_id_account){
        acc = &selected->getAccountById(a);
        QBarSet *set = new QBarSet(QString::fromStdString(acc->getStringType()));
        setQBarSetColor(set);
        stats = &acc->getStats();
        for(auto i = 0; i<categories.size() && categories.at(i) != stats->at(0)->getDate().addMonths(-1).toString("MMM yyyy") ; i++){
            *set << 0;
        }
        if(!(acc->getType()==facebook)) {throw "This account doesn't have Page Like Stats";}
        for(auto s : *stats){
            *set<< static_cast<const Stats_facebook*>(s)->getPageLikes();
        }
        series->append(set);
    }
    QChart* chart = new QChart();
    setChart(series, &categories, chart);
    chart->setTitle("Page Likes chart");
    return chart;
}
//EXCEPT FACEBOOK
QChart *Model::graphFollowing(vector<u_int>* _id_account) const
{
    QStringList categories;
    setCategories(_id_account, &categories);
    QBarSeries* series = new QBarSeries();
    const Account *acc;
    const vector<const Stats_account*>* stats;
    for(auto a : *_id_account){
        acc = &selected->getAccountById(a);
        QBarSet *set = new QBarSet(QString::fromStdString(acc->getStringType()));
        setQBarSetColor(set);
        stats = &acc->getStats();
        for(auto i = 0; i<categories.size() && categories.at(i) != stats->at(0)->getDate().addMonths(-1).toString("MMM yyyy") ; i++){
            *set << 0;
        }
        if(acc->getType()==facebook) {throw "This account doesn't have Following Stats";}
        for(auto s : *stats){
            if(dynamic_cast<const Stats_youtube*>(s))
                *set<<static_cast<const Stats_youtube*>(s)->getFollowing();
            else
                *set<<static_cast<const Stats_instagram*>(s)->getFollowing();
        }
        series->append(set);
    }
    QChart* chart = new QChart();
    setChart(series, &categories, chart);
    chart->setTitle("Following chart");
    return chart;

}
//ONLY YOUTUBE
QChart *Model::graphDonators(vector<u_int>* _id_account) const
{
    QStringList categories;
    setCategories(_id_account, &categories);
    QBarSeries* series = new QBarSeries();
    const Account *acc;
    const vector<const Stats_account*>* stats;
    for(auto a : *_id_account){
        acc = &selected->getAccountById(a);
        QBarSet *set = new QBarSet(QString::fromStdString(acc->getStringType()));
        setQBarSetColor(set);
        stats = &acc->getStats();
        for(auto i = 0; i<categories.size() && categories.at(i) != stats->at(0)->getDate().addMonths(-1).toString("MMM yyyy") ; i++){
            *set << 0;
        }
        if(!(acc->getType()==youtube)) {throw "This account doesn't have Donators Stats";}
        for(auto s : *stats){
            *set<< static_cast<const Stats_youtube*>(s)->getDonators();
        }
        series->append(set);
    }
    QChart* chart = new QChart();
    setChart(series, &categories, chart);
    chart->setTitle("Donators chart");
    return chart;
}
//ONLY YOUTUBE
QChart *Model::graphTotalViews(vector<u_int>* _id_account) const
{
    QStringList categories;
    setCategories(_id_account, &categories);
    QBarSeries* series = new QBarSeries();
    const Account *acc;
    const vector<const Stats_account*>* stats;
    for(auto a : *_id_account){
        acc = &selected->getAccountById(a);
        QBarSet *set = new QBarSet(QString::fromStdString(acc->getStringType()));
        setQBarSetColor(set);
        stats = &acc->getStats();
        for(auto i = 0; i<categories.size() && categories.at(i) != stats->at(0)->getDate().addMonths(-1).toString("MMM yyyy") ; i++){
            *set << 0;
        }
        if(!(acc->getType()==youtube)) {throw "This account doesn't have Total Views Stats";}
        for(auto s : *stats){
            *set<< static_cast<const Stats_youtube*>(s)->getTotalViews();
        }
        series->append(set);
    }
    QChart* chart = new QChart();
    setChart(series, &categories, chart);
    chart->setTitle("Total Views chart");
    return chart;
}
//ONLY YOUTUBE
QChart *Model::graphAvgWatchtime(vector<u_int>* _id_account) const
{
    QStringList categories;
    setCategories(_id_account, &categories);
    QBarSeries* series = new QBarSeries();
    const Account *acc;
    const vector<const Stats_account*>* stats;
    for(auto a : *_id_account){
        acc = &selected->getAccountById(a);
        QBarSet *set = new QBarSet(QString::fromStdString(acc->getStringType()));
        setQBarSetColor(set);
        stats = &acc->getStats();
        for(auto i = 0; i<categories.size() && categories.at(i) != stats->at(0)->getDate().addMonths(-1).toString("MMM yyyy") ; i++){
            *set << 0;
        }
        if(!(acc->getType()==youtube)) {throw "This account doesn't have Average Stats";}
        for(auto s : *stats){
            *set<< static_cast<const Stats_youtube*>(s)->getAvgWatchtime();
        }
        series->append(set);
    }
    QChart* chart = new QChart();
    setChart(series, &categories, chart);
    chart->setTitle("Average Watchtime chart");
    return chart;
}

void Model::reset()
{
    selected = nullptr;
    list = new CreatorList();
}

void Model::exportList(string path)
{
    ofstream write;
    write.open(path);
    if(write.is_open()){
        write << *list;
        write.close();
    }
}

void Model::importList(string path)
{
    reset();

    ifstream read;
    read.open(path);
    if(read.is_open()){
       read >> *list;
       read.close();
    }
}
