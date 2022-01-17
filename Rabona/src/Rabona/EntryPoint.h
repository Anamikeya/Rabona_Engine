#pragma once

#ifdef RB_PLATFORM_WINDOWS

extern Rabona::Application* Rabona::CreateApplication();

void main(int argc, char** argv)
{

	auto app = Rabona::CreateApplication();
	app->Run();
	delete app;
}

#endif