#include"graphics/window.h"
#include<iostream>
#include<GLFW/glfw3.h>
int main()
{
	using namespace rabona;
	using namespace graphics;

	Window window("Rabona", 800, 600);
	glClearColor(0.2f, 0.3, 0.9, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << window.getWidth() << " , " << window.getHeight() << std::endl;
	
	while (!window.closed())
	{
		
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.update();
	}
	system("PAUSE");
	std::cin.get();


}