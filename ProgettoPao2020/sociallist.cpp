#include "sociallist.h"
SocialList::~SocialList(){}
SocialList::SocialList(const SocialList& _sociallist):list(_sociallist.list){}

SocialList::SocialList(const std::vector<Account>& _sl):list(_sl){}

SocialList::SocialList(const Account& _acc){ list.push_back(_acc); }

void SocialList::addAccount(const Account &_acc)
{
    bool valid=true;
    for(auto a : list)
        if(a.getId()==_acc.getId())
            valid=false;
    if(valid)
        list.push_back(_acc);
    else
        throw "Account alredy exists in the list";
}

void SocialList::removeAt(u_int _i)
{
    if(_i<0 || _i>list.size())
        throw "Index out of range";
    list.erase(list.cbegin()+_i);
}

void SocialList::removeById(u_int _id)
{
    for(u_int i=0; i< list.size(); i ++)
        if(list[i].getId()==_id)
            list.erase(list.begin()+i);
}


