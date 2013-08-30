#include "Polygon3D.h"


Polygon3D::Polygon3D()
{
	this->countOfPoints = 0;
	this->coords= 0;
	this->textureCoords = 0;
	this->whichTexture = 0;
	this->texture = picture();
}

Polygon3D::Polygon3D(Vertex3D* v3D, Vertex2D* v2D, int countOfPoints, int whichTexture  )
{
	this->coords = v3D;
	this->textureCoords = v2D;
	this->countOfPoints = countOfPoints;
	this->whichTexture = whichTexture;
	this->texture = picture();
}

void Polygon3D::DrawPolygon()
{
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, texture.xsize, texture.ysize, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.content ); //Aussehen der Textur festlegen
	glColor3d(1,1,1);

	glBegin( GL_POLYGON);
	for(int i = 0; i < countOfPoints; i++)
	{
		glTexCoord2d( this->textureCoords->get_X() , this->textureCoords->get_Y() );
		glVertex3d( (this->coords+i)->get_X(),(this->coords+i)->get_Y(),(this->coords+i)->get_Z() - 4 );
	}
	glEnd();
}

void Polygon3D::setTexture(char* textureName)
{
	this->texture.load(textureName);
}

int Polygon3D::get_WhichTexture(void)
{
	return this->whichTexture;
}

Polygon3D::~Polygon3D(void)
{
}
