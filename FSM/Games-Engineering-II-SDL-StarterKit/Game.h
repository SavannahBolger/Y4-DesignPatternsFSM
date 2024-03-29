#ifndef GAME_H
#define GAME_H
#include "Debug.h"
#include <SDL.h>
#include <SDL_image.h>

class Game
{
public:
	Game();
	~Game();
	bool Initialize(const char*, int, int, int, int, int);
	void LoadContent();
	void UnloadContent();
	void Render();
	void Update();
	void HandleEvents();
	bool IsRunning();
	void CleanUp();
private:
	bool m_running;
	SDL_Window* m_p_Window;
	SDL_Renderer* m_p_Renderer;
	SDL_Texture* m_p_Texture;
	SDL_Rect m_Source;
	SDL_Rect m_Destination;
	SDL_Surface* m_p_Surface;
	SDL_Rect srcrect = { 0, 0, 86, 86 };
	SDL_Rect dstrect = { 10, 10, 86, 86 };
};
#endif

