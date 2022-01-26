#include "Rbpch.h"
#include "Application.h"
#include "Rabona/Events/ApplicationEvent.h"
#include "Rabona/Log.h"
#include "GLFW/glfw3.h"

namespace Rabona {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		
		while (true)
		{
			glClearColor(0.8, 0.9, 0.9, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
		
	}
}
