#ifndef CREATORLIST_H
#define CREATORLIST_H
#include <creator.h>

class CreatorList
{
    private:
        class node{
            public:
                Creator info;
                node *prev, *next;

                node(Creator& _info, node* _prev=nullptr, node* _next=nullptr): info(_info), prev(_prev), next(_next){}
                ~node();
        };

        node *first, *last;

    public:
        CreatorList(Creator& c);
        ~CreatorList();

        int getCreatorIndex(const Creator &c) const;
        void InsertFront(Creator &c);
        void InsertBack(Creator &c);
        int size() const;
        bool empty() const;
        Creator RemoveAt(int i);
        Creator RemoveNode(node* n);
        Creator RemoveCreator(const Creator &c);
        Creator RemoveBySSN(std::string ssn);
        Creator operator[](int i) const;

        class constiterator{
            friend class CreatorList;

            private:
                node* ptr;
                bool pastTheEnd;
                constiterator(node* n, bool pte): ptr(n), pastTheEnd(pte){}
            public:
                constiterator(): ptr(nullptr), pastTheEnd(false){}
                const Creator& operator*() const;
                const Creator* operator->() const;
                constiterator& operator++();
                constiterator& operator--();
                constiterator operator++(int);
                constiterator operator--(int);
                bool operator==(const constiterator &x) const;
                bool operator!=(const constiterator &x) const;
        };

        constiterator begin() const;
        constiterator end() const;

};

// https://elearning.unipd.it/math/pluginfile.php/55974/mod_resource/content/1/dList-11-12-nov-2019.cpp

// eliminazione per Piva, CF, elimina tutto


#endif // CREATORLIST_H