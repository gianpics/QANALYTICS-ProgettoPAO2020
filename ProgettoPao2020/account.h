#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <vector>
#include <stats_account.h>
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
    vector<Content> contents;
    vector<Stats_account> stats;
    account_type type;
public:
    Account(u_int _id, string _username, string _email, account_type _type, vector<Content> contents = vector<Content>(), vector<Stats_account> stats = vector<Stats_account>());
    u_int getId() const;
    string getUsername() const;
    string getEmail() const;
    string getLink() const;
    vector<Content> *getContents();
    vector<Stats_account> *getStats();
};

#endif // ACCOUNT_H
