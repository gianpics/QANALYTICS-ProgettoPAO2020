#ifndef CREATORS_H
#define CREATORS_H
#include <creator.h>

class Creators
{
    private:
        Creator c;
        Creators* prev;
        Creators* next;

    public:
        Creators(Creator&, Creators*, Creators*);
        ~Creators();

};

#endif // CREATORS_H
