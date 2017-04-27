#ifndef HUFF_H
#define HUFF_H
#include"heap.cpp"
template<typename T>
class huffNode
{
public:
    virtual ~huffNode(){}
    virtual int getWeight() = 0;
    virtual bool isLeaf() = 0;
};


template<typename T>
class leafNode : public huffNode <T>
{
private:
    T value;
    int weight;

public:
    leafNode(const T& newValue, int newWeight = 0) : value(newValue), weight(newWeight)
    {}

    int getWeight();
    T getValue();
    bool isLeaf();
};



template<typename T>
class internalNode : public huffNode <T>
{
private:
    huffNode<T>* left;
    huffNode<T>* right;
    int weight;

public:
    
    internalNode(huffNode<T>* newLeft = 0, huffNode<T>* newRight = 0) : left(newLeft), right(newRight)
    {
        weight = newLeft->getWeight() + newRight->getWeight();
    }

    int getWeight();
    bool isLeaf();

    huffNode<T>* getLeft() const;
    huffNode<T>* getRight() const;

    void setLeft(huffNode<T>* newLeft);
    void setRight(huffNode<T>* newRight);


};


template<typename T>
class huffTree
{
private:
    huffNode<T>* root;
    
public:
   
    huffTree(T& newValue, int newWeight);
    
    huffTree(huffTree<T>* newLeft = 0, huffTree<T>* newRight = 0);

    ~huffTree(){}

    huffNode<T>* getRoot();
    int getWeight();

	
	friend bool operator>(huffTree<T>& item1, huffTree<T>& item2);
	friend bool operator<(huffTree<T>& item1, huffTree<T>& item2);
};

#endif

