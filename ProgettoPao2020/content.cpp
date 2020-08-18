#include "content.h"

Content::Content(QDateTime _timestamp, content_type _type, StatsList &_stats, string _title, string _description) : title(_title), description(_description), timestamp(_timestamp), type(_type), stats(_stats){}

Content::Content(const Content &_content)
{
    title = _content.title;
    description = _content.description;
    timestamp = _content.timestamp;
    type = _content.type;
    stats=_content.stats;
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

    StatsList s;
    s.read(_json);
    stats=s;

}

void Content::write(QJsonObject &_json) const
{
    _json["title"] = QString::fromStdString(title);
    _json["description"] = QString::fromStdString(description);
    _json["timestamp"] = timestamp.toString();
    _json["content_type"] = type;//QString::fromStdString(getType());
    stats.write(_json);

}


