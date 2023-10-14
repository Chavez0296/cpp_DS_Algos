#ifndef H_orderedLinkedList
#define H_orderedLinkedList
#include "linkedList.h"
using namespace std;

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
    public:
        bool search(const Type& searchItem) const;
        void insert(const Type& newItem);
        void insertFirst(const Type& newItem);
        void insertLast(const Type& newItem);
        void deleteNode(const Type& deleteItem);

};
#endif