#ifndef SOCIAL_H
#define SOCIAL_H
#include "vector"
#include "account.h"


class Social
{
private:
    std::vector<Account&> socialList;
public:
    Social(){}
    Social(const std::vector<Account&>&);
    Social(const Social&);
    Social(const Account&);
    virtual ~Social();

};

#endif // SOCIAL_H
