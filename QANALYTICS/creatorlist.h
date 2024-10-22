#ifndef CREATORLIST_H
#define CREATORLIST_H
#include <creator.h>

class CreatorList
{
private:
    std::vector<Creator> info;

public:
    CreatorList();
    CreatorList(Creator& c);

    int getCreatorIndex(const Creator &c) const;
    void InsertCreator(const Creator &c);
    int size() const;
    bool empty() const;
    Creator RemoveAt(int i);
    Creator RemoveCreator(const Creator &c);
    Creator RemoveBySSN(std::string ssn);
    const Creator& getCreatorBySSN(std::string _ssn) const;
    const Creator& operator[](unsigned int i) const;
    std::vector<Creator>::const_iterator begin() const;
    std::vector<Creator>::const_iterator end() const;
    void read(const QJsonObject &_json);
    void write(QJsonObject &_json) const;

};
#endif // CREATORLIST_H
