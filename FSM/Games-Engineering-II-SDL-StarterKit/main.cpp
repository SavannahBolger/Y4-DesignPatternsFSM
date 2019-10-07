#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include <iostream>
#include <thread>
#include <string>

#include <TinyXML2.h>

#include <SDL.h>
#include <SDL_image.h>

#include <Game.h>
#include <Player.h>

using namespace std;
using namespace tinyxml2;

int main(int argc, char** argv){

	DEBUG_MSG("Game Object Created");

	Player* player = new Player();

	Game* game = new Game();

	XMLDocument doc;
	doc.LoadFile("Levels.xml");

	const char* temp = doc.FirstChildElement("root")->FirstChildElement("level1")->FirstChildElement("player")->FirstChildElement("health")->GetText();

	DEBUG_MSG(temp);

	//Adjust screen positions as needed
	DEBUG_MSG("Game Initialising");
	game->Initialize("SDL StarterKit",300,100,800,600, SDL_WINDOW_INPUT_FOCUS);
	
	DEBUG_MSG("Loading Content");
	game->LoadContent();


	DEBUG_MSG("Game Loop Starting......");
	while(game->IsRunning())
	{
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	DEBUG_MSG("Calling Cleanup");
	game->CleanUp();
	game->UnloadContent();
	
	return 0;
}