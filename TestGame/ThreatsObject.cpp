#include "ThreatsObject.h"

ThreatObject::ThreatObject()
{
	rect_.x = SCREEN_WIDTH;
	rect_.y = SCREEN_HEIGHT * 0.3;
	rect_.w = WIDTH_THREAT;
	rect_.h = HEIGHT_THREAT;

	x_val_ = 0;
	y_val_ = 0;
}

ThreatObject::~ThreatObject()
{
	if (p_amo_list_.size() > 0)
	{
		for (int i = 0; i < p_amo_list_.size(); i++)
		{
			AmoObject* p_amo = p_amo_list_.at(i);
			if (p_amo)
			{
				delete p_amo;
				p_amo = NULL;
			}
		}
		p_amo_list_.clear();
	}
	;
}

void ThreatObject::InitAmo(AmoObject* amo)
{
	if (amo)
	{
		bool ret = amo->LoadImg("sphere.png");
		if (ret) 
		{
			amo->set_is_move(true);
			amo->SetWidthHeight(WIDTH_AMO_SPHERE, HEIGHT_AMO_SPHERE);
			amo->set_type(AmoObject::SPHERE);
			amo->SetRect(rect_.x, rect_.y + rect_.h * 0.5);
			amo->set_x_val(8);
			p_amo_list_.push_back(amo);
		}
	}
}

void ThreatObject::MakeAmo(SDL_Surface* des, const int& x_limit, const int& y_limit)
{
	for (int i = 0; i < p_amo_list_.size(); i++)
	{
		AmoObject* p_amo = p_amo_list_.at(i);
		if (p_amo)
		{
			if (p_amo->get_is_move())
			{
				p_amo->Show(des);
				p_amo->HandleMoveRightToLeft();
			}
			else
			{
				p_amo->set_is_move(true);
				p_amo->SetRect(rect_.x, rect_.y + rect_.h * 0.5);
			}
		}
	}
}
void ThreatObject::HandleMove(const int& x_border, const int& y_border)
{
	rect_.x -= x_val_;

	if (rect_.x < 0)
	{
		rect_.x = SCREEN_WIDTH;
	}
}

void ThreatObject::HandleInputAction(SDL_Event events)
{
	;
}
