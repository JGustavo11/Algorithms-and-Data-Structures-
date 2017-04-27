#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
//prototypes *******
void doRandLinearSearches(int searches, int*list, int& size, ofstream& iAsk);
int binarySearchComps(int* list, int low, int high, int target, int& comps);
void displayArray(int* list, int size, ofstream& iAsk);
int linearSearchComps(int* list, int size, int dest);
void doBinarySearches(int searches, int* list, int& size, ofstream& iAsk);
void makeArray(int* list, int size);
int main()
{
ofstream iAsk;
iAsk.open("iAsk.txt");
iAsk << "Enter something positive, but a number lol ";
int size;
cin >> size;
int* list = new int[size];
makeArray(list, size); // call makeArray
displayArrayArray(list, size, iAsk); //call displayArray 
doRandLinearSearches(100, list, size, iAsk); // call do randlinearsheard
doBinarySearches(100, list, size, iAsk); // call do binary searches
iAsk.close();
return 0;
}
// function definitions
int linearSearchComps(int* list, int size, int dest)
{
	int comparisons = 0;

	for(int i = 0; i < size; i++)
	{
		comparisons++;
		if(list[i] == dest)
		{
			return comparisons;
		}
	}

	return size; //not found
}

void displayArray(int* list, int size, ofstream& iAsk)
{
	for(int i = 0; i < size; i++)
	{
		iAsk << list[i] << ' ';
	}

	iAsk << endl;
}


void makeArray(int* list, int size)
{
	int i = 0;
	int randNum = 0;
	srand(time(0));

	for(int m = 0; i < size; m++)
	{
		randNum = rand() % 10 + 1;

		for(int j = 0; j < randNum; j++)
		{
			list[i++] = m;
		}
	}
}

void doRandLinearSearches(int searches, int* list, int& size, ofstream& iAsk)
{
	int comps = 0;
	int randTarget = 0;

	srand(time(0));

	for(int i = 0; i < searches; i++)
	{
		randTarget = list[rand() % (size)];
		comps = linearSearchComps(list, size, randTarget);
		iAsk << "linear comparison " << comps << endl;
	}
}

int binarySearchComps(int* list, int low, int high, int dest, int& comps)
{

	if(low > high)
	{
		return comps;
	}

	int mid = (high + low) / 2;

	comps++;

	if(list[mid] > dest)
	{
		//comps++;
		return binarySearchComps(list, low, mid - 1, dest, comps);
	}
	else if(list[mid] < dest)
	{
		//comps++;
		return binarySearchComps(list, mid+1, high, dest, comps);
	}
	else
	{
		return comps;
	}
}

void doBinarySearches(int searches, int* list, int& size, ofstream& iAsk)
{
	int comps = 0;
	int randTarget = 0;
	srand(time(0));

	for(int i = 0; i < searches; i++)
	{
		comps = 0;
		randTarget = list[rand() % (size)];
		comps = binarySearchComps(list, 0, size - 1, randTarget, comps);
		iAsk << "BinaryS comparison " << comps << endl;
	}
}
