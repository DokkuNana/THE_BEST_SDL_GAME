#include"CommonFunction.h"
#include"MainObject.h"
#include "ThreatsObject.h"
#undef main

SDL_Surface* g_object;

bool Init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		{
			return false;
		}
		g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
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
	g_background = SDLCommon::LoadImage("bk1.png");
	if (g_background == NULL)
	{
		return 0;
	}
	SDLCommon::ApplySurface(g_background, g_screen, 0, 0);

	MainObject Human_Object;
	Human_Object.SetRect(300, 420);
	bool ret= Human_Object.LoadImg("plane_fly.png");
	if (!ret)
	{
		return 0;
	}
	Human_Object.Show(g_screen);

	ThreatObject* threats = new ThreatObject[NUM_THREATS];

	for (int i = 0; i < NUM_THREATS; i++)
	{
		ThreatObject* threat = (threats + i);
		if (threat)
		{
			ret = threat->LoadImg("af1.png");
			if (ret == false)
			{
				return 0;
			}

			int rand_y = rand() % 600;
			if (rand_y > SCREEN_HEIGHT - 100)
			{
				rand_y = SCREEN_HEIGHT * 0.3;
			}

			threat->SetRect(SCREEN_WIDTH + i * 400, rand_y);
			threat->set_x_val(3);

			AmoObject* p_amo = new AmoObject();
			threat->InitAmo(p_amo);
		}
	}
	

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

		// Apply Background
		SDLCommon::ApplySurface(g_background, g_screen, 0, 0);

		//Implement main objects
		Human_Object.Show(g_screen);
		Human_Object.HandleMove();
		Human_Object.MakeAmo(g_screen);
		
		

		// Init Threats

		for (int i = 0; i < NUM_THREATS; i++)
		{
			ThreatObject* threat = (threats + i);
			if (threat)
			{
				threat->Show(g_screen);
				threat->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
				threat->MakeAmo(g_screen, SCREEN_WIDTH, SCREEN_HEIGHT);
			}
		}

		if (SDL_Flip(g_screen) == -1)
			return 0;
	}

	delete[] threats;
	SDLCommon::CleanUp();
	SDL_Quit();
	return 1;
}