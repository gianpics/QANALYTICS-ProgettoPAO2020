#include "creatorlist.h"
#include "creator.h"

CreatorList::CreatorList(Creator& c): first(new node(c)), last(first){}

CreatorList::~CreatorList(){ delete first; delete last; }

CreatorList::node::~node(){

}

Creator CreatorList::RemoveNode(node* n){
    Creator foo=n->info;

    if(n==first)
    {
        first=n->next;
        first->prev=0;
    }
    else
    {
        (n->prev)->next=n->next;
        if(n->next!=0) (n->next)->prev=n->prev;
    }

    return foo;
}

const Creator& CreatorList::constinterator::operator*() const {
    return ptr->info;
}

const Creator* CreatorList::constinterator::operator->() const {
    return &(ptr->info);
}

void CreatorList::InsertFront(Creator& c)
{
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

void CreatorList::InsertBack(Creator& c)
{
    node* n = new node(c, last, nullptr);

    if(last==nullptr)
        // lista vuota
        first=last=n;
    else
        // lista non vuota
        last=last->next=n;
}

Creator CreatorList::RemoveCreator(Creator& c){
    // Localizza nella lista l'elemento da rimuovere
    Creator foo;
    bool found=false;
    for(constinterator i = begin(); i!=end() && !found; ++i)
    {
        if(i.ptr->info==c)
        {
            found=true;

            // rimozione
            foo=RemoveNode(i.ptr);
        }
    }

    if(found)
        return foo;
    else
        throw "Element not present.";
}

Creator CreatorList::RemoveByVAT(std::string piva){
    Creator foo;
    bool found=false;
    for(constinterator i = begin(); i!=end() && !found; ++i)
    {
        if(i.ptr->info.getVAT()==piva)
        {
            found=true;

            // rimozione
            foo=RemoveNode(i.ptr);
        }
    }

    if(found)
        return foo;
    throw "Element not present.";
}

Creator CreatorList::RemoveBySSN(std::string ssn){
    Creator foo;
    bool found=false;
    for(constinterator i = begin(); i!=end() && !found; ++i)
    {
        if(i.ptr->info.getSSN()==ssn)
        {
            found=true;

            // rimozione
            foo=RemoveNode(i.ptr);
        }
    }

    if(found)
        return foo;
    throw "Element not present.";
}

// operatore pre-incremento ++i
CreatorList::constinterator& CreatorList::constinterator::operator++() {
    if(ptr!=nullptr && !pastTheEnd)
    {
        if(ptr->next==nullptr)
        {
            ptr++;  // ptr=ptr->next; (?)
            pastTheEnd=true;
        }
        else
            ptr=ptr->next;
    }
    return *this;
}

// operatore pre-decremento --i
CreatorList::constinterator& CreatorList::constinterator::operator--() {
    if(ptr!=nullptr)
    {
        if(pastTheEnd)
        {
            ptr--;  // ptr=ptr->prev; (?)
            pastTheEnd=false;
        }
        else
            ptr=ptr->prev;
    }
    return *this;
}


bool CreatorList::constinterator::operator==(const constinterator& x) const { return ptr==x.ptr; }

bool CreatorList::constinterator::operator!=(const constinterator& x) const { return ptr!=x.ptr; }

CreatorList::constinterator CreatorList::begin() const { return constinterator(first, false); }

CreatorList::constinterator CreatorList::end() const { return constinterator(last+1, true); }
