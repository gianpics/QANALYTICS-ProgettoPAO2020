#ifndef CONTENT_H
#define CONTENT_H

#include <string>
#include <QDateTime>
#include <stats_content.h>
#include <vector>

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
        vector<const Stats_content*> stats;

    public:
        Content(QDateTime _timestamp, content_type _type, const vector<const Stats_content*>& _stats, string _title = "", string _description = "");
        Content(const Content& _content);
        ~Content();
        Content &operator=(const Content& _content);
        string getTitle() const;
        void setTitle(string _title);
        string getDescription() const;
        void setDescription(string _description);
        QDateTime getTimestamp() const;
        void setTimeStamp(QDateTime _timestamp);
        content_type getType() const;
        void setType(content_type _type);
        const vector<const Stats_content*>& getStats() const;
        void setStats(vector<const Stats_content*>&_stats);
        virtual void print(ostream &_os) const;
};
ostream &operator<<(ostream& _os, const Content& _c);
istream &operator>>(istream &_is, vector<Content> &_c);
#endif
