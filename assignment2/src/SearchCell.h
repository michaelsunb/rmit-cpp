/*
 * SearchCell.h
 *
 *  Created on: 9 Oct 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#pragma once

#include <math.h>

#define WORLDSIZE 64

struct SearchCell
{
	int x;
	int y;
	int id;

	SearchCell *parent;

	float G;
	float H;

	SearchCell() : x(0), y(0), parent(nullptr), id(0), G(0), H(0) {};
	SearchCell(int x,int y, SearchCell * parent = nullptr)
	: x(x), y(y), parent(parent), id(x*WORLDSIZE), G(0), H(0) {};

	float getF() { return G + H; };
	float mamHattanDetance (SearchCell * nodeEnd)
	{
		float x = (float) (fabs((float)(this->x - nodeEnd->x)));
		float y = (float) (fabs((float)(this->y - nodeEnd->y)));

		return x + y;
	}
};
