#include "social.h"

Social::Social(const Social& _s){
    for(Account* acc : _s.socialList)
        socialList.push_back(new Account(*acc));
}

Social::Social(const std::vector<Account*>& _sl){
    for(Account* acc : _sl)
        socialList.push_back(new Account(*acc));
}

Social::Social(const Account* _acc){
    socialList.push_back(new Account(*_acc));
}

Social::~Social(){}

