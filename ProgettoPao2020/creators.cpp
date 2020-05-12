#include "creators.h"

Creators::Creators(Creator& _c, Creators* _prev=nullptr, Creators* _next=nullptr):c(_c),prev(_prev),next(_next){}

Creators::~Creators(){
    prev=next;

    next->prev=prev;
}
