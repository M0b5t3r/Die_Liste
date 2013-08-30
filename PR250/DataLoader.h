#pragma once

#include <stdio.h>

#include "Vertex3D.h"
#include "Vertex2D.h"
#include "Polygon3D.h"
#include "Texture2D.h"

class DataLoader
{
	public:
		DataLoader(char* DataName);
		~DataLoader(void);

		int get_CountOfPolygons(void);
		Polygon3D* get_Polygon3D(void);

	private:
		int i_countOfCoords;
		Vertex3D* p_Coordinates;

		int i_countOfTextureCoords;
		Vertex2D* p_TextureCoords;

		int i_countOfPolygons;
		Polygon3D* p_PolygonCoords;

		int i_countOfTextures;
		Texture2D* p_Texture;
};

