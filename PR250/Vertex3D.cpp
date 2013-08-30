#include "Vertex3D.h"

Vertex3D::Vertex3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vertex3D::Vertex3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vertex3D::get_X()
{
	return this->x;
}

float Vertex3D::get_Y()
{
	return this->y;
}

float Vertex3D::get_Z()
{
	return this->z;
}


Vertex3D::~Vertex3D(void)
{
}
