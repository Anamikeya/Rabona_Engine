#pragma once

#ifdef RB_PLATFORM_WINDOWS

extern Rabona::Application* Rabona::CreateApplication();

int main(int argc, char** argv)
{
	Rabona::Log::Init();
	RB_CORE_WARN("Initialized Log");
	int a = 5;
	RB_INFO("Hello Var={0}", a);
	

	auto app = Rabona::CreateApplication();
	app->Run();
	delete app;
}

#endif