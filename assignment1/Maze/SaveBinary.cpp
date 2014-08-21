/*
 * SaveBinary.cpp
 *
 *  Created on: 21 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#include "../Assignment1.h"
#include "../Maze.h"

using namespace std;

void Maze::SaveBinary(char *fileName)
{
	cout << "Saving binary maze: " << fileName << endl;

	fstream dataFile(fileName, ios::out | ios::binary);

	dataFile.write((char*)&width,sizeof(int));
	dataFile.write((char*)&height,sizeof(int));
	dataFile.write((char*)&numOfEdges,sizeof(int));

	for(int ip = 0; ip < numOfEdges; ip++)
	{
		dataFile.write((char*)&eArray[ip].x1,sizeof(int));
		dataFile.write((char*)&eArray[ip].y1,sizeof(int));
		dataFile.write((char*)&eArray[ip].x2,sizeof(int));
		dataFile.write((char*)&eArray[ip].y2,sizeof(int));
	}
	dataFile.close();
}
