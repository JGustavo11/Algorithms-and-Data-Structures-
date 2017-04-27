// Dragonball Super
//dedicated to my boy goku, shoutout to him.
#include"lists.cpp"
#include"List.h"
#include<iostream>

//----------------
template<class E>
class List;
template<class E>
class Link;
template<class E>
class goku;
//------------
int main()
{
using namespace std;
gokussj<int> mygoku;
//start putting in them numbers 
cout << "Prepending: 6" << endl;
mygoku.prepend(6);
mygoku.printList();


cout << "Prepending: 2" << endl;
mygoku.prepend(2);
mygoku.printList();


cout << "Prepending: 5" << endl;
mygoku.prepend(5);
mygoku.printList();


cout << "Appending: 3" << endl;
mygoku.append(3);
mygoku.printList();


cout << "Appending: 1" << endl;
mygoku.append(1);
mygoku.printList();


cout << "Appeding: 8" << endl;
mygoku.append(8);
mygoku.printList();


//display what you have
//use for
cout << "What you have " << *mygoku.getValue() << endl;
mygoku.moveToEnd();
cout << "then it looks like this" << *mygoku.getValue() << endl;
mygoku.moveToStart();


// less than 10 ro else numbers you put wont go through
for (int i = 0; i < 10; i++)
{
cout << "what you got " << *mygoku.getValue() << endl;
cout << "Next: " << mygoku.next() << endl;
}



for (int i = 0; i < 10; i++)
{

cout << "here" << mygoku.prev() << endl;
}

cout << "# active links: " << mygoku.numActive() << endl;
cout << "here are the free links: " << mygoku.numFree() << endl;
cout << "Clearing list" << endl;
mygoku.clear();
mygoku.printList();

cout << "Number of links active: " << mygoku.numActive() << endl;
cout << "Number of links free: " << mygoku.numFree() << endl;
return 0;
}
