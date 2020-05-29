#ifndef STATS_INSTAGRAM_H
#define STATS_INSTAGRAM_H
#include <stats_account.h>
#include <vector>

class Stats_instagram : public Stats_account
{
private:
    u_int following;
public:
    Stats_instagram(QDate _date, u_int _impression = 0,  u_int _coverage = 0, u_int _like = 0, u_int _followers = 0, u_int _following = 0);
    virtual ~Stats_instagram() = default;
    u_int getFollowing() const;
    void setFollowing(u_int _following);
    virtual void print(ostream &_os) const;
    static void getStream(istream &_is, vector<const Stats_account*>& v);

};
ostream& operator<<(ostream& _os, const Stats_instagram &_si);

#endif // STATS_INSTAGRAM_H
