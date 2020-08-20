#include "account.h"


Account::Account(u_int _id, string _username, string _email, account_type _type, const vector<Content>& _contents, StatsList& _stats) : id(_id), username(_username), email(_email), type(_type), contents(_contents), stats(_stats){}

Account::Account()
{

}
Account::Account(const Account& _account)
{
    id=_account.id;
    username=_account.username;
    email=_account.email;
    type=_account.type;
    contents=_account.contents;
    stats=_account.stats;
}

Account& Account::operator=(const Account& _account)
{
    if(this != &_account){
        id=_account.id;
        username=_account.username;
        email=_account.email;
        type=_account.type;
        contents=_account.contents;
        stats=_account.stats;
    }
    return *this;
}

u_int Account::getId() const { return id; }

string Account::getUsername() const { return username; }


string Account::getEmail() const { return email; }


account_type Account::getType() const { return type;
}

const vector<Content>& Account::getContents() const {return contents;}


const StatsList& Account::getStats() const {return stats;}


string Account::getStringType() const
{
    switch (type) {
        case instagram: return "Instagram";
        case facebook: return "Facebook";
        case youtube: return "Youtube";
    }
}

account_type Account::getTypefromString(string t) const{
    if(t=="Instagram")
        return instagram;
    else if(t=="Facebook")
        return facebook;
    else
        return youtube;
}

void Account::read(const QJsonObject &_json)
{
    if(_json.contains("id") && _json["id"].isDouble())
        id = _json["id"].toInt();
    else
        throw runtime_error("Id format or value not valid.");

    if(_json.contains("username") && _json["username"].isString())
        username = _json["username"].toString().toStdString();
    else
        throw runtime_error("Username format or value not valid.");

    if(_json.contains("email") && _json["email"].isString())
        email = _json["email"].toString().toStdString();
    else
        throw runtime_error("Email format or value not valid.");

    if(_json.contains("account_type") && _json["account_type"].isString())
        type = getTypefromString(_json["account_type"].toString().toStdString());
    else
        throw runtime_error("Account_type format or value not valid.");

    if(_json.contains("contents") && _json["contents"].isArray()){
            QJsonArray contentArray = _json["contents"].toArray();
            for(int i = 0; i<contentArray.size(); ++i){
                QJsonObject contentObj = contentArray[i].toObject();
                Content c;
                c.read(contentObj);
                contents.push_back(c);
            }
    }
    else
        throw runtime_error("Contents format or value not valid.");

    StatsList s;
    s.read(_json);
    stats = s;

    /*QJsonObject statsobj = _json["stats"].toObject();
    switch (type) {
        case instagram: {
            Stats_instagram si;
            si.read(statsobj);
            stats.PushBack(si);
            break;
        }
        case facebook: {
            Stats_facebook sf;
            sf.read(statsobj);
            stats.PushBack(sf);
            break;
        }
        case youtube: {
            Stats_youtube sy;
            sy.read(statsobj);
            stats.PushBack(sy);
            break;
        }
    }*/

}

void Account::write(QJsonObject &_json) const
{
    _json["id"] = qint64(id);
    _json["username"] = QString::fromStdString(username);
    _json["email"] = QString::fromStdString(email);
    _json["account_type"] = QString::fromStdString(getStringType());
    QJsonArray jc;
    for(const Content &c : contents){
        QJsonObject obj;
        c.write(obj);
        jc.append(obj);
    }
    _json["contents"]=jc;
    stats.write(_json);
}

