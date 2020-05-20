#include "creatorlist.h"
#include "creator.h"

CreatorList::CreatorList(Creator& c): first(new node(c)), last(first){}

CreatorList::~CreatorList(){ delete first; delete last; }

CreatorList::node::~node(){ delete next; }

Creator CreatorList::RemoveNode(node* n){
    Creator foo=n->info;

    if(n==first)
    {
        // nodo da rimuovere è testa
        first=n->next;
        first->prev=nullptr;
    }
    else
    {
        (n->prev)->next=n->next;
        (n->next)->prev=n->prev;

        // se nodo era finale, aggiorna last al nuovo ultimo
        if(n==last) last=n->prev;
    }

    // delink
    n->prev=nullptr;
    n->next=nullptr;
    delete n;

    return foo;
}

int CreatorList::getCreatorIndex(const Creator &c) const
{
    constiterator x;
    int i;
    for(i=0, x=begin(); x!=end(); i++, x++)
        if(x.ptr->info==c) return i;
    return -1;
}

void CreatorList::InsertFront(Creator &c)
{
    if(getCreatorIndex(c)>-1)
        throw "Could not insert already present element.";

    node* n = new node(c, nullptr, first);

    if(first==nullptr)
        // lista vuota
        first=last=n;
    else
    {
        // lista non vuota
        first->prev=n;
        first=n;
    }
}

void CreatorList::InsertBack(Creator &c)
{
    if(getCreatorIndex(c)>-1)
        throw "Could not insert already present element.";

    node* n = new node(c, last, nullptr);

    if(last==nullptr)
        // lista vuota
        first=last=n;
    else
        // lista non vuota
        last=last->next=n;
}

int CreatorList::size() const
{
    int i=0;
    for(constiterator x=begin(); x!=end(); i++) i++;

    return i;
}

bool CreatorList::empty() const { return first==nullptr; }

Creator CreatorList::RemoveAt(int i)
{
    return RemoveCreator(this->operator[](i));
}

Creator CreatorList::RemoveCreator(const Creator& c)
{
    for(constiterator i = begin(); i!=end(); ++i)
        if(i.ptr->info==c)
            return RemoveNode(i.ptr);

    throw "Could not remove non existent element.";
}

Creator CreatorList::RemoveBySSN(std::string ssn)
{
    for(constiterator i = begin(); i!=end(); ++i)
        if(i.ptr->info.getSSN()==ssn)
            return RemoveNode(i.ptr);

    throw "Could not remove non existent element.";
}

Creator CreatorList::operator[](int i) const
{
    constiterator x;
    int k;

    for(k=0, x=begin(); k<=i && x!=end(); k++, x++)
        if (k==i) return x.ptr->info;

    throw "Out of range.";
}

// operatore pre-incremento ++i
CreatorList::constiterator& CreatorList::constiterator::operator++()
{
    if(ptr!=nullptr && !pastTheEnd)
    {
        if(ptr->next==nullptr)
        {
            ptr=ptr->next;
            pastTheEnd=true;
        }
        else
            ptr=ptr->next;
    }

    return *this;
}

// operatore pre-decremento --i
CreatorList::constiterator& CreatorList::constiterator::operator--()
{
    if(ptr!=nullptr)
    {
        if(pastTheEnd)
        {
            ptr=ptr->prev;
            pastTheEnd=false;
        }
        else
            ptr=ptr->prev;
    }

    return *this;
}

// operatore post-incremento i++
CreatorList::constiterator CreatorList::constiterator::operator++(int)
{
    constiterator foo(*this);

    if(ptr!=nullptr && !pastTheEnd)
    {
        if(ptr->next==nullptr)
        {
            ptr=ptr->next;
            pastTheEnd=true;
        }
        else
            ptr=ptr->next;
    }

    return foo;
}

// operatore post-decremento i--
CreatorList::constiterator CreatorList::constiterator::operator--(int)
{
    constiterator foo(*this);

    if(ptr!=nullptr)
    {
        if(pastTheEnd)
        {
            ptr=ptr->prev;
            pastTheEnd=false;
        }
        else
            ptr=ptr->prev;
    }

    return foo;
}

const Creator& CreatorList::constiterator::operator*() const { return ptr->info; }

const Creator* CreatorList::constiterator::operator->() const { return &(ptr->info); }

bool CreatorList::constiterator::operator==(const constiterator& x) const { return ptr==x.ptr; }

bool CreatorList::constiterator::operator!=(const constiterator& x) const { return ptr!=x.ptr; }

CreatorList::constiterator CreatorList::begin() const { return constiterator(first, false); }

CreatorList::constiterator CreatorList::end() const { return constiterator(last+1, true); }

ostream &operator<<(ostream &_os, const CreatorList &_cl)
{
    for(CreatorList::constiterator i = _cl.begin(); i!= _cl.end(); ++i)
        _os << &i <<";";
    return _os;
}
