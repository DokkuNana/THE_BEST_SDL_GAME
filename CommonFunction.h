#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <iostream>
#include<windows.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HIEGHT = 600;
const int SCREEN_BPP = 32;

static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_background = NULL;
static SDL_Event g_event;

namespace SDLCommon
{
	SDL_Surface* LoadImage(std::string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();
}
#endif