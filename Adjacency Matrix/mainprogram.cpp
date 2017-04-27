#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "graph.h"

//was case the best to use or could've I used something a bit more easier 
//and more efficient

using namespace std;
int main()
{
int num_of_vertices, num_of_edges, vertex1, vertex2, function;
Graph *g = new Graph();
while (1) {
cout << "1 - make graph" << endl;
cout << "2 - insert to graph" << endl;
cout << "3 - display edges in graph" << endl;
cout << "4 - neighbors for a vertex" << endl;
cout << "5 - which aint got no neighbors?" << endl;
cout << "6 - quit" << endl << endl;
cout << "whats your choice?  ";
cin >> function;
cout << endl << endl;
switch (function) {
case 1:
cout << "how many vertices in graph? ";
cin >> num_of_vertices;
cout << endl << endl;
g->init(num_of_vertices);
break;
case 2:
cout << "Enter the vertices" << endl;
cin >> vertex1 >> vertex2;
cout << endl << endl;
g->insert_edge(vertex1, vertex2);
break;
case 3:
g->list_all_edges();
break;
case 4:
cout << "vertex of all neighbors bih";
cin >> vertex1;
cout << endl << endl;
g->list_all_neighbors(vertex1);
break;
case 5:
g->no_incoming();
break;
case 6:
return 0;
}
} 
}
