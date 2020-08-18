#ifndef CONTENT_H
#define CONTENT_H

#include <string>
#include <QDateTime>
#include <stats_content.h>
#include <vector>
#include <statslist.h>
#include <QJsonObject>

using namespace std;
typedef unsigned int u_int;
enum content_type{image = 0 , video = 1, livestream = 2, story= 3, text=4};

class Content
{
    private:
        string title;
        string description;
        QDateTime timestamp;
        content_type type;
        StatsList stats;

    public:
        Content();
        Content(QDateTime _timestamp, content_type _type, StatsList &_stats, string _title = "", string _description = "");
        Content(const Content& _content);
        virtual ~Content();
        Content &operator=(const Content& _content);
        string getTitle() const;
        void setTitle(string _title);
        string getDescription() const;
        void setDescription(string _description);
        QDateTime getTimestamp() const;
        void setTimeStamp(QDateTime _timestamp);
        string getType() const;
        void setType(content_type _type);
        const StatsList& getStats() const;
        void setStats(StatsList &_stats);
        virtual void print(ostream &_os) const;
        void read(const QJsonObject &_json);
        void write(QJsonObject &_json) const;
};
#endif
