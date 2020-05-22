#include "stats_facebook.h"

Stats_facebook::Stats_facebook(QDate _date, u_int _coverage, u_int _impression, u_int _like, u_int _followers, u_int _pagelikes) : Stats_account(_date, _coverage, _impression, _like, _followers), page_likes(_pagelikes){}

u_int Stats_facebook::getPageLikes() const {return page_likes;}

void Stats_facebook::setPageLikes(u_int _page_likes)
{
    page_likes = _page_likes;
}

ostream &operator<<(ostream &_os, const Stats_facebook _sf)
{
    _sf.print(_os);
    _os<<_sf.getFollowers()<<";";
    return _os;
}
