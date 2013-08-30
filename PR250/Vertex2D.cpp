#include "Vertex2D.h"

Vertex2D::Vertex2D()
{
	this->x = 0;
	this->y = 0;
}

Vertex2D::Vertex2D(float x , float y)
{
	this->x = x;
	this->y = y;
}

float Vertex2D::get_X()
{
	return this->x;
}

float Vertex2D::get_Y()
{
	return this->y;
}

Vertex2D::~Vertex2D(void)
{

}
