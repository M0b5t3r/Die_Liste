#include "DataLoader.h"


DataLoader::DataLoader(char* DataName)
{
	//Start Open
	FILE* fp = fopen(DataName, "r");

	//How Many Coords
	fscanf(fp, "%d", &i_countOfCoords);

	this->p_Coordinates = new Vertex3D[this->i_countOfCoords]; 
	for(int i = 0; i < i_countOfCoords; i++)
	{
		float tmpX, tmpY, tmpZ;

		fscanf(fp, "%f", &tmpX);
		fscanf(fp, "%f", &tmpY);
		fscanf(fp, "%f", &tmpZ);

		Vertex3D* v = new Vertex3D( tmpX, tmpY, tmpZ );

		this->p_Coordinates[i] = *v;
	}

	//How Many Texture Coords
	fscanf(fp, "%d", &i_countOfTextureCoords);

	this->p_TextureCoords = new Vertex2D[this->i_countOfTextureCoords];
	for(int i = 0; i < i_countOfTextureCoords; i++)
	{
		float tmpX, tmpY;

		fscanf(fp, "%f", &tmpX);
		fscanf(fp, "%f", &tmpY);

		Vertex2D* v = new Vertex2D( tmpX, tmpY);

		this->p_TextureCoords[i] = *v;
	}

	//How many Polygons
	fscanf(fp, "%d", &i_countOfPolygons);

	this->p_PolygonCoords = new Polygon3D[this->i_countOfPolygons];
	for(int i = 0; i < i_countOfPolygons; i++)
	{
		int tmpCount;
		int tmpRef, tmpTextureRef; 
		int tmpTexturePolygon;

		fscanf(fp, "%d", &tmpCount);
		
		Vertex3D* tmpv3D = new Vertex3D[tmpCount];
		Vertex2D* tmpv2D = new Vertex2D[tmpCount]; 

		for(int j = 0; j < tmpCount; j++)
		{
			fscanf(fp, "%d", &tmpRef);
			fscanf(fp, "%d", &tmpTextureRef);

			tmpv3D[j] = this->p_Coordinates[tmpRef];
			tmpv2D[j] = this->p_TextureCoords[tmpTextureRef];
		}

		fscanf(fp, "%d", &tmpTexturePolygon);

		this->p_PolygonCoords[i] = Polygon3D(tmpv3D,tmpv2D,tmpCount,tmpTexturePolygon);
	}

	//How many Textures
	fscanf(fp,"%d", &i_countOfTextures);

	this->p_Texture = new Texture2D[this->i_countOfTextures];
	for(int i = 0 ; i < i_countOfTextures ; i++)
	{
		//string buffer
		char* tmpString = new char[128];
		
		fscanf(fp, "%s", tmpString);

		this->p_Texture[i] = Texture2D(tmpString);
	}
	for(int i = 0; i < this->i_countOfPolygons; i++)
	{
		(this->p_PolygonCoords+i)->setTexture(
			( this->p_Texture + (this->p_PolygonCoords+i)->get_WhichTexture() )->get_TextureName() 
		);
	}

	/* //For Debug
	for(int x = 0; x < i_countOfCoords; x++)
	{
		Vertex3D tmp = p_Coordinates[x];
	}*/
	fclose(fp);
}

int DataLoader::get_CountOfPolygons()
{
	return this->i_countOfPolygons;
}

Polygon3D* DataLoader::get_Polygon3D()
{
	return this->p_PolygonCoords;
}


DataLoader::~DataLoader(void)
{
}
