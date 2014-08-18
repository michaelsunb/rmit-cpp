/*
 * DepthBuilder.hpp
 *
 *  Created on: 16 Aug 2014
 *      Author: Michaelsun Baluyos
 *       Email: s3110401@student.rmit.edu.au
 */

#ifndef DEPTHBUILDER_HPP_
#define DEPTHBUILDER_HPP_


#include "Assignment1.hpp"     /* srand, rand */ // http://max99x.com/school/maze-generator
#include "Edges.hpp" // http://www.cplusplus.com/forum/beginner/41707/
#include "Maze.hpp"

class DepthBuilder
{
private:
	enum DIR { xIncrement, yIncrement, xDecrement, yDecrement};
public:
	DepthBuilder();
	void Build(Maze maze,int width, int height);
};



#endif /* DEPTHBUILDER_HPP_ */
