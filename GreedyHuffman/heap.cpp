#include"stdafx.h"
#include"heap.h"
#include"assert.h"
#include<iostream>
template<typename T>
bool maxHeapComp<T>::prior(T item1, T item2)
{
    
    heapReads++;
    heapReads++;

    if (item1 > item2)
    {
        return true;
    }

    return false;
}
template<typename T>
bool minHeapComp<T>::prior(T item1, T item2)
{
    
    heapReads++;
    heapReads++;

    if (item1 < item2)
    {
        return true;
    }

    return false;
}
template<typename T, typename Comp>
void arrayHeap<T, Comp>::sink(int pos)
{
   
    while (!isLeaf(pos))
    {
        int max = getLeft(pos);
        int right = getRight(pos);
		
        if (right < getSize() && Comp::prior(heapPtr[right], heapPtr[max]))
        {
            max = right;
        }

        if (Comp::prior(heapPtr[pos], heapPtr[max]))
        {
            return;
        }

        swap(pos, max);
        pos = max;
    }
}
template<typename T, typename Comp>
void arrayHeap<T, Comp>::swap(int pos1, int pos2)
{
    T temp = heapPtr[pos1];
    heapPtr[pos1] = heapPtr[pos2];
    heapPtr[pos2] = temp;

    
    heapReads++;
    heapReads++;

    
    heapWrites++;
    heapWrites++;
}

template<typename T, typename Comp>
int arrayHeap<T, Comp>::getSize() const
{
    return size;
}

template<typename T, typename Comp>
int arrayHeap<T, Comp>::getLeft(int pos) const
{
    return (2 * pos) + 1;
}

template<typename T, typename Comp>
int arrayHeap<T, Comp>::getRight(int pos) const
{
    return (2 * pos) + 2;
}

template<typename T, typename Comp>
int arrayHeap<T, Comp>::getParent(int pos) const
{
    return (pos - 1) / 2;
}

template<typename T, typename Comp>
bool arrayHeap<T, Comp>::isLeaf(int pos) const
{
    return ((pos < size) && pos >= (size / 2));
}

template<typename T, typename Comp>
void arrayHeap<T, Comp>::buildHeap()
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        sink(i);
    }
}

template<typename T, typename Comp>
void arrayHeap<T, Comp>::insert(const T& newData)
{
    using namespace std;

    if (size >= maxSize)
    {
        std::cout << "full" << endl;
        return;
    }

    int curr = size++;

    heapPtr[curr] = newData;
	
     
    heapWrites++;

    while ((curr != 0) && (Comp::prior(heapPtr[curr], heapPtr[getParent(curr)] )))
    {
        swap(curr, getParent(curr));
        curr = getParent(curr);
    }
}

template<typename T, typename Comp>
T arrayHeap<T, Comp>::removeFirst()
{
    using namespace std;

    if (size < 0)
    {
        cout << "heap is empty" << endl;

    }
    

    swap(0, --size);

    if (size != 0)
    {
        sink(0);
    }

    heapReads++;

    return heapPtr[size];
}

template<typename T, typename Comp>
T arrayHeap<T, Comp>::remove(int pos)
{
    using namespace std;

    if ((pos < 0) || (pos > size))
    {
        //?
        
    }

    if (pos == (size - 1))
    {
        size--;
		return heapPtr[size];
    }
    else
    {
        swap(pos, --size);
        while ((pos != 0) && (Comp::prior(heapPtr[pos], heapPtr[getParent(pos)])))
        {
            swap(pos, getParent(pos));
            pos = getParent(pos);

        }

        if (size != 0)
        {
            sink(pos);
        }

        heapReads++;

        return heapPtr[size];
    }
}
