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
        ~Content()=default;
        string getTitle();
        string getDescription();
        QDateTime getTimestamp();
        content_type getType();
        u_int getLikes();
        u_int getDislikes();
        u_int getViews();
        u_int getWatchtime();
        u_int getImpressions();
        u_int getComments();
        u_int getCoverage();


};
#endif
