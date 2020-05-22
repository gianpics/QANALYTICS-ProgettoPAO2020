#include "content.h"

Content::Content(QDateTime _timestamp, content_type _type, const vector<Stats_content>& _stats, string _title, string _description) : title(_title), description(_description), timestamp(_timestamp), type(_type), stats(_stats){}

Content::Content(const Content &_content)
{
    title = _content.title;
    description = _content.description;
    timestamp = _content.timestamp;
    type = _content.type;
    stats=_content.stats;
    /*for(auto a : _content.stats){
        stats.push_back(new Stats_content(*a));
    }*/
}

Content::~Content()
{

}

Content &Content::operator=(const Content &_content)
{
    if(this!=&_content){
        title = _content.title;
        description = _content.description;
        timestamp = _content.timestamp;
        stats=_content.stats;
        /*type = _content.type;for(auto a : _content.stats){
            stats.push_back(new Stats_content(*a));
        }*/
    }
    return *this;
}

string Content::getTitle() const {return title;}

void Content::setTitle(string _title)
{
    title=_title;
}

string Content::getDescription() const {return description;}

void Content::setDescription(string _description)
{
    description=_description;
}

QDateTime Content::getTimestamp() const {return timestamp;}

void Content::setTimeStamp(QDateTime _timestamp)
{
    timestamp=_timestamp;
}

content_type Content::getType() const{return type;}

void Content::setType(content_type _type)
{
    type=_type;
}

vector<Stats_content> *Content::getStats() { return &stats;}

void Content::setStats(vector<Stats_content> &_stats)
{
    stats=_stats;
}

ostream &operator<<(ostream &_os, Content &_c)
{

    _os<<_c.getTitle()<<","<<_c.getDescription()<<","<<_c.getTimestamp().toString("dd.MM.yyyy").toStdString()<<_c.getType();
    _os<<_c.getStats();
    return _os;
}
