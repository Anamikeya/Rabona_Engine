#pragma once
#include"Core.h"

namespace Rabona
{
	class RABONA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//to be created on teh client that is the app in which 
	//the person is working
	Application* CreateApplication();
}

