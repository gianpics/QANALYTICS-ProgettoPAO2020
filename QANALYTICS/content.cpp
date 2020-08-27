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

string Content::getDescription() const {return description;}

QDateTime Content::getTimestamp() const {return timestamp;}

string Content::getType() const{
    switch(type){
        case 0:
            return "image";
        case 1:
            return "video";
        case 2:
            return "livestream";
        case 3:
            return "story";
        case 4:
            return "text";
    }
    return "";
}

const StatsList& Content::getStats() const { return stats;}

void Content::read(const QJsonObject &_json)
{

    if(_json.contains("title") && _json["title"].isString())
        title = _json["title"].toString().toStdString();
    else
        throw runtime_error("Title format or value not valid.");

    if(_json.contains("description") && _json["description"].isString())
        description = _json["description"].toString().toStdString();
    else
        throw runtime_error("Description format or value not valid.");

    if(_json.contains("timestamp") && _json["timestamp"].isString())
        timestamp = QDateTime::fromString(_json["timestamp"].toString());
    else
        throw runtime_error("Timestamp format or value not valid.");

    if(_json.contains("content_type") && _json["content_type"].isDouble())
        type = content_type(_json["content_type"].toInt());
    else
        throw runtime_error("Content_type format or value not valid.");

    StatsList s;
    s.read(_json);
    stats=s;

}

void Content::write(QJsonObject &_json) const
{
    _json["title"] = QString::fromStdString(title);
    _json["description"] = QString::fromStdString(description);
    _json["timestamp"] = timestamp.toString();
    _json["content_type"] = type;
    stats.write(_json);

}


