/*
 * readfile.cpp
 *
 *  Created on: 29 Jul 2014
 *      Author: Michaelsun Baluyos
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char ** argv)
{
	try
	{
		ifstream dataFile;
		dataFile.open("ass1_example.maze",ios::binary);

		int x(0);
		while(!dataFile.eof())
		{
			dataFile.read((char*)&x,sizeof(int));
			cout << x << "\t" << flush;
		}
	}
	catch(exception &ex)
	{
		cout << "File Error! cant load data" << endl;
	}
	cout << endl;

	return 0;
}
