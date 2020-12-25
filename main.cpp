#include"graphics/window.h"

int main()
{
	using namespace rabona;
	using namespace graphics;

	Window window("Rabona", 800, 600);
	glClearColor(0.2f, 0.3, 0.9, 1.0f);

	GLuint vao;
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	{
		std::cout << "GLEW Loaded" << std::endl;

	}
		while (!window.closed())
		{

			window.clear();
			double x, y;
			window.getMousePosition(x, y);
			std::cout << x << "," << y << std::endl;
#if 1
			glBegin(GL_TRIANGLES);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.0f, 0.5f);
			glVertex2f(0.5f, -0.5f);
			glEnd();
			
#else
			glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		
#endif
			window.update();
		}
	system("PAUSE");
	std::cin.get();


}