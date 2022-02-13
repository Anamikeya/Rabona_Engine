#pragma once
#include "Rabona/Core.h"

#include "Rabona/LayerStack.h"
#include "Events/Event.h"
#include "Rabona/Events/ApplicationEvent.h"
#include "Rabona/ImGui/ImGuiLayer.h"
#include "Window.h"

namespace Rabona
{
	class RABONA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void Run();
		void OnEvent(Event& e);
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running;

		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;


	};

	Application* CreateApplication();
	//to be created on teh client that is the app in which 
	//the person is working
	
}

