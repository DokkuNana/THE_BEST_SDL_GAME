#include"MainObject.h"

MainObject::MainObject()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = WIDTH_MAIN_OBJECT;
	rect_.h = HEIGHT_MAIN_OBJECT;
	x_val_ = 0;
	y_val = 0;
}

MainObject::~MainObject()
{
	;
}

void MainObject::HandleInputAction(SDL_Event events)
{
	if (events.type == SDL_KEYDOWN) {
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val -= HEIGHT_MAIN_OBJECT / 8;
			break;
		case SDLK_DOWN:
			y_val += HEIGHT_MAIN_OBJECT / 8;
			break;
		case SDLK_LEFT:
			x_val_ -= WIDTH_MAIN_OBJECT / 8;
			break;
		case SDLK_RIGHT:
			x_val_ += WIDTH_MAIN_OBJECT / 8;
			break;
		}
	}
}

void MainObject::HandleMove()
{
	rect_.x += x_val_;

	if (rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH) {
		rect_.x -= x_val_;
	}

	rect_.y += y_val;

	if (rect_.y < 0 || rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HIEGHT) {
		rect_.y -= y_val;
	}
}