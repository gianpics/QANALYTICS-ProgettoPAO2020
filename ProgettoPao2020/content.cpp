#include "content.h"

Content::Content(QDateTime _timestamp, content_type _type, StatsList &_stats, string _title, string _description) : title(_title), description(_description), timestamp(_timestamp), type(_type), stats(_stats){}

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
Content::Content()
{

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
        type = _content.type;
        /*for(auto a : _content.stats){
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

string Content::getType() const{
    switch(type){
        case 0:
            return "image";
            break;
        case 1:
            return "video";
            break;
        case 2:
        return "livestream";
            break;
        case 3:
            return "story";
            break;
        case 4:
            return "text";
            break;
    }
}



void Content::setType(content_type _type)
{
    type=_type;
}

const StatsList& Content::getStats() const { return stats;}

void Content::setStats(StatsList &_stats)
{
    stats=_stats;
    /*for(auto a : _stats){
        stats.push_back(new Stats_content(*a));
    }*/
}

void Content::print(ostream &_os) const
{
    /*_os << title << endl << description << endl << timestamp.toString().toStdString() << endl << type << endl;
    _os << "["<<endl;
    for(auto s : stats)
        _os << *s;
    _os << "]"<<endl;*/
}

void Content::read(const QJsonObject &_json)
{

    if(_json.contains("title"))
        title = _json["title"].toString().toStdString();

    if(_json.contains("description"))
        description = _json["description"].toString().toStdString();

    if(_json.contains("timestamp"))
        timestamp = QDateTime::fromString(_json["timestamp"].toString());

    if(_json.contains("content_type"))
        type = content_type(_json["content_type"].toInt());

    Stats_content sc;
    sc.read(_json["stats"].toObject());
    stats.PushBack(sc);

}

void Content::write(QJsonObject &_json) const
{
    _json["title"] = QString::fromStdString(title);
    _json["description"] = QString::fromStdString(description);
    _json["timestamp"] = timestamp.toString();
    _json["content_type"] = type;//QString::fromStdString(getType());
    stats.write(_json);

}


