#include "stats_content.h"

Stats_content::Stats_content(QDate _date, u_int _impression, u_int _coverage, u_int _like, u_int _dislike, u_int _numcomments, u_int _views, u_int _watchtime) : Stats(_date, _impression, _coverage, _like), dislike(_dislike), num_comments(_numcomments), views(_views), watchtime(_watchtime){}

void Stats_content::setDislike(u_int _dislike)
{
    dislike=_dislike;
}

void Stats_content::setNum_comments(u_int _numcomments)
{
    num_comments = _numcomments;
}

void Stats_content::setViews(u_int _views)
{
    views = _views;
}

void Stats_content::setWatchtime(u_int _watchtime)
{
    watchtime = _watchtime;
}
ostream &operator<<(ostream &_os, const Stats_content &_sc)
{
    _sc.print(_os);
    _os<<_sc.getDislike()<<endl<<_sc.getNum_comments()<<endl<<_sc.getViews()<<endl<<_sc.getWatchtime()<<endl;
    return _os;
}


istream &operator>>(istream &_is, vector<const Stats_content *> &_v)
{
    string tmp;
    getline(_is, tmp);
    if(tmp=="[")
        while(tmp!="]"){
            string _date, _impression, _coverage, _like, _dislike, _ncomment, _views, _watchtime;
            if(tmp=="[")
                getline(_is, _date);
            else
                _date=tmp;
            getline(_is, _impression);
            getline(_is, _coverage);
            getline(_is, _like);
            getline(_is, _dislike);
            getline(_is, _ncomment);
            getline(_is, _views);
            getline(_is, _watchtime);
            _v.push_back(new Stats_content(QDate::fromString(QString::fromStdString(_date)), stoi(_impression), stoi(_coverage), stoi(_like), stoi(_dislike), stoi(_ncomment), stoi(_views), stoi(_watchtime)));
            getline(_is, tmp);
        }

    return _is;
}
