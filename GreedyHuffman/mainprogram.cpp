#include "stdafx.h"
#include "heap.h"
#include "huff.cpp"
#include <iostream>
int main()
{
    using namespace std;

    
	int myList[20] = {};
	for (int i = 0; i < 10; i++)
	{
		myList[i] = i;
	}
    arrayHeap<int, minHeapComp<int> >  myHeap(myList,10,20);
	cout << myHeap.getSize() << endl;
    cout << myHeap.isLeaf(1) << endl;
    cout << myHeap.removeFirst() << endl;
    cout << myHeap.removeFirst() << endl;
    cout << myHeap.removeFirst() << endl;
    cout << myHeap.getLeft(0) << endl;
    cout << myHeap.getRight(0) << endl;
    cout << myHeap.getParent(3) << endl;
    cout << myHeap.getParent(4) << endl;
    myHeap.insert(10);
    myHeap.insert(12);
    cout << myHeap.remove(3) << endl;
huffTree<char>listOfHuffTrees[26];
arrayHeap< huffTree<char>, minHeapComp<huffTree<char>> >* myHeapOfHuffTrees= new arrayHeap< huffTree<char>, minHeapComp<huffTree<char>> > (listOfHuffTrees, 26, 26);
huffTree<char> myHuffTree = buildHuff(listOfHuffTrees, 26);

    return 0;
}
