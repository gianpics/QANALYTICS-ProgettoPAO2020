#include "content.h"

Content::Content(string _title, string _description, QDateTime _timestamp, content_type _type, vector<Stats_content> _stats) : title(_title), description(_description), timestamp(_timestamp), type(_type), stats(_stats){}

string Content::getTitle() const {return title;}

string Content::getDescription() const {return description;}

QDateTime Content::getTimestamp() const {return timestamp;}

content_type Content::getType() const{return type;}

vector<Stats_content> *Content::getStats(){ return &stats;}
