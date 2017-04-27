#ifndef HEAP_H
#define HEAP_H
template<typename T>
class maxHeapComp
{
public:
    static bool prior(T item1, T item2);
};

template<typename T>
class minHeapComp
{
private:
public:
    static bool prior(T item1, T item2);
};

template<typename T, typename Comp>
class heap
{
private:
    void operator=(const heap&){}
    heap(const heap&){}

public:
    heap(){}
    virtual ~heap(){}

    virtual int getSize() const = 0;

    virtual int getLeft(int pos) const = 0;
    virtual int getRight(int pos) const = 0;
    virtual int getParent(int pos) const = 0
    virtual bool isLeaf(int pos) const = 0;

    virtual void buildHeap() = 0;
    virtual void insert(const T& newData) = 0;

  
    virtual T removeFirst() = 0;
  
    virtual T remove(int targetPos) = 0;
};

template<typename T, typename Comp>
class arrayHeap : public heap<T,Comp>
{
private:
    T* heapPtr;
    int size;
    int maxSize;

    void sink(int pos);
    void swap(int pos1, int pos2);

public:
    
    arrayHeap(T* newHeapPtr = 0, int newSize = 0, int newMaxSize = 0) :
        heapPtr(newHeapPtr), size(newSize), maxSize(newMaxSize)
    
        
        heapWrites++;

        buildHeap();
    }

    int getSize() const;
    int getLeft(int pos) const;
    int getRight(int pos) const;
    int getParent(int pos) const;

    bool isLeaf(int pos) const;

    void buildHeap();
    void insert(const T& newData);

    T removeFirst();
    T remove(int targetPos);

};

#endif
