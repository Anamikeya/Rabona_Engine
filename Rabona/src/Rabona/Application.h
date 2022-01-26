#pragma once

#include "Rabona/Core.h"
#include "Events/Event.h"
#include "Rabona/Events/ApplicationEvent.h"
#include "Window.h"

namespace Rabona
{
	class RABONA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running;

	};

	Application* CreateApplication();
	//to be created on teh client that is the app in which 
	//the person is working
	
}

