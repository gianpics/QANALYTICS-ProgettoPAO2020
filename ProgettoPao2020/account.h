#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <stats_account.h>
#include <stats_facebook.h>
#include <stats_youtube.h>
#include <stats_instagram.h>
#include <content.h>
#include <QJsonObject>
#include <QJsonArray>

typedef unsigned int u_int;
using namespace std;
enum account_type{youtube = 0, facebook = 1, instagram = 2};
class Account
{
private:
    u_int id;
    string username;
    string email;
    account_type type;
    vector<Content> contents;
    StatsList stats;
public:
    Account(u_int _id, string _username, string _email, account_type _type, const vector<Content>& contents, StatsList& stats);
    Account();
    Account(const Account& _account);
    Account& operator=(const Account& _account);
    u_int getId() const;
    void setId(u_int _id);
    string getUsername() const;
    void setUsername(string _username);
    string getEmail() const;
    void setEmail(string _email);
    account_type getType() const;
    void setType(account_type _type);
    const vector<Content>& getContents() const;
    void setContents(vector<Content>& _contents);
    const StatsList& getStats() const;
    void setStats(StatsList &_stats);
    string getStringType() const;
    account_type getTypefromString(string t)const;
    void read(const QJsonObject &_json);
    void write(QJsonObject &_json) const;
};


#endif // ACCOUNT_H
