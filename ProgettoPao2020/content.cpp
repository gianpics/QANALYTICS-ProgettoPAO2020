#include "content.h"

Content::Content(const string& _title, const string& _description, const QDateTime& _timestamp, const content_type& _type, const u_int& _impressions, const u_int& _comments, const u_int& _coverage, const u_int& _likes, const u_int dislikes, const u_int _views, const u_int _watchtime):title(_title),description(_description),timestamp(_timestamp),type(_type),impressions(_impressions),comments(_comments),coverage(_coverage),likes(_likes),dislikes(_likes),views(_views),watchtime(_watchtime){}

string Content::getTitle(){ return Content::title; }
string Content::getDescription(){ return Content::description; }
QDateTime Content::getTimestamp(){ return Content::timestamp; }
u_int Content::getLikes(){ return Content::likes; }
u_int Content::getDislikes(){ return Content::dislikes; }
u_int Content::getViews(){ return Content::views; }
u_int Content::getWatchtime(){ return Content::watchtime; }
u_int Content::getImpressions(){ return Content::impressions; }
u_int Content::getComments(){ return Content::comments; }
u_int Content::getCoverage(){ return Content::coverage; }
content_type Content::getType(){ return Content::type; }
