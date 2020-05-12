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

        class constinterator{
            friend class Creators;

            private:
                Creators* ptr;
                bool pastTheEnd;
            public:
                constinterator(): ptr(nullptr), pastTheEnd(false){}

                const Creator& operator*() const {}

                const Creator* operator->() const {}

                constinterator& operator++() {}

                constinterator& operator--() {}

                bool operator==(const constinterator&) const {}

                bool operator!=(const constinterator&) const {}
        };
};


// eliminazione per Piva, CF, elimina tutto


#endif // CREATORS_H
