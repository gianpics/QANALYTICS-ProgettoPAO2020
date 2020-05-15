#include "content.h"

Content::Content(string _title, string _description, QDateTime _timestamp, content_type _type, const vector<Stats_content>& _stats) : title(_title), description(_description), timestamp(_timestamp), type(_type), stats(_stats){}

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

string Content::getDescription() const {return description;}

QDateTime Content::getTimestamp() const {return timestamp;}

content_type Content::getType() const{return type;}

vector<Stats_content> *Content::getStats(){ return &stats;}
