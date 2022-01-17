#include<Rabona.h>

class Game : public Rabona::Application
{
public:
	Game()
	{

	}
	~Game()
	{

	}
};


Rabona::Application* Rabona::CreateApplication()
{
	return new Game();
}