/*
 * Kruskal.cpp
 *
 *  Created on: 5 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

#include "../Kruskal.h"

using namespace std;

Cell Kruskal::findM(Cell vertex)
{
	int x2 = vertex.x2;
	int y2 = vertex.y2;

	if((PARENT[x2][y2].x2 == x2)
			&& (PARENT[x2][y2].y2 == y2))
	{
		return PARENT[x2][y2];
	}
	else
	{
		return findM(PARENT[x2][y2]);
	}
}

void Kruskal::makeSet(Cell vertex)
{
	int x2 = vertex.x2;
	int y2 = vertex.y2;

	PARENT[x2][y2] = {x2,y2};
	RANK[x2][y2] = 0;
}

void Kruskal::unionM(Cell root1, Cell root2) // merge
{
	int x1 = root1.x2;
	int y1 = root1.y2;

	int x2 = root2.x2;
	int y2 = root2.y2;

	if(RANK[x1][y1] > RANK[x2][y2])
	{
		PARENT[x2][y2] = root1;//x1,y1
	}
	else if(RANK[x2][y2] > RANK[x1][y1])
	{
		PARENT[x1][y1] = root2;//x2,y2
	}
	else
	{
		PARENT[x1][y1] = root2;//x2,y2
		RANK[x2][y2]++;
	}
}

bool Kruskal::ifEquals(Cell root1,Cell root2)
{
	int x1 = root1.x2;
	int y1 = root1.y2;

	int x2 = root2.x2;
	int y2 = root2.y2;

	if((x1 == x2) && (y1 == y2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Kruskal::build(int width, int height,int seed)
{
	srand(seed);
	vector<KruskalEdge> A;

	int numOfLines = (width*height);
	//vertices.resize(numOfLines);
	//edges.resize(numOfLines);

	PARENT.resize(width);
	RANK.resize(width);

	Cell prevCell = {0,0};
	Cell newCell = {0,0};
	int random = 0;

	int i = 0;
	for(int x=0;x<width;x++)
	{
		for(int y=0;y<height;y++)
		{
			newCell = {x, y};
			vertices.push_back(newCell);

			random = rand() % (numOfLines);

			if(x<width-1)
			{
				int incX = x+1;
				Cell newCellincX = {incX,y};
				edges.push_back(KruskalEdge(newCell,newCellincX,random));
			}

			random = rand() % (numOfLines);

			if(y<height-1)
			{
				int incY = y+1;
				Cell newCellIncY = {x,incY};
				edges.push_back(KruskalEdge(newCell,newCellIncY,random));
			}

			random = rand() % (numOfLines);

			if(x>0)
			{
				int decX = x-1;
				Cell newCellDecX = {decX,y};
				edges.push_back(KruskalEdge(newCell,newCellDecX,random));
			}

			if(y>0)
			{
				int decY = y-1;
				Cell newCellDecY = {x,decY};
				edges.push_back(KruskalEdge(newCell,newCellDecY,random));
			}
			PARENT[x].push_back({x, y});
			RANK[x].push_back(0);
		}
	}

	for(KruskalEdge e : edges)
	{
		i++;
		cout << i << ") x1='" << e.x1 << "' y1='" << e.y1 << "' x2='" << e.x2 << "' y2='" << e.y2 << "' weight='" << e.weight << endl;
	}

	sort(edges.begin(), edges.end(),[](KruskalEdge x, KruskalEdge y){return x.weight < y.weight;});

	for(KruskalEdge e : edges)
	{
		Cell root1 = findM({e.x1,e.y1});
		Cell root2 = findM({e.x2,e.y2});
		if(!ifEquals(root1,root2))
		{
			A.push_back(e);
			unionM(root1,root2);
		}
	}

	cout << "Saving Kruskal svg maze: test.svg" << endl;
	ofstream svgFile("test.svg", ofstream::out);

	svgFile << "<svg viewBox='0 0 1 1' width='500' height='500' "
			"xmlns='http://www.w3.org/2000/svg'>\n"
			"<rect width='1' height='1' style='fill: black' />" << endl;
	for(KruskalEdge e : A)
	{
		svgFile << "<line stroke='white' stroke-width='0.005'"
				" x1='" << float(e.x1)/width
				<< "' y1='" << float(e.y1)/height
				<< "' x2='" << float(e.x2)/width
				<< "' y2='" << float(e.y2)/height  << "'/>\n";
	}

	svgFile << "</svg>" << flush;
	svgFile.close();
}

//	Kruskal()
//	{
////		Cell cellA = Cell(0,0); // A
////		Cell cellB = Cell(1,0); // B
////		Cell cellC = Cell(1,1); // C
////		Cell cellD = Cell(2,1); // D
////		Cell cellE = Cell(2,2); // E
////		Cell cellF = Cell(3,2); // F
////
////		vertices = {cellA,cellB,cellC,cellD,cellE,cellF};
////
////		edges.push_back(KruskalEdge(cellA,cellB,4));
////		edges.push_back(KruskalEdge(cellC,cellD,7));
////		edges.push_back(KruskalEdge(cellE,cellF,2));
//
//		build(10,10,1);
//	}
