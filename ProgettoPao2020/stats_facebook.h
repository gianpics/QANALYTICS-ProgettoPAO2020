#ifndef STATS_FACEBOOK_H
#define STATS_FACEBOOK_H
#include <stats_account.h>
#include <vector>

class Stats_facebook : public Stats_account
{
private:
    u_int page_likes;
public:
    Stats_facebook();
    Stats_facebook(QDate _date, u_int _impression = 0, u_int _coverage = 0, u_int _like = 0, u_int _followers = 0, u_int _pagelikes = 0);
    virtual ~Stats_facebook() = default;
    u_int getPageLikes() const;
    Stats_facebook* clone() const;
    virtual void read(const QJsonObject &_json);
    virtual void write(QJsonObject &_json) const;
};
#endif // STATS_FACEBOOK_H
