/*
 * Cell.h
 *
 *  Created on: 18 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#pragma once
#include <vector>

struct Cell
{
	/**
	 * Need x and y to get 
	 * current position
	 */
	int x2;
	int y2;

	Cell(int x2,int y2): x2(x2), y2(y2) {};
	Cell(): x2(0), y2(0) {};

	/**
	 * Operator overload the
	 * equals-equals to detect
	 * if two cells equal each other
	 */
	bool operator==(Cell b)
	{
		if((b.x2 == x2) && (b.y2 == y2))
		{
			return true;
		}
		return false;
	}
};

struct VisitedCell : public Cell
{
	bool visited;

	VisitedCell(bool iVisited,int iX2, int iY2)
	{
		visited = iVisited;
		x2 = iX2;
		y2 = iY2;
	}

	VisitedCell()
	{
		visited = false;
		x2 = 0;
		y2 = 0;
	}
};

/**
 * Node so that x and y
 * can have children and
 * the children can have
 * children
 */
struct Node : public Cell
{
	std::vector<Node> children;

	Node(int x,int y)
	{
		x2 = x;
		y2 = y;
	}

	Node()
	{
		x2 = 0;
		y2 = 0;
	}

	void addChild(Node n)
	{
		children.push_back(n);
		return;
	}

	std::vector<Node> getChildren() { return children; }
};
