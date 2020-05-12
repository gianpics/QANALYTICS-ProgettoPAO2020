<<<<<<< HEAD
#ifndef CONTENT_H
#define CONTENT_H

#include <string>
#include <QDateTime>
#include <map>

using namespace std;
typedef unsigned int u_int;
enum content_type{image, video, livestream, story, text};

class Content
{
    private:
        const string title;
        const string description;
        const QDateTime timestamp;
        const content_type type;
        const u_int impressions;
        const u_int comments;
        const u_int coverage;
        const u_int likes;
        const u_int dislikes;
        const u_int views;
        const u_int watchtime;


    public:
        Content(const string&, const string&, const QDateTime&, const content_type&, const u_int&, const u_int&, const u_int&, const u_int&, const u_int=0, const u_int=0, const u_int=0);
        ~Content()=default;
        string getTitle();
        string getDescription();
        QDateTime getTimestamp();
        u_int getLikes();
        u_int getDislikes();
        u_int getViews();
        u_int getWatchtime();
        u_int getImpressions();
        u_int getComments();
        u_int getCoverage();
        content_type getType();

};

#endif // CONTENT_H
=======
#ifndef CONTENUTO_H
#define CONTENUTO_H


class Contenuto
{
public:
    Contenuto();
    void foo(){return;}
};

#endif // CONTENUTO_H
>>>>>>> 492605c3b018cbf342c29072f7eb43bb3036c48f
