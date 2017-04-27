#include "stdafx.h"
#include"graph.h"
//------------------------------
void graph::print_row(int index)
{
cout << index << ": ";
int size = adj_matrix.at(index).size();
for (int x = 0; x < size; x++){
if (adj_matrix[index][x].edge == 1){
cout << x << ", ";
}
}
cout << endl;
}
//------------------------------------

void graph::initialize_graph(int num_of_vertices, int num_of_edges)
{
//declare 2d vector
graph empty;
empty.edge = 0;
vector<graph> temp;
temp.resize(num_of_vertices);
// make vector as 0 to init
for (int y = 0; y < num_of_vertices; y++){
temp.at(y) = empty;
}

adj_matrix.resize(num_of_vertices);
for (int x = 0; x < num_of_vertices; x++){
adj_matrix.at(x) = temp;
}

for (int j = 0; j < num_of_edges; j++){
cout << "input two numbers. Ie, 3 4, remember the space" << endl;
int vert1, vert2;
cin >> vert1 >> vert2;
insert_edge(vert1, vert2);
}
}
//-----------------------------------------
//-------------------------------------------------

void graph::insert_edge(int vertex1, int vertex2)
{
int num_of_vertices = adj_matrix.size();
bool isDuplicate = false;
if (vertex2 > num_of_vertices - 1){
cout << "cant find that young blood " << vertex2 << " in graph" << endl;
isDuplicate = true;
}
if (adj_matrix[vertex1][vertex2].edge == 1 || isDuplicate == true){
cout << "its either here, or you put the same edge twice" << endl;
int vert1, vert2;
cin >> vert1 >> vert2;
insert_edge(vert1, vert2);
}
else {
adj_matrix[vertex1][vertex2].edge = 1;
}
}
void graph::delete_edge(int vertex1, int vertex2)
{
adj_matrix.at(vertex1).at(vertex2).edge = 0;
}
//--------------------------------------------------------
//---------------------------------------------------------

void graph::list_all_edges(int num_of_vertices)
{
// Display all edges 
for (int x = 0; x < num_of_vertices; x++){
print_row(x);
}
}
//-------------------------------------------------------------
//-------------------------------------------------------------
void graph::list_all_neighbors(int vertex1, int num_of_vertices)
{

print_row(vertex1);
}
//------------------------------------------------------------------
//-------------------------------------------------------------------
void graph::no_incoming_edges(int num_of_vertices)
{

bool incoming[num_of_vertices];
for (int i = 0; i < num_of_vertices; i++){
incoming[i] = false;
}

for (int x = 0; x < num_of_vertices; x++){
for (int y = 0; y < num_of_vertices; y++){
if (adj_matrix[x][y].edge == 1){
int vertex_index = y;
incoming[vertex_index] = true;
}
}
}

for (int j = 0; j < num_of_vertices; j++){
if (incoming[j] == false){
cout << "this # " << j << " had no neighbors, cause he is lonely" << endl;
}
}
}

