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


void Controller::fillStatsLyt(GraphsWindow *gw, QVBoxLayout *statsLyt, QString acc)
{
    // svuota layout
    eraseLayout(statsLyt);

    QPushButton* btn;

    if(acc=="all")
    {
        // all

        //getFollowers
        btn=new QPushButton;
        btn->setText("Followers");
        btn->setToolTip("Compare socials' followers");
        btn->setObjectName("allfollowers");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getImpressions
        btn=new QPushButton;
        btn->setText("Impressions");
        btn->setToolTip("Compare socials' impressions");
        btn->setObjectName("allimpressions");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getCoverage
        btn=new QPushButton;
        btn->setText("Coverage");
        btn->setToolTip("Compare socials' coverage");
        btn->setObjectName("allcoverage");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getLike
        btn=new QPushButton;
        btn->setText("Likes");
        btn->setToolTip("Compare socials likes");
        btn->setObjectName("alllikes");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        return;
    }

    if(acc=="fb")
    {
        // fb

        //getFollowers
        btn=new QPushButton;
        btn->setText("Followers");
        btn->setToolTip("View followers monthly growth");
        btn->setObjectName("fbfollowers");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getImpressions
        btn=new QPushButton;
        btn->setText("Impressions");
        btn->setToolTip("View impressions monthly growth");
        btn->setObjectName("fbimpressions");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getCoverage
        btn=new QPushButton;
        btn->setText("Coverage");
        btn->setToolTip("View coverage monthly growth");
        btn->setObjectName("fbcoverage");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getLike
        btn=new QPushButton;
        btn->setText("Likes");
        btn->setToolTip("View likes monthly growth");
        btn->setObjectName("fblikes");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getPageLikes
        btn=new QPushButton;
        btn->setText("Page likes");
        btn->setToolTip("View page's likes monthly growth");
        btn->setObjectName("fbpagelikes");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        return;
    }

    if(acc=="ig")
    {
        // ig

        //getFollowers
        btn=new QPushButton;
        btn->setText("Followers");
        btn->setToolTip("View followers monthly growth");
        btn->setObjectName("igfollowers");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getImpressions
        btn=new QPushButton;
        btn->setText("Impressions");
        btn->setToolTip("View impressions monthly growth");
        btn->setObjectName("igimpressions");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getCoverage
        btn=new QPushButton;
        btn->setText("Coverage");
        btn->setToolTip("View coverage monthly growth");
        btn->setObjectName("igcoverage");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getLike
        btn=new QPushButton;
        btn->setText("Likes");
        btn->setToolTip("View likes monthly growth");
        btn->setObjectName("iglikes");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getFollowing
        btn=new QPushButton;
        btn->setText("Following");
        btn->setToolTip("View following monthly growth");
        btn->setObjectName("igfollowing");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        return;
    }

    if(acc=="yt")
    {
        // yt

        //getFollowers
        btn=new QPushButton;
        btn->setText("Followers");
        btn->setToolTip("View followers monthly growth");
        btn->setObjectName("ytfollowers");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getImpressions
        btn=new QPushButton;
        btn->setText("Impressions");
        btn->setToolTip("View impressions monthly growth");
        btn->setObjectName("ytimpressions");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getCoverage
        btn=new QPushButton;
        btn->setText("Coverage");
        btn->setToolTip("View coverage monthly growth");
        btn->setObjectName("ytcoverage");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getLike
        btn=new QPushButton;
        btn->setText("Likes");
        btn->setToolTip("View likes monthly growth");
        btn->setObjectName("ytlikes");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getFollowing
        btn=new QPushButton;
        btn->setText("Following");
        btn->setToolTip("View following monthly growth");
        btn->setObjectName("ytfollowing");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getDonators
        btn=new QPushButton;
        btn->setText("Donators");
        btn->setToolTip("View donators monthly growth");
        btn->setObjectName("ytdonators");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getTotalViews
        btn=new QPushButton;
        btn->setText("Total Views");
        btn->setToolTip("View total views monthly growth");
        btn->setObjectName("yttotalviews");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        //getAvgWatchTime
        btn=new QPushButton;
        btn->setText("Average Watch Time");
        btn->setToolTip("View average watch time monthly growth");
        btn->setObjectName("ytavgwatchtime");
        btn->setFlat(true);
        btn->setFixedSize(QSize(275,25));
        connect(btn, SIGNAL(clicked()), gw, SLOT(statsBtnClick()));
        statsLyt->addWidget(btn);

        return;
    }

}

void Controller::eraseLayout(QLayout *layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        delete item->widget();
        delete item;
    }
}


// riempie graphsLyt con il grafico richiesto
void Controller::fillGraphsLyt(GraphsWindow *g, QVBoxLayout *graphsLyt, QString stat)
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
}
