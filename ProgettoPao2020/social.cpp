#include "social.h"

Social::Social(const std::vector<Account>& _sl):socialList(_sl){}

Social::Social(const Social& _s):socialList(_s.socialList){}

Social::Social(const Account& _a){
    socialList.push_back(const_cast<Account &>(_a));
}

Social::~Social() = default;


