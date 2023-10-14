#include <iostream>
#include "linkedList.h"
#include "unorderedLinkedList.h"
#include "orderedLinkedList.h"
using namespace std;

template<class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr;
}
template<class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}
template<class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}
template<class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;

    return *this;
}
template<class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}
template<class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}
template <class Type>
bool orderedLinkedList<Type>:: search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current;

    current = this->first;

    while(current != nullptr && !found)
    {
        if(current->info >= searchItem)
            found = true;
        else
            current = current->link;
    }

    if(found)
        found = (current->info == searchItem);

    return found;
}
template <class Type>
void orderedLinkedList<Type>:: insert(const Type& newItem)
{   
    nodeType<Type> *current; //ptr to traverse the list
    nodeType<Type> *trailCurrent = nullptr; //ptr before current
    nodeType<Type> *newNode; //ptr to create a node
    bool found;

    newNode = new nodeType<Type>; //create the node
    newNode->info = newItem; //store newItem in the node
    newNode->link = nullptr; //newly inserted node points to nullptr

    if(this->first == nullptr) //case 1
    {
        this->first = newNode; //first is pointing to nullptr therefore the list is empty so we
        this->last  = newNode; // set both first and last ptr's to point at the newly inserted item
        this->count++; //keep track of linkedlist size after adding an item
    }
    else
    {
        current = this->first; //set current to the first node in the list
        found = false;

        while(current != nullptr && !found) //search the list
        {
            if(current->info >= newItem)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        if(current == this->first)//case 2
        {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
        }
        else // case 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if(current == nullptr)
                this->last = newNode;
            this->count++;
        }
    }
}
template <class Type>
void orderedLinkedList<Type>:: insertFirst(const Type& newItem)
{
    insert(newItem);
}
template <class Type>
void orderedLinkedList<Type>:: insertLast(const Type& newItem)
{
    insert(newItem);
}
template <class Type>
void orderedLinkedList<Type>:: deleteNode(const Type& deleteItem)
{   
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent = nullptr;
    bool found;

    if(this->first == nullptr)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = this->first;
        found = false;
        while(current != nullptr && !found)
            if(current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if(current == nullptr)
            cout << "The item to be deleted is not in the list." << endl;
        else
            if(current->info == deleteItem)
            {
                if(this->first == current)
                {
                    this->first = this->first->link;
                    if(this->first == nullptr)
                        this->last = nullptr;
                    delete current;
                }
                else
                {
                    trailCurrent->link = current->link;

                    if(current == this->last)
                        this->last = trailCurrent;
                    delete current;
                }
                this->count--;
            }
            else
                cout << "The item to be deleted is not in the list." << endl;
    }
}
template<class Type>
bool unorderedLinkedList<Type>:: search(const Type& searchItem) const
{
    nodeType<Type> *current;
    bool found = false;
    current = this->first;

    while(current != nullptr && !found)
    {
        if(current->info == searchItem)
        {
            found = true;
        }
        else
        {
            current = current->link;
        }
    }
    return found;
}
template<class Type>
void unorderedLinkedList<Type>:: insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = this->first;
    this->first = newNode;

    this->count++;

    if(this->last == nullptr)

        this->last = newNode;
}
template<class Type>
void unorderedLinkedList<Type>:: insertLast(const Type& newItem) 
{
    nodeType<Type> *newNode;

    newNode = new nodeType<Type>;

    newNode->info = newItem;
    newNode->link = nullptr;

    if(this->first == nullptr)
    {
        this->first = newNode;
        this->last = newNode;
        this->count++;
    }
    else
    {
        this->last->link = newNode;
        this->last = newNode;

        this->count++;
    }
}
template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;

    if(this->first == nullptr)
        cout << "Cannot delete from an empty list." << endl;

    else
    {
        if(this->first->info == deleteItem)
        {
            current = this->first;
            this->first = this->first->link;
            this->count--;

            if(this->first == nullptr)
            {
                this->last = nullptr;
            } 
            delete current;
        }
           
        else
        {
            found = false;
            trailCurrent = this->first;
            current = this->first->link;
                
            while(current != nullptr && !found)
            {
                    if(current->info != deleteItem)
                    {
                        trailCurrent = current;
                        current = current->link;
                    }
                    else
                        found = true;
            }
            if(found)
            {
                trailCurrent->link = current->link;
                this->count--;

                if(this->last == current)
                {
                        this->last = trailCurrent;
                }
                delete current;
            }
            else
                cout << "The item to be deleted is not in the list." << endl;
        }
        
    }
}
template<class Type>
linkedListType<Type>::linkedListType()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}
template<class Type>
void linkedListType<Type>::initializeList() //The function initializes the list to an empty state... default constructor or copyconstructor has already initialized the list when object is delcared.
{   //This function reinitializes the list to an empty state.
    destroyList();//if the list has any nodes, delete them.
}
template<class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current; //ptr to traverse the list

    current = first; 

    while(current != nullptr)
    {
        cout << current->info << " ";
        current = current->link;
    }
}
template<class Type>
int linkedListType<Type>::length() const
{
    return count;
}
template<class Type>
Type linkedListType<Type>::front() const
{
    assert(first != nullptr); //program will terminate if nullptr

    return first->info;
}
template<class Type>
Type linkedListType<Type>::back() const
{
    assert(last != nullptr);

    return last->info;
}
template<class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);

    return temp;
}
template<class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(last);

    return temp;
}
template<class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
    nodeType<Type> *newNode; //ptr to create a node
    nodeType<Type> *current; //ptr to traverse the list

    if(first != nullptr)
        destroyList();

    if(otherList.first == nullptr)
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        current = otherList.first; 

        count = otherList.count;

        first = new nodeType<Type>;

        first->info = current->info;
        first->link = nullptr;

        last = first;

        current = current->link;

        while(current != nullptr)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;

            last->link = newNode;
            last = newNode;

            current = current->link;
        }
    }
}
template<class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
    first = nullptr;
    copyList(otherList);
}
template<class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
    if(this != &otherList)
    {
        copyList(otherList);
    }
    return *this;
}
template<class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == nullptr);
}
template<class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;

    while(first != nullptr)
    {
        temp = first;
        first = first->link;
        delete temp;
    }

    last = nullptr;

    count = 0;
}

template<class Type>
linkedListType<Type>::~linkedListType()
{
    destroyList();
}

int main()
{
    cout << "Hello this is a linked list program." << endl;
    unorderedLinkedList<int> list1, list2;

    int num;

    cout << "Line 8: Enter numbers ending with -999." << endl;
    cin >> num;
    while(num != -999)
    {
        list1.insertFirst(num);
        cin >> num;
    }
    cout << endl;

    cout << "Line 16: list1: ";
    list1.print();
    cout << endl;
    list1.destroyList();
    orderedLinkedList<int> list3;

    int num2;

    cout << "Enter numbers ending with -1." << endl;
    cin >> num2;
    while(num2 != -999)
    {
        list3.insert(num2);
        cin >> num2;
    }
    cout << endl;

    cout << "Ordered list: ";
    list3.print();
    cout << endl;
    return 0;
}