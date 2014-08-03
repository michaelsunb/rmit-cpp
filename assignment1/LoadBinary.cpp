/*
 * LoadBinary.cpp
 *
 *  Created on: 29 Jul 2014
 *      Author: Michaelsun Baluyos
 */

#include "Assignment1.hpp"
#include "Maze.hpp"

const int widthBinary = 0;
const int heightBinary = 1;
const int numberOfLinesBinary = 2;
const int everyForthBinary = 4;

using namespace std;

void Maze::LoadBinary(char *fileName)
{
	ifstream dataFile;
	dataFile.open(fileName,ios::binary);

	int binaryNumber = 0;
	int x = 0;

	int xyBinary = 0;
	int xyBinaryLine = 0;

	if(!dataFile.is_open())
	{
		return;
	}
	while(!dataFile.eof())
	{
		dataFile.read((char*)&x,sizeof(int));

		if(binaryNumber == widthBinary)
		{
			this->width = x;
		}
		else if(binaryNumber == heightBinary)
		{
			this->height = x;
		}
		else if(binaryNumber == numberOfLinesBinary)
		{
			this->numOfLInes = x;
			this->x1=new int[numOfLInes];
			this->y1=new int[numOfLInes];
			this->x2=new int[numOfLInes];
			this->y2=new int[numOfLInes];
		}
		else
		{
			if((xyBinary % everyForthBinary) == 0)
			{
				x1[xyBinaryLine] = x;
			}
			if(((xyBinary + 3) % everyForthBinary) == 0)
			{
				y1[xyBinaryLine] = x;
			}
			if(((xyBinary + 2) % everyForthBinary) == 0)
			{
				x2[xyBinaryLine] = x;
			}
			if(((xyBinary + 1) % everyForthBinary) == 0)
			{
				y2[xyBinaryLine] = x;
				xyBinaryLine++;
			}
			xyBinary++;
		}
		binaryNumber++;
	}
}

