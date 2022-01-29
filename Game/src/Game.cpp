#include<Rabona.h>

class ExampleLayer : public Rabona::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{}

	void OnUpdate() override
	{
		RB_INFO("ExampleLayer::Update");
	}

	void OnEvent(Rabona::Event& event) override
	{
		RB_TRACE("{0}", event);
	}
};

class Game : public Rabona::Application
{
public:
	Game()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Rabona::ImGuiLayer());
	}
	~Game()
	{

	}
};
Rabona::Application* Rabona::CreateApplication()
{
	return new Game();
}