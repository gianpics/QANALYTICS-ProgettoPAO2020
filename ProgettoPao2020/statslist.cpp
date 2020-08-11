#include "statslist.h"

StatsList::StatsList() :first(), last(){}

StatsList::StatsList(Stats &s): first(new node(&s)), last(first){}

StatsList::StatsList(const StatsList &s)
{
    if(s.size()>0){
        for(int i = 0; i<s.size(); i++){
            if(i==0)
                first=last=new node(&s[0], nullptr, nullptr);
            PushBack(s[i]);
        }
    }
}

StatsList &StatsList::operator=(const StatsList &s)
{
    if(this!=&s){
        if(s.size()>0){
            delete first; delete last;
            for(int i = 0; i<s.size(); i++){
                if(i==0)
                    first=last=new node(&s[0], nullptr, nullptr);
                PushBack(s[i]);
            }
        }
    }
    return *this;
}

void StatsList::PushBack(Stats &s)
{
    if(getStatIndex(s)>-1)
        throw "Could not insert already present element.";
    node* n = new node(&s, last, nullptr);
    if(last==nullptr)
        // lista vuota
        first=last=n;
    else
        // lista non vuota
        last=last->next=n;
}

int StatsList::getStatIndex(const Stats &s) const
{
    constiterator x;
    int i;
    if(first!=nullptr)
        for(i=0, x=begin(); x!=end(); i++, x++)
            if(x.ptr->info==&s) return i;
    return -1;
}

int StatsList::size() const
{
    int i=0;
    for(constiterator x=begin(); x!=end(); x++) i++;

    return i;
}

bool StatsList::empty() const
{
    return (first==nullptr);
}

void StatsList::clear()
{
    while(!empty()){
        RemoveNode(first);
    }
    last = nullptr;
}

void StatsList::RemoveAt(int i)
{
    Stats& s = this->operator[](i);
    for(constiterator j = begin(); j!=end(); ++j)
        if(j.ptr->info==&s)
            RemoveNode(j.ptr);
}

void StatsList::RemoveNode(StatsList::node *n)
{
    if(n==first)
    {
        // nodo da rimuovere è testa
        first=n->next;
        if(first!=nullptr) first->prev=nullptr;
    }
    else if(n==last)
    {
        //nodo da rimuovere in coda
        last=n->prev;
        if(last!=nullptr) last->next=nullptr;
    }else{
        (n->prev)->next=n->next;
        (n->next)->prev=n->prev;  
    }
    delete n;
}

Stats &StatsList::operator[](int i) const
{
    constiterator x;
    int k;

    for(k=0, x=begin(); k<=i && x!=end(); k++, x++)
        if (k==i) return *(x.ptr->info);

    throw "Out of range.";
}

StatsList::constiterator StatsList::begin() const
{
    return constiterator(first, false);
}

StatsList::constiterator StatsList::end() const
{
   return constiterator(last+1, true);
}

const Stats &StatsList::constiterator::operator*() const
{
    return *ptr->info;
}

const Stats *StatsList::constiterator::operator->() const
{
    return ptr->info;
}

StatsList::constiterator &StatsList::constiterator::operator++()
{
    if(ptr!=nullptr && !pastTheEnd)
    {
        if(ptr->next==nullptr)
        {
            ++ptr;
            pastTheEnd=true;
        }
        else
            ptr=ptr->next;
    }

    return *this;
}

StatsList::constiterator &StatsList::constiterator::operator--()
{
    if(ptr!=nullptr)
    {
        if(pastTheEnd)
        {
            --ptr;
            pastTheEnd=false;
        }
        else
            ptr=ptr->prev;
    }

    return *this;
}

StatsList::constiterator StatsList::constiterator::operator++(int)
{
    constiterator foo(*this);

    if(ptr!=nullptr && !pastTheEnd)
    {
        if(ptr->next==nullptr)
        {
            ++ptr;
            pastTheEnd=true;
        }
        else
            ptr=ptr->next;
    }

    return foo;
}

StatsList::constiterator StatsList::constiterator::operator--(int)
{
    constiterator foo(*this);

    if(ptr!=nullptr)
    {
        if(pastTheEnd)
        {
            --ptr;
            pastTheEnd=false;
        }
        else
            ptr=ptr->prev;
    }

    return foo;
}

bool StatsList::constiterator::operator==(const StatsList::constiterator &x) const
{
    return ptr==x.ptr;
}

bool StatsList::constiterator::operator!=(const StatsList::constiterator &x) const
{
    return ptr!=x.ptr;
}
