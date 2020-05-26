#include "controller.h"
#include <QPushButton>

Controller::Controller(Model *m, QObject *parent) : QObject(parent), model(m), lw(nullptr), gw(nullptr){}

void Controller::setView(LandingWindow *_lw)
{
    lw=_lw;
}

void Controller::setView(GraphsWindow *_gw)
{
    gw=_gw;
}

CreatorList* Controller::retrieveCreators()
{
    std::vector<const Stats_content*> listsc;
    std::vector<Content> lc;
    std::vector<const Stats_account*> listsa;
    std::vector<Account> la;

    //INSERIMENTO DATI  CREATOR 1
    //STATS_CONTENT     QDATE, IMPRESSION, COVERAGE, LIKE, DISLIKE, NUMCOMMENTS, VIEWS, WATCHTIME
    Stats_content sc1a(*new QDate(2020, 02, 1), 215, 500, 1000, 200, 600, 20000, 400);      //VIDEO
    Stats_content sc1b(*new QDate(2010, 03, 1), 240, 900, 1100, 300, 850, 30000, 421);      //VIDEO

    Stats_content sc2a(*new QDate(2020, 02, 1), 300, 600, 2000, 220, 600, 20000, 400);      //VIDEO
    Stats_content sc2b(*new QDate(2020, 03, 1), 310, 650, 3000, 250, 900, 40000, 380);      //VIDEO

    Stats_content sc3a(*new QDate(2020, 02, 1), 400, 1200, 1000, 0, 600, 20000, 0);      //IMAGE
    Stats_content sc3b(*new QDate(2020, 03, 1), 300, 1000, 1100, 0, 700, 25000, 0);      //IMAGE

    Stats_content sc4a(*new QDate(2020, 01, 24), 1000, 1200, 0, 0, 0, 20000, 0);      //STORY

    Stats_content sc5a(*new QDate(2020, 02, 1), 300, 1000, 0, 0, 500, 3000, 12200);      //LIVESTREAM

    Stats_content sc6a(*new QDate(2020, 02, 1), 300, 500, 1000, 200, 120, 20000, 0);      //TEXT
    Stats_content sc6b(*new QDate(2020, 03, 1), 100, 400, 1300, 250, 150, 30000, 0);      //TEXT

    listsc.clear(); listsc.push_back(&sc1a); listsc.push_back(&sc1b);
    Content c1a(*(new QDateTime(*new QDate(2020, 01, 3))), video, listsc, "SCHERZO EPIKO FINITO MALE", "desc1");

    listsc.clear(); listsc.push_back(&sc2a); listsc.push_back(&sc2b);
    Content c1b(*(new QDateTime(*new QDate(2020, 01, 12))), video, listsc, "COME FOSSERO I GIOCATORI SENZA DENTI", "desc2");

    listsc.clear(); listsc.push_back(&sc3a); listsc.push_back(&sc3b);
    Content c2a(*(new QDateTime(*new QDate(2020, 01, 15))), image, listsc, "", "finalmente estate xoxo");

    listsc.clear(); listsc.push_back(&sc4a);
    Content c2b(*(new QDateTime(*new QDate(2020, 01, 24))), story, listsc);

    listsc.clear(); listsc.push_back(&sc5a);
    Content c3a(*(new QDateTime(*new QDate(2020, 01, 16))), livestream, listsc, "SPAKKETTAMENTO EPIKO FIFA20", "desc3");

    listsc.clear(); listsc.push_back(&sc6a); listsc.push_back(&sc6b);
    Content c3b(*(new QDateTime(*new QDate(2020, 01, 18))), text, listsc, "", "Ci vediamo oggi pomeriggio in live qui su fb");

    //STATS_YT      QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, FOLLOWING, DONATORS, TOTAL_VIEWS, AVG_WATCHTIME
    Stats_youtube sy1a(*new QDate(2020, 02, 1), 500, 200, 1100, 20000, 125, 10, 40000, 400);
    Stats_youtube sy1b(*new QDate(2020, 03, 1), 800, 500, 1550, 20100, 122, 25, 70000, 400);
    lc.clear(); lc.push_back(c1a);lc.push_back(c1b);
    listsa.clear(); listsa.push_back(&sy1a); listsa.push_back(&sy1b);
    Account acc1a(00, "panzYT", "panz@gmail.com", youtube, lc, listsa);
    //STATS_INSTA   QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, FOLLOWING
    Stats_instagram si1a(*new QDate(2020, 04, 1),800,3000,1000,10000, 125);
    Stats_instagram si1b(*new QDate(2020, 05, 1),1000,4000,1100,10100, 130);
    lc.clear(); lc.push_back(c2a);lc.push_back(c2b);
    listsa.clear(); listsa.push_back(&si1a); listsa.push_back(&si1b);
    Account acc1b(01, "panzINSTA", "panz@gmail.com", instagram, lc, listsa);
    //STATS_FB      QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, PAGE_LIKES
    Stats_facebook sf1a(*new QDate(2020, 02, 1),600,200,1000,18000, 25000);
    Stats_facebook sf1b(*new QDate(2020, 03, 1),900,700,1300,19000, 26000);
    lc.clear(); lc.push_back(c3a);lc.push_back(c3b);
    listsa.clear(); listsa.push_back(&sf1a); listsa.push_back(&sf1b);
    Account acc1c(02, "panzFB", "panz@gmail.com", facebook, lc, listsa);

    la.clear(); la.push_back(acc1a);la.push_back(acc1b);la.push_back(acc1c);
    Creator c1(la, "Giacomo", "SASSARO", "SSSGCM", "Via roma", "000012562", "Panz");
//---------------------------------------------------------------------------------------------------------------------
    //INSERIMENTO DATI CREATOR 2
    //STATS_CONTENT     QDATE, IMPRESSION, COVERAGE, LIKE, DISLIKE, NUMCOMMENTS, VIEWS, WATCHTIME
    Stats_content sc7a(*new QDate(2020, 02, 1), 40, 200, 45, 0, 10, 150, 0);      //IMAGE
    Stats_content sc7b(*new QDate(2020, 03, 1), 30, 190, 65, 0, 12, 180, 0);      //IMAGE

    Stats_content sc8a(*new QDate(2020, 02, 1), 30, 250, 80, 0, 25, 200, 0);      //IMAGE
    Stats_content sc8b(*new QDate(2020, 03, 1), 25, 220, 90, 0, 29, 220, 0);      //IMAGE

    Stats_content sc9a(*new QDate(2020, 02, 1), 20, 800, 25, 150, 200, 500, 0);      //TEXT
    Stats_content sc9b(*new QDate(2020, 03, 1), 10, 900, 28, 190, 220, 800, 0);      //TEXT

    listsc.clear(); listsc.push_back(&sc7a); listsc.push_back(&sc7b);
    Content c4a(*(new QDateTime(*new QDate(2020, 01, 26))), image, listsc, "", "Nuovi acquisti");
    listsc.clear(); listsc.push_back(&sc8a); listsc.push_back(&sc8b);
    Content c4b(*(new QDateTime(*new QDate(2020, 01, 10))), image, listsc, "", "Non smettere mai di lottare, sei una leonessa.");
    listsc.clear(); listsc.push_back(&sc9a); listsc.push_back(&sc9b);
    Content c5a(*(new QDateTime(*new QDate(2020, 01, 11))), text, listsc, "", "Quanto mi piacciono i bambini XD");

    //STATS_INSTA   QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, FOLLOWING
    Stats_instagram si2a(*new QDate(2020, 02, 1),400,600,125,500, 1250);
    Stats_instagram si2b(*new QDate(2020, 03, 1),500,800,155,550, 1300);
    lc.clear(); lc.push_back(c4a);lc.push_back(c4b);
    listsa.clear(); listsa.push_back(&si2a); listsa.push_back(&si2b);
    Account acc2a(10, "yubiINSTA", "yubi@gmail.com", instagram, lc, listsa);
    //STATS_FB      QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, PAGE_LIKES
    Stats_facebook sf2a(*new QDate(2020, 02, 1),50,1000,25,200, 150);
    Stats_facebook sf2b(*new QDate(2020, 03, 1),60,1100,28,202, 160);
    lc.clear(); lc.push_back(c5a);
    listsa.clear(); listsa.push_back(&sf2a); listsa.push_back(&sf2b);
    Account acc2b(11, "yubiFB", "yubi@gmail.com", facebook, lc, listsa);

    la.clear(); la.push_back(acc2a);la.push_back(acc2b);
    Creator c2(la, "Ayoub", "MAHER", "AYBMHR", "Via napoli", "000026598", "Yubi");

//---------------------------------------------------------------------------------------------------------------------------
    //INSERIMENTO DATI CREATOR 3

    //STATS_CONTENT     QDATE, IMPRESSION, COVERAGE, LIKE, DISLIKE, NUMCOMMENTS, VIEWS, WATCHTIME
    Stats_content sc10a(*new QDate(2020, 02, 1), 30000, 600000, 150000, 1000, 10000, 800000, 800);      //VIDEO
    Stats_content sc10b(*new QDate(2020, 03, 1), 40000, 800000, 200000, 1500, 12000, 1000000, 787);      //VIDEO

    listsc.clear(); listsc.push_back(&sc10a); listsc.push_back(&sc10b);
    Content c6a(*(new QDateTime(*new QDate(2020, 01, 1))), video, listsc, "FREE CATS <3", "descxxx 4catlover");

    //STATS_YT      QDATE, IMPRESSION, COVERAGE, LIKE, FOLLOWERS, FOLLOWING, DONATORS, TOTAL_VIEWS, AVG_WATCHTIME
    Stats_youtube sy3a(*new QDate(2020, 02, 1), 70000, 650000, 150000, 200000, 1, 500, 800000, 800);
    Stats_youtube sy3b(*new QDate(2020, 03, 1), 80000, 700000, 200000, 300000, 1, 550, 1000000, 787);
    lc.clear(); lc.push_back(c6a);
    listsa.clear(); listsa.push_back(&sy3a); listsa.push_back(&sy3b);
    Account acc3a(20, "gianpicsYT", "gianpics@gmail.com", youtube, lc, listsa);
    la.clear(); la.push_back(acc3a);
    Creator c3(la, "Gianpiero Giuseppe", "TOVO", "GNPTVO", "Via milano", "000098562", "Gianpics");
//----------------------------------------------------------------------------------------------------------------------------
    CreatorList *cl = new CreatorList(c1);
    cl->InsertBack(c2);
    cl->InsertBack(c3);
    model->setList(cl);
    return cl;
}

void Controller::launchCreatorGraphs(QString ssn)
{
    model->setSelected(ssn.toStdString());
    setView(new GraphsWindow(this));
    gw->show();
    lw->hide();
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


// riempie graphsLyt con il grafico richiesto
/*void Controller::fillGraphsLyt(GraphsWindow *g, QVBoxLayout *graphsLyt, QString stat)
{


    if(stat=="allfollowers")
    {
        //allaccount getFollowers

        return;
    }

    if(stat=="allimpressions")
    {
        //allaccount getImpressions

        return;
    }

    if(stat=="allcoverage")
    {
        //allaccount getCoverage

        return;
    }

    if(stat=="alllikes")
    {
        //allaccount getLikes

        return;
    }


    if(stat=="fbfollowers")
    {
        //fb getFollowers

        return;
    }


    if(stat=="fbimpressions")
    {
        //fb getImpressions

        return;
    }


    if(stat=="fbcoverage")
    {
        //fb getCoverage

        return;
    }


    if(stat=="fblikes")
    {
        //fb getLikes

        return;
    }


    if(stat=="fbpagelikes")
    {
        //fb getPageLikes

        return;
    }


    if(stat=="igfollowers")
    {
        //ig getFollowers

        return;
    }


    if(stat=="igimpressions")
    {
        //ig getImpressions

        return;
    }


    if(stat=="igcoverage")
    {
        //ig getCoverage

        return;
    }


    if(stat=="iglikes")
    {
        //ig getLikes

        return;
    }


    if(stat=="igfollowing")
    {
        //ig getFollowing

        return;
    }


    if(stat=="ytfollowers")
    {
        //yt getFollowers

        return;
    }


    if(stat=="ytimpressions")
    {
        //yt getImpressions

        return;
    }


    if(stat=="ytcoverage")
    {
        //yt getCoverage

        return;
    }


    if(stat=="ytlikes")
    {
        //yt getLikes

        return;
    }


    if(stat=="ytfollowing")
    {
        //yt getFollowing

        return;
    }


    if(stat=="ytdonators")
    {
        //yt getDonators

        return;
    }


    if(stat=="yttotalviews")
    {
        //yt getTotalViews

        return;
    }


    if(stat=="ytavgwatchtime")
    {
        //yt getAvgWatchTime

        return;
    }
}*/

void Controller::accountBtnClick()
{
    gw->updateAccountButtonsStyle(sender()->objectName());
    QStringList *stats = new QStringList();
    //Stats all account
    stats->append(QString::fromStdString("impression"));
    stats->append(QString::fromStdString("coverage"));
    stats->append(QString::fromStdString("likes"));
    stats->append(QString::fromStdString("followers"));
    int id = sender()->objectName().toInt();
    if(id!=-1){//non è all account
        id = model->getSelectedTypeById(sender()->objectName().toInt());
        switch(id){//lo switch è sul tipo
            case 0://Youtube
                stats->append(QString::fromStdString("following"));
                stats->append(QString::fromStdString("donators"));
                stats->append(QString::fromStdString("totalviews"));
                stats->append(QString::fromStdString("avgwatchtime"));
                break;
            case 1://facebook
                stats->append(QString::fromStdString("pagelikes"));
                break;
            case 2://instagram
                stats->append(QString::fromStdString("following"));
                break;
        }
    }

    gw->insertStatsButtons(stats, sender()->objectName());
    // richiama statistiche account selezionato
    //controller->fillStatsLyt(this, statsLyt, senderBtn->objectName());
}
