#include "social.h"

Social::Social(const Social& _s):socialList(_s.socialList){}

Social::Social(const std::vector<Account>& _sl):socialList(_sl){}

Social::Social(const Account& _acc){ socialList.push_back(_acc); }

