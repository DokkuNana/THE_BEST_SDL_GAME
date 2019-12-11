 #include<SDL_image.h>
#include<string>
using namespace std;

SDL_Surface* LoadImage(string file_path)
{
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;

	load_image = IMG_Load(file_path.c_str());
	if (load_image != NULL) {
		optimize_image = SDL_DisplayFormat(load_image);
		SDL_FreeSurface(load_image);
	}
	return optimize_image;
}

int main(int arc, char* argv[])
{
	SDL_Surface* screen;
	SDL_Surface* image;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return 1;

	screen = SDL_SetVideoMode(1200, 600, 32, SDL_SWSURFACE);
	image = LoadImage("bkground1.png");

	SDL_BlitSurface(image, NULL, screen, NULL);
	
	SDL_Flip(screen);
	SDL_Delay(5000);
	SDL_FreeSurface(image);
	SDL_Quit();

	return 0;
}
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
bool Init()

 int main(int arc, char* argv[])
{
  bool is_quit = false;
  if (Init() == false)
   return 0;
 
  g_bkground = LoadImage("bkground.png");
  if (g_bkground == NULL)
  {
    return 0;
  }
 
  ApplySurface(g_bkground, g_screen, 0, 0);
 
  while (!is_quit) 
  {
    while (SDL_PollEvent(&g_even)) 
    {
      if (g_even.type == SDL_QUIT)
      {
        is_quit = true;
        break;
      }
    }
    if ( SDL_Flip(g_screen) == -1)
    return 0;
  }
  CleanUp();
  SDL_Quit();
  return 1;
}
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
 SDL_Surface* LoadImage(std::string file_path)
{
  SDL_Surface * load_image = NULL;
  SDL_Surface* optimize_image = NULL;
  load_image = IMG_Load(file_path.c_str());
  if (load_image != NULL)
  {
    optimize_image= SDL_DisplayFormat(load_image);
    SDL_FreeSurface(load_image);
  }
  return optimize_image;
}
void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, NULL, des, &offset);
}
void CleanUp()
{
  SDL_FreeSurface(g_screen);
  SDL_FreeSurface(g_bkground);
}
 int main(int arc, char* argv[])
{
  bool is_quit = false;
  if (Init() == false)
   return 0;
 
  g_bkground = LoadImage("bkground.png");
  if (g_bkground == NULL)
  {
    return 0;
  }
 
  ApplySurface(g_bkground, g_screen, 0, 0);
 
  while (!is_quit) 
  {
    while (SDL_PollEvent(&g_even)) 
    {
      if (g_even.type == SDL_QUIT)
      {
        is_quit = true;
        break;
      }
    }
    if ( SDL_Flip(g_screen) == -1)
    return 0;
  }
  CleanUp();
  SDL_Quit();
  return 1;
}