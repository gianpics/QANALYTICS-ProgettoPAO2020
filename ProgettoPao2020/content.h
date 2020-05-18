#ifndef CONTENT_H
#define CONTENT_H

#include <string>
#include <QDateTime>
#include <stats_content.h>

using namespace std;
typedef unsigned int u_int;
enum content_type{image, video, livestream, story, text};

class Content
{
    private:
        string title;
        string description;
        QDateTime timestamp;
        content_type type;
        vector<Stats_content> stats;

    public:
        Content(string _title, string _description, QDateTime _timestamp, content_type _type, const vector<Stats_content>& _stats);
        Content(const Content& _content);
        Content &operator=(const Content& _content);
        string getTitle() const;
        void setTitle(string _title);
        string getDescription() const;
        void setDescription(string _description);
        QDateTime getTimestamp() const;
        void setTimeStamp(QDateTime _timestamp);
        content_type getType() const;
        void setType(content_type _type);
        vector<Stats_content> *getStats();
        void setStats(vector<Stats_content>&_stats);


};
#endif
