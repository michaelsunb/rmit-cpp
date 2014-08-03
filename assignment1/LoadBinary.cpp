/*
 * LoadBinary.cpp
 *
 *  Created on: 29 Jul 2014
 *      Author: Michaelsun Baluyos
 */

#include "Assignment1.hpp"
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

		if(!dataFile.is_open())
		{
			return;
		}
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
					this->x1++;
				}
				if(((xyBinary + 3) % every_forth_binary) == 0)
				{
					this->y1 = &x;
					this->y1++;
				}
				if(((xyBinary + 2) % every_forth_binary) == 0)
				{
					this->x2 = &x;
					this->x2++;
				}
				if(((xyBinary + 1) % every_forth_binary) == 0)
				{
					this->y2 = &x;
					this->y2++;
				}
				xyBinary++;
			}

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
}

