#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include <stats_account.h>
#include <content.h>
typedef unsigned int u_int;
using namespace std;
class Account
{
private:
    u_int id;
    string username;
    string email;
    string link;
    vector<Content> contents;
    vector<Stats_account> stats;
public:
    Account(u_int, string, string, string, vector<Content> = vector<Content>(), vector<Stats_account> = vector<Stats_account>());
    u_int getId() const;
    string getUsername() const;
    string getEmail() const;
    string getLink() const;
    vector<Content> *getContents();
    vector<Stats_account> *getStats();
};

#endif // ACCOUNT_H
