#pragma once

#include <gl\glew.h>
#include <stdio.h>

#include "Vertex2D.h"
#include "Vertex3D.h"
#include "picture.h"

class Vertex3D;
class Vertex2D;

class Polygon3D
{
public:
	Polygon3D();
	~Polygon3D(void);

	Polygon3D(Vertex3D* v3D, Vertex2D* v2D, int countOfPoints, int whichTexture  );
	void DrawPolygon();
	void setTexture(char* textureName);

	int get_WhichTexture(void);

private:
	int countOfPoints;
	int whichTexture;

	Vertex3D* coords;
	Vertex2D* textureCoords;
	picture texture;
};

