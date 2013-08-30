#pragma once
class Vertex2D
{
	public:
		Vertex2D();
		Vertex2D(float x, float y);

		~Vertex2D(void);

		float get_X(void);
		float get_Y(void);

	private:
		float x;
		float y;
};

