#pragma once

#include "Rabona/Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Rabona
{
	class RABONA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running;

	};

	Application* CreateApplication();
	//to be created on teh client that is the app in which 
	//the person is working
	
}

