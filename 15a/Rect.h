
HANDLE	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
HDC hDeviceContext;
CONSOLE_CURSOR_INFO curs;
HWND hWindow;
HPEN hPen;

class Rect2
{
public:
	struct color
	{
		int r;
		int g;
		int b;
	};
	color color_type;
	Rect2(COORD one = { 260, 140 }, COORD two = { 300, 160 }, color red = { 255, 0, 0 }) :left_bottom(one), right_top(two), color_type(red) {}
	void set_rect(COORD one, COORD two)
	{
		left_bottom = one;
		right_top = two;
	}
	void draw_rect()
	{
		hWindow = NULL;
		hWindow = GetConsoleWindow();
		hDeviceContext = GetDC(hWindow);
		hPen = CreatePen(0, pero+1, RGB(color_type.r, color_type.g, color_type.b));
		SelectObject(hDeviceContext, hPen);
		for (int i = left_bottom.Y; i < right_top.Y; i+=cre)
		{
			MoveToEx(hDeviceContext, left_bottom.X, i, NULL);
			LineTo(hDeviceContext, right_top.X, i);
		}
		DeleteObject(hPen);
	}
	void get_rect(COORD *one, COORD *two)
	{
		left_bottom = *one;
		right_top = *two;
	}
	
	void decrease_rect()
	{
		left_bottom.X += 5;
		left_bottom.Y += 5;
		right_top.X -= 5;
		right_top.Y -= 5;
	}
	COORD ret()
	{
		return left_bottom;
	}
	COORD left_bottom;
	COORD right_top;
private:
	double x, y;
protected:
	int cre=1;
	int pero=1;
};
