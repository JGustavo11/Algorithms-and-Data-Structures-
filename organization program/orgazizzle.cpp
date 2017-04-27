//jose hernandez
//program should open a given (give) data and then organize it and store it in a output file  using if and of
#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
#include <iterator>

using namespace std;

int main()
{
	// used to open and write
	ifstream x;
	ofstream y;
	//declare the vector as thelist
	unordered_map<string, vector<string>> thelist;
	string sss, label;
	// will search for "red.txt" and open it
	x.open("red.txt", ifstream::in);

	// read label (1 line);
	getline(x, label);

	//use while so it will run as long as the file has somethin in it
	// while not end of file check if label shares the same sss
	while (!x.eof())
	{
		//read first line
		getline(x, sss);

		unordered_map<string, vector<string>>::const_iterator got = thelist.find(sss);

		if (got == thelist.end())
		{
			thelist[sss].push_back(label);
		}
		else
		{
			thelist[sss].push_back(label);
		}
		getline(x, label);
	}

	// Close data file
	x.close();

	//this will look for the y1.txt and open it
	// when it is open, the ifstream in will write the new contents
	y.open("y1.txt", ifstream::in);
	for (unordered_map <string, vector<string>>::iterator it = thelist.begin(); it != thelist.end(); ++it)
	{
		vector<string> tempVec = it->second;

		//display labels
		for (int i = 0; i < tempVec.size(); i++)
		{
			y << tempVec[i];

			if (i != (tempVec.size() - 1))
			{
				y << ", ";
			}

		}
		y << endl;

		//cout the sequence with labels
		y << it->first << endl;
	}
	// close our output file
	y.close();
	//use system pause so it can display press any key to continue
	//this will show that it was success and it opened and wrote new content
	system("pause");
	return 0;
}
