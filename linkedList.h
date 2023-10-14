#ifndef H_linkedList
#define H_linkedList
using namespace std;

template<class Type>
struct nodeType
{
    Type info;   //Struct node 
    nodeType<Type> *link;
};

template <class Type>
class linkedListIterator  //
{
    public:
        linkedListIterator();
        linkedListIterator(nodeType<Type> *ptr);
        Type operator*();
        linkedListIterator<Type> operator++();
        bool operator==(const linkedListIterator<Type>& right) const; 
        bool operator!=(const linkedListIterator<Type>& right) const;

    private:
        nodeType<Type> *current;
};
template <class Type>
class linkedListType
{
    public:
        const linkedListType<Type>& operator= (const linkedListType<Type>&); //Overload the assignment operator.
        void initializeList(); //Initialize the list to an empty state. Postcondition: first = nullptr, last = nullptr, count = 0;
        bool isEmptyList() const; //Function to determine whether the list is empty. Postcondition: return true if the list is empty, otherwise retuns false.
        void print() const; // Function to output the data contained in each node. 
        int length() const; //Function to return the number of nodes in the list.
        void destroyList(); // Function to delete all the nodes from the list. Postcondition: first= nullptr, last = nullptr, count = 0;
        Type front() const; //Function to return the first element of the list. Precondition: The list must exist and must not be empty. POSTCONDITION: If the list is empty, the program terminates, otherwise the first element of the list is returned.
        Type back() const;
        virtual bool search(const Type& searchItem) const = 0;
        virtual void insertFirst(const Type& newItem) = 0;
        virtual void insertLast(const Type& newItem) = 0;
        virtual void deleteNode(const Type& deleteItem) = 0;
        linkedListIterator<Type> begin();
        linkedListIterator<Type> end();
        linkedListType();
        linkedListType(const linkedListType<Type>& otherList);
        ~linkedListType();
    protected:
        int count; //variable to store the number of elements in the list

        nodeType<Type> *first; //pointer to the first node of the list
        nodeType<Type> *last; //pointer to the last node of the list

    private:
        void copyList(const linkedListType<Type>& otherList); //Function to make a copy of otherList. Post Condition: A copy of otherList is created and assigned to this list.
};

#endif