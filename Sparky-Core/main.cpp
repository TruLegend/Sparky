#include "inc\graphics\Window.h"

int main()
{
	using namespace sparky;
	using namespace graphics;

	Window window("Sparky", 1280, 720);
	glClearColor(0.2, 0.3, 0.8, 1);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Vector2 vector2d(1, 2);
	Vector3 vector3d(1, 2, 3);
	Vector4 color(1, 2, 3, 4);

	vector2d += 10;
	vector3d += 5;

	while (!window.Closed())
	{
		window.Clear();
		
		std::cout << vector2d << std::endl;

		float x, y;
		window.getMousePosition(x, y);
		std::cout << x << ", " << y << std::endl;

		glBegin(GL_QUADS);
		glVertex2d(-0.5, -0.5);
		glVertex2d(-0.5,  0.5);
		glVertex2d( 0.5,  0.5);
		glVertex2d( 0.5, -0.5);
		glEnd();

		//glDrawArrays(GL_ARRAY_BUFFER, 0, 0);

		window.Update();
	}

	return 0;
}