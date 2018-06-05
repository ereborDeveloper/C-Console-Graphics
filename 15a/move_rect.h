#include "Rect.h"


	class move_rect : public Rect2
	{
	public:
		move_rect() :Rect2(), step(0) {}
		move_rect(int st,int k) :Rect2(), step(st),koef(k) {
			if (k <= 0) koef = 1;
		}
		void setcre(int vel,int per)
		{
			cre = vel;
			pero = per;
		}
		void increase(color a)
		{
			color_type = a;
			set_rect({ (SHORT)(left_bottom.X - step), (SHORT)(left_bottom.Y - step / (koef)) }, { (SHORT)(right_top.X + step), (SHORT)(right_top.Y + step / (koef) )});
			draw_rect();
		}
		void decrease(color a)
		{
			color_type = a;
			set_rect({ (SHORT)(left_bottom.X + step), (SHORT)(left_bottom.Y + step / (koef) )}, { (SHORT)(right_top.X - step), (SHORT)(right_top.Y - step / (koef)) });
			draw_rect();
		}
	private:
		int step;
		int koef;
	};
