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
