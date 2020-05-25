#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include <stats_account.h>
#include <stats_facebook.h>
#include <stats_youtube.h>
#include <stats_instagram.h>
#include <content.h>
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
    vector<const Stats_account*> stats;
public:
    Account(u_int _id, string _username, string _email, account_type _type, const vector<Content>& contents, const vector<const Stats_account*>& stats);
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
    const vector<const Stats_account*>& getStats() const;
    void setStats(vector<const Stats_account*> &_stats);
    string getStringType() const;
};
ostream& operator<<(ostream& _os, const Account& _a);

#endif // ACCOUNT_H
