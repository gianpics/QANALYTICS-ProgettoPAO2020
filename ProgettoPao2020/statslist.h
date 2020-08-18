#ifndef STATSLIST_H
#define STATSLIST_H
#include <stats_content.h>
#include <stats_facebook.h>
#include <stats_instagram.h>
#include <stats_youtube.h>
#include "QJsonArray"

class StatsList
{
    private:
        class node{
            public:
                Stats *info;
                node *prev, *next;

                node(Stats *_info, node* _prev=nullptr, node* _next=nullptr): info(_info->clone()), prev(_prev), next(_next){}
                node(const node& n) : info(n.info->clone()), prev(n.prev), next(n.next){}
                node& operator=(const node& n){
                    if(this!=&n){
                        delete info;
                        info = n.info->clone();
                        prev=n.prev;
                        next=n.next;
                    }
                    return *this;
                }
                ~node(){delete info; prev=nullptr; next=nullptr;}
        };

        node *first, *last;
        void RemoveNode(node* n);
    public:
        StatsList();
        StatsList(Stats& s);
        StatsList(const StatsList& s);
        StatsList& operator=(const StatsList& s);
        virtual ~StatsList() = default;
        void PushBack(Stats &s);
        int getStatIndex(const Stats &s) const;
        int size() const;
        bool empty() const;
        void clear();
        void RemoveAt(int i);
        Stats& operator[](int i) const;
        void read(const QJsonObject &_json);
        void write(QJsonObject &_json) const;

    class constiterator{
        friend class StatsList;
        private:
            node* ptr;
            bool pastTheEnd;
            constiterator(node* n, bool pte): ptr(n), pastTheEnd(pte){}
        public:
            constiterator(): ptr(nullptr), pastTheEnd(false){}
            const Stats& operator*() const;
            const Stats* operator->() const;
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

#endif // STATSLIST_H
