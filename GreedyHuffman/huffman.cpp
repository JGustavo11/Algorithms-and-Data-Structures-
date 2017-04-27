#include"stdafx.h"
#include"huff.h"
template<typename T>
int leafNode<T>::getWeight()
{
    return weight;
}

template<typename T>
T leafNode<T>::getValue()
{
    return value;
}

template<typename T>
bool leafNode<T>::isLeaf()
{
    return true;
}

template<typename T>
int internalNode<T>::getWeight()
{
    return weight;
}

template<typename T>
bool internalNode<T>::isLeaf()
{
    return false;
}

template<typename T>
huffNode<T>* internalNode<T>::getLeft() const
{
    return left;
}

template<typename T>
huffNode<T>* internalNode<T>::getRight() const
{
    return right;
}

template<typename T>
void internalNode<T>::setLeft(huffNode<T>* newLeft)
{
    left = newLeft;
}

template<typename T>
void internalNode<T>::setRight(huffNode<T>* newRight)
{
    right = newRight;
}

template<typename T>
huffTree<T>::huffTree(T& newValue, int newWeight)
{
    root = new leafNode<T>(newValue, newWeight);
}

template<typename T>
huffTree<T>::huffTree(huffTree<T>* newLeft, huffTree<T>* newRight)
{
    root = new internalNode<T>(newLeft->getRoot(), newRight->getRoot());
}

template<typename T>
huffNode<T>* huffTree<T>::getRoot()
{
    return root;
}

template<typename T>
int huffTree<T>::getWeight()
{
    return root->getWeight();
}

template<typename T>
bool operator>(huffTree<T>& item1, huffTree<T>& item2)
{
	return (item1->getgetWeight()) > item2->getWeight();
}

template<typename T>
bool operator<(huffTree<T>& item1, huffTree<T>& item2)
{
	return (item1->getgetWeight()) < item2->getWeight();
}

template<typename T>
huffTree<T>* buildHuff(huffTree<T>** treeArray, int count)
{
    arrayHeap<huffTree<T>*, minHeapComp<T>>* forest = new arrayHeap< huffTree<T>*, minHeapComp<T>>(treeArray, count, count);

    huffTree<T>* tmp1 = 0;
    huffTree<T>* tmp2 = 0;
    huffTree<T>* tmp3 = 0;

    while (forest->getSize() > 1)
    {
        tmp1 = forest->removeFirst();
        tmp2 = forest->removeFirst();
        tmp3 = new huffTree<T>(tmp1, tmp2);

        forest->insert(tmp3);
        delete tmp1;
        delete tmp2;
    }

    return tmp3;
}
