#ifndef MAIN_OBJECT_M_
#define MAIN_OBJECT_M_

#include"CommonFunction.h"
#include"BaseObject.h"

#define WIDTH_MAIN_OBJECT 80
#define HEIGHT_MAIN_OBJECT 46

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	void HandleInputAction(SDL_Event events);
	void HandleMove();
private:
	int x_val_;
	int y_val;
};
#endif // !MAIN_OBJECT_M_