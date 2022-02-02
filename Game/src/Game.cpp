#include<Rabona.h>

class ExampleLayer : public Rabona::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{}

	void OnUpdate() override
	{

		if (Rabona::Input::IsKeyPressed(RB_KEY_TAB))
			RB_INFO("Tab Key is Pressed!");
	}

	void OnEvent(Rabona::Event& event) override
	{
		if (event.GetEventType() == Rabona::EventType::KeyPressed)
		{
			Rabona::KeyPressedEvent& e = (Rabona::KeyPressedEvent&)event;
			RB_TRACE("{0}",(char)e.GetKeyCode());
		}
		//RB_TRACE("{0}", event);
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