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

#include "../Kruskal.h"
#include "../Maze.h"

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

Node Kruskal::build(Maze &maze,int width, int height,int seed)
{
	srand(seed);

	cout << "Generating Kruskal maze with seed: " << seed
			<< ", width: " << width
			<< ", height: " << height << endl;

	int numOfLines = (width*height);

	PARENT = new Cell*[width];
	RANK = new int*[width];

	Cell newCell = {0,0};
	int random = 0;

	for(int x=0;x<width;x++)
	{
		PARENT[x] = new Cell[height];
		RANK[x] = new int[height];
		for(int y=0;y<height;y++)
		{
			newCell = {x, y};

			if(x<width-1)
			{
				random = rand() % (numOfLines);

				int incX = x+1;
				Cell newCellincX = {incX,y};
				edges.push_back(KruskalEdge(newCell,newCellincX,random));
			}

			if(y<height-1)
			{
				random = rand() % (numOfLines);

				int incY = y+1;
				Cell newCellIncY = {x,incY};
				edges.push_back(KruskalEdge(newCell,newCellIncY,random));
			}

			if(x>0)
			{
				random = rand() % (numOfLines);

				int decX = x-1;
				Cell newCellDecX = {decX,y};
				edges.push_back(KruskalEdge(newCell,newCellDecX,random));
			}

			if(y>0)
			{
				random = rand() % (numOfLines);

				int decY = y-1;
				Cell newCellDecY = {x,decY};
				edges.push_back(KruskalEdge(newCell,newCellDecY,random));
			}

			makeSet({x, y});
		}
	}

	sort(edges.begin(), edges.end(),[](KruskalEdge x, KruskalEdge y){return x.weight < y.weight;});

	Maze* buildMaze = &maze;
	buildMaze->setWidth(width);
	buildMaze->setHeight(height);
	vector<SVGEdge> & mazeEdges = buildMaze->mazeEdgeArray();

	Node root(0,0);
	for(KruskalEdge e : edges)
	{
		int prevX = e.x1;
		int prevY = e.y1;
		int currentX = e.x2;
		int currentY = e.y2;

		Cell root1 = findM({prevX,prevY});
		Cell root2 = findM({currentX,currentY});
		if(!(root1 == root2))
		{
			mazeEdges.push_back(SVGEdge(prevX,prevY,currentX,currentY,"white"));
			unionM(root1,root2);

			root.addChild(Node(mazeEdges[currentX].x1,
					mazeEdges[currentY].y1));
		}
	}

	return root;
}
