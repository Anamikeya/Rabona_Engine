#include"window.h"
namespace rabona {

	namespace graphics
	{
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		
		void windowResize(GLFWwindow* window, int width, int height);
		
		Window::Window(const char* name, int width, int height)
		{
			m_Title = name;
			m_Width = width;
			m_Height = height;

			if (!init())
			{
				glfwTerminate();
			}
			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize" << std::endl;
				return false;

			}


			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "Failed to create a window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, windowResize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);
			std::cout << "OpenGL : " << glGetString(GL_VERSION) << std::endl;


			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW!" << std::endl;
			}
			return true;
		}
		bool Window::isKeyPressed(unsigned int Keycode) const
		{
			if (Keycode >= MAX_KEYS)
			{
				return false;
			}


			return m_Keys[Keycode];
		}
		bool Window::isMouseButtonPressed(unsigned int button) const
		{
			if (button >= MAX_BUTTONS)
			{
				return false;
			}
			return m_MouseButtons[button];
		} 
		void Window::getMousePosition(double& x, double& y) const
		{
			x = mx;
			y = my;
		}
		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}



		void Window::update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);


		}
		void windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);

		}
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window); 
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		
		}


		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			action = GLFW_RELEASE;
			win->m_Keys[key] = true;
		}
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
			 
		}



		



	}
}
