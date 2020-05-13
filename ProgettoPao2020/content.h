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
        Content(string, string, QDateTime, content_type, vector<Stats_content>);
        string getTitle() const;
        string getDescription() const;
        QDateTime getTimestamp() const;
        content_type getType() const;
        vector<Stats_content> *getStats();


};
#endif
