#pragma once
class Vertex3D
{
	public:
		Vertex3D();
		Vertex3D(float x, float y, float z);

		~Vertex3D(void);

		float get_X(void);
		float get_Y(void);
		float get_Z(void);

	private:
		float x;
		float y;
		float z;
};

