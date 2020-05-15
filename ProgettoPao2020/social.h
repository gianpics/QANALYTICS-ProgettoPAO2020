#ifndef SOCIAL_H
#define SOCIAL_H
#include "account.h"


class Social
{
private:
    std::vector<Account> socialList;

public:
    Social(){}
    virtual ~Social()  = 0;
    Social(const Social& _s);
    Social(const std::vector<Account>& _sl);
    Social(const Account& _acc);
};

#endif // SOCIAL_H
