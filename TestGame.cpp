#include"CommonFunction.h"
#include"MainObject.h"

#undef main

SDL_Surface* g_object;

bool Init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		{
			return false;
		}
		g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HIEGHT, SCREEN_BPP, SDL_SWSURFACE);
		if (g_screen == NULL)
		{
			return false;
		}
		return true;
	}



int main(int arc, char argv[])
{
	bool is_quit = false;
	if (Init() == false)
		return 0;
	g_background = SDLCommon::LoadImage("bkground3.png");
	if (g_background == NULL)
	{
		return 0;
	}
	SDLCommon::ApplySurface(g_background, g_screen, 0, 0);

	MainObject Human_Object;
	Human_Object.SetRect(300, 420);
	bool ret= Human_Object.LoadImg("plane80.png");
	if (!ret)
	{
		return 0;
	}
	Human_Object.Show(g_screen);


	
	while (!is_quit)
	{
		while(SDL_PollEvent(&g_event))
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
				break;
			}
			Human_Object.HandleInputAction(g_event);
		}

		SDLCommon::ApplySurface(g_background, g_screen, 0, 0);
		Human_Object.Show(g_screen);
		Human_Object.HandleMove();
		if (SDL_Flip(g_screen) == -1)
			return 0;
	}
	SDLCommon::CleanUp();
	SDL_Quit();
	return 1;
}