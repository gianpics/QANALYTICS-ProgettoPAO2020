#ifndef CREATORLIST_H
#define CREATORLIST_H
#include <creator.h>

class CreatorList
{
    private:
        class node{
            public:
                Creator info;
                node* prev;
                node* next;

                node(Creator& _info, node* _prev=nullptr, node* _next=nullptr): info(_info), prev(_prev), next(_next){}
                ~node();
        };
        node *first, *last;

    public:
        CreatorList(Creator&);
        ~CreatorList();

        void InsertFront(Creator&);
        void InsertBack(Creator&);
        Creator RemoveNode(node*);
        Creator RemoveCreator(Creator&);
        Creator RemoveByVAT(std::string);
        Creator RemoveBySSN(std::string);

        class constinterator{
            friend class CreatorList;

            private:
                node* ptr;
                bool pastTheEnd;
                constinterator(node* n, bool pte): ptr(n), pastTheEnd(pte){}
            public:
                constinterator(): ptr(nullptr), pastTheEnd(false){}
                const Creator& operator*() const;
                const Creator* operator->() const;
                constinterator& operator++();
                constinterator& operator--();
                bool operator==(const constinterator&) const;
                bool operator!=(const constinterator&) const;
        };

        constinterator begin() const;
        constinterator end() const;

};

// https://elearning.unipd.it/math/pluginfile.php/55974/mod_resource/content/1/dList-11-12-nov-2019.cpp

// eliminazione per Piva, CF, elimina tutto


#endif // CREATORLIST_H
