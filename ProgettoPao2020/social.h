#ifndef SOCIAL_H
#define SOCIAL_H
#include "vector"
#include "account.h"


class Social
{
private:
    std::vector<const Account&> socialList;
public:
    Social(std::vector<const Account&>&);
    Social(const Social&);
    Social(const Account&);
    virtual ~Social();

};

#endif // SOCIAL_H
