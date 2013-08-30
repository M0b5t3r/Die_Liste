#pragma once

#include <stdio.h>

#include "picture.h"

class Texture2D
{
	public:
		Texture2D();
		Texture2D(char* textureName);

		char* get_TextureName(void);

		~Texture2D(void);

	private:
		char textureName[128];
		picture p_textures;
};

