#include "creators.h"
#include "creator.h"

Creators::Creators(Creator& c): first(new node(c)), last(first){}

Creators::~Creators(){ delete first; delete last; }

Creators::node::~node(){

}

const Creator& Creators::constinterator::operator*() const {
    return ptr->info;
}

const Creator* Creators::constinterator::operator->() const {
    return &(ptr->info);
}

void Creators::InsertFront(Creator& c)
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

void Creators::InsertBack(Creator& c)
{
    node* n = new node(c, last, nullptr);

    if(last==nullptr)
        // lista vuota
        first=last=n;
    else
        // lista non vuota
        last=last->next=n;
}

Creator Creators::RemoveCreator(Creator& c){
    // Localizza nella lista l'elemento da rimuovere
    Creator foo;
    bool found=false;
    for(Creators::constinterator i = begin(); i!=end() && !found; ++i)
    {
        if(i.ptr->info==c)
        {
            found=true;
            foo=i.ptr->info;

            // rimozione
            delete i.ptr;
        }
    }

    if(found)
        return foo;
    throw "Element not present.";
}

Creator Creators::RemoveByPIva(std::string piva){
    Creator foo;
    bool found=false;
    for(Creators::constinterator i = begin(); i!=end() && !found; ++i)
    {
        if(i.ptr->info.getVAT()==piva)
        {
            found=true;
            foo=i.ptr->info;

            // rimozione
            delete i.ptr;
        }
    }

    if(found)
        return foo;
    throw "Element not present.";
}

Creator Creators::RemoveBySSN(std::string ssn){
    Creator foo;
    bool found=false;
    for(Creators::constinterator i = begin(); i!=end() && !found; ++i)
    {
        if(i.ptr->info.getPiva()==ssn)
        {
            found=true;
            foo=i.ptr->info;

            // rimozione
            delete i.ptr;
        }
    }

    if(found)
        return foo;
    throw "Element not present.";
}

// operatore pre-incremento ++i
Creators::constinterator& Creators::constinterator::operator++() {
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
Creators::constinterator& Creators::constinterator::operator--() {
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


bool Creators::constinterator::operator==(const constinterator& x) const { return ptr==x.ptr; }

bool Creators::constinterator::operator!=(const constinterator& x) const { return ptr!=x.ptr; }

Creators::constinterator Creators::begin() const { return constinterator(first, false); }

Creators::constinterator Creators::end() const { return constinterator(last+1, true); }
