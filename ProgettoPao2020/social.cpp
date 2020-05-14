#include "social.h"


Social::Social(const std::vector<Account &>& _sl):socialList(_sl){}

Social::Social(const Social& _s):socialList(_s ? _s.socialList : 0){}

Social::Social(const Account & _a):socialList(_a){}

Social::~Social() = default;
