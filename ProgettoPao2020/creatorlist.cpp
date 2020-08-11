#include "creatorlist.h"

CreatorList::CreatorList(){}

CreatorList::CreatorList(Creator& c){ info.push_back(c); }


int CreatorList::getCreatorIndex(const Creator& c) const
{
    for(unsigned int i=0; i!=info.size(); i++)
    {
       if(info.at(i).getSSN()==c.getSSN())
           return i;
    }

    return -1;
}

void CreatorList::InsertCreator(Creator &c)
{
    if(getCreatorIndex(c)>-1)
        throw "Could not insert already present element.";

    info.push_back(c);

}

int CreatorList::size() const { return info.size(); }

bool CreatorList::empty() const { return info.empty(); }

Creator CreatorList::RemoveAt(int i)
{
    return RemoveCreator(info.at(i));
}

Creator CreatorList::RemoveCreator(const Creator& c)
{
    if(getCreatorIndex(c)>-1)
    {
        info.erase(std::vector<Creator>::const_iterator(info.begin()+getCreatorIndex(c)));
        return c;
    }

    throw "Could not remove non-existent element.";
}

Creator CreatorList::RemoveBySSN(std::string _ssn)
{
    Creator tmp;
    for(std::vector<Creator>::iterator it=info.begin(); it!=info.end(); it++)
        if(it->getSSN()==_ssn)
        {
            tmp=*it;
            info.erase(it);
            return tmp;
        }

    throw "Could not remove non existent element.";
}

const Creator& CreatorList::getCreatorBySSN(string _ssn) const
{
    for(std::vector<Creator>::const_iterator it=info.begin(); it!=info.end(); it++)
    {
        if(it->getSSN()==_ssn)
            return *it;
    }

    throw "Out of range.";
}

std::vector<Creator>::const_iterator CreatorList::begin() const
{
    return std::vector<Creator>::const_iterator(info.begin());
}

std::vector<Creator>::const_iterator CreatorList::end() const
{
    return std::vector<Creator>::const_iterator(info.end());
}


const Creator& CreatorList::operator[](unsigned int i) const
{
    return info.at(i);
}

ostream &operator<<(ostream &_os, const CreatorList &_cl)
{
    _os<<_cl.size()<<endl;
    for(std::vector<Creator>::const_iterator i = _cl.begin(); i!= _cl.end(); ++i)
        _os << *i <<"\n";
    return _os;
}

istream &operator>>(istream &_is, CreatorList &_cl)
{
    int size;
    _is >> size;
    for(int i=0;i<size;i++){
        Creator c;
        _is >> c;
        //cout<<c;
        _cl.InsertCreator(c);
    }
    return _is;
}
