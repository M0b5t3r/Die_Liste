#include "Texture2D.h"


Texture2D::Texture2D()
{
	this->textureName[0] = '\0';
}

Texture2D::Texture2D(char* textureName)
{
	sscanf( textureName, "%s", this->textureName );
	this->p_textures.load(textureName);
}

char* Texture2D::get_TextureName()
{
	return this->textureName;
}


Texture2D::~Texture2D(void)
{
}
