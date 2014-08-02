/*
 * loadbinary.cpp
 *
 *  Created on: 29 Jul 2014
 *      Author: Michaelsun Baluyos
 */

#include "assignment1.hpp"
#include "Maze.hpp"

const int width_binary = 0;
const int height_binary = 1;
const int number_of_lines_binary = 2;
const int every_forth_binary = 4;

using namespace std;

void Maze::LoadBinary(char *fileName)
{
	try
	{
		ifstream dataFile;
		dataFile.open(fileName,ios::binary);

		int binaryNumber = 0;
		int x = 0;

		int xyBinary = 0;
		int numberLines = 0;

		while(!dataFile.eof())
		{
			dataFile.read((char*)&x,sizeof(int));

			if(binaryNumber == width_binary)
			{
				this->width = x;
			}
			else if(binaryNumber == height_binary)
			{
				this->height = x;
			}
			else if(binaryNumber == number_of_lines_binary)
			{
				this->numOfLInes = x;
			}
			else
			{
				if((xyBinary % every_forth_binary) == 0)
				{
					numberLines++;

					this->x1 = &x;
					cout << "\n" << numberLines << "\tx1: " << *this->x1 << "\t" << flush;
					(*this->x1)++;
				}
				if(((xyBinary + 3) % every_forth_binary) == 0)
				{
					this->y1 = &x;
					cout << " y1: " << *this->y1 <<  "\t" << flush;
					(*this->y1)++;
				}
				if(((xyBinary + 2) % every_forth_binary) == 0)
				{
					this->x2 = &x;
					cout << " x2: " << *this->x2 <<  "\t" << flush;
					(*this->x2)++;
				}
				if(((xyBinary + 1) % every_forth_binary) == 0)
				{
					this->y2 = &x;
					cout << " y2: " << *this->y2 << "\t" << flush;
					(*this->y2)++;
				}
				xyBinary++;
			}

			/*if(binaryNumber == 502)
			{
				break;
			}*/

			binaryNumber++;
		}
		cout << "\nsvg width: " << this->width << endl;
		cout << "svg height: " << this->height << endl;
		cout << "svg number of lines: " << this->numOfLInes << endl;
		cout << "bin number of lines: " << numberLines << endl;
	}
	catch(exception &ex)
	{
		cout << "File Error! cant load data" << endl;
	}
	cout << endl;
}

