//#include"stdafx.h"
// goku ssj
//may not be efficient
#include"List.h"
#include<cstdlib>
#include<iostream>
//#include<new>
template<class E>
//make private, not public class
//**************************************
class Link
{
private:

static Link<E>* freeList;
static int	activeLinks;
static int	freeLinks;
public:
E data;
Link<E>* prev;
Link<E>* next;

Link()
{
activeLinks++;
if (freeLinks != 0)
{
freeLinks--;
}
}

Link(E newData, Link<E>* newPrev = 0, Link<E>* newNext = 0) : data(newData), prev(newPrev), next(newNext)
{
activeLinks++;
if (freeLinks != 0)
{
freeLinks--;
}
}

void* operator new(size_t size);
void operator delete(void* p);

Link<E>* getFreeList();
int getActiveLinks();
int getFreeLinks();
};
//*****************************
//remember to close }, or else it wont compile



//*********** Define members
// then define the boy gokussj right here too
template<class E>
Link<E>* Link<E>::freeList = 0;
template<class E>
int Link<E>::activeLinks = 0;
template<class E>
int Link<E>::freeLinks = 0;
template<class E>
void* Link<E>::operator new(size_t size)
{

if (!freeList)
{

return ::new char[sizeof(Link<E>)];
}

freeLinks--;
Link<E>* newLink = freeList;
freeList = freeList->next;
return newLink;
}
template<class E>
void Link<E>::operator delete(void* p)
{

activeLinks--;
freeLinks++;
Link<E>* linkToDelete = static_cast<Link<E>*> (p);
linkToDelete->next = 0;
linkToDelete->prev = 0;
if (!freeList)
{
freeList = linkToDelete;
return;
}

freeList->prev = linkToDelete;
linkToDelete->next = freeList;
freeList = linkToDelete;
}
template<class E>
Link<E>* Link<E>::getFreeList()
{
return freeList;
}
template<class E>
int Link<E>::getActiveLinks()
{
return activeLinks;
}
template<class E>
int Link<E>::getFreeLinks()
{
return freeLinks;
}
template<class E>
class gokussj : public List<E>
{
private:
Link<E>* currNode;
Link<E>* head;
Link<E>* tail;
void deleteHead();
public:
gokussj(Link<E>* newCurrNode = 0, Link<E>* newHead = 0, Link<E>* newTail = 0) : currNode(newCurrNode), head(newHead), tail(newTail)
{}
~gokussj();
void clear();
void prepend(const E& item);
void append(const E& item);
bool moveToStart();
bool moveToEnd();
bool next();
bool prev();

const E* getValue() const;
int numActive();
int numFree();
void printList();
};
template<class E>
gokussj<E>::~gokussj()
{
while (head != 0)
{
Link<E>* oldHead = head;
head = head->next;
delete oldHead;
}
}
template<class E>
void gokussj<E>::deleteHead()
{
if (!head || head == tail)
{
delete head;
head = 0;
tail = 0;
currNode = 0;
return;
}
Link<E>* oldHead = head;
head = head->next;

delete oldHead;
}
template<class E>
void gokussj<E>::clear()
{
while (head != 0)
{
deleteHead();
}
}

template<class E>
void gokussj<E>::prepend(const E& item)
{
Link<E>* newLink = new Link<E>(item);
if (head == 0)
{
head = newLink;
tail = newLink;
currNode = newLink;
return;
}
head->prev = newLink;
newLink->next = head;
head = newLink;
}
template<class E>
void gokussj<E>::append(const E& item)
{
Link<E>* newLink = new Link<E>(item);
if (head == 0)
{
head = newLink;
tail = newLink;
currNode = newLink;
return;
}
newLink->prev = tail;
tail->next = newLink;
tail = newLink;
}
template<class E>
bool gokussj<E>::moveToStart()
{
if (head == 0)
{
return false;
}
currNode = head;
return true;
}
template<class E>
bool gokussj<E>::moveToEnd()
{
if (head == 0)
{
return false;
}
currNode = tail;
return true;
}
template<class E>
bool gokussj<E>::next()
{
if (head == 0 || currNode->next == 0)
{
return false;
}
currNode = currNode->next;
return true;
}
template<class E>
bool gokussj<E>::prev()
{
if (head == 0 || currNode->prev == 0)
{
return false;
}
currNode = currNode->prev;
return true;
}
template<class E>
const E* gokussj<E>::getValue() const
{
const E* value = &(currNode->data);
return value;
}
template<class E>
int gokussj<E>::numActive()
{
return head->getActiveLinks();
}
template<class E>
int gokussj<E>::numFree()
{
return head->getFreeLinks();
}
template<class E>
void gokussj<E>::printList()
{
using namespace std;
Link<E>* curr = head;
while (curr != 0)
{
cout << curr->data << ' ';
curr = curr->next;
}
cout << endl;
}
