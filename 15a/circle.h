class ring
{
public:
	COORD center;
	int radius;

	ring() :center({ 260, 140 }), radius(100) {}
	ring(COORD cen, int rad) :center(cen), radius(rad){}
	
	int setcircle(COORD a, int r1)
	{
		radius = r1;
	}
private:
	double x, y;
};
class ellipse_ring:public ring
{
public:
	struct color
	{
		int r;
		int g;
		int b;
	};
	color color_type;
	int bradius;
	ellipse_ring():ring(),bradius(radius) {}
	ellipse_ring(COORD cen, int rad, int brad,color a):ring(cen, rad),bradius(brad),color_type(a) {}
	void show_ellipse(double accuracy, int pero, int width);
	void setellipse(COORD a, int r1, int r2, color b)
	{
		center = a;
		radius = r1;
		bradius = r2;
		color_type = b;
	}
private:
	double x, y;
};
void ellipse_ring::show_ellipse(double accuracy, int pero, int width)
{
	HANDLE	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HDC hDeviceContext;
	HWND hWindow;
	HPEN hPen;
	hWindow = NULL;
	hWindow = GetConsoleWindow();
	hDeviceContext = GetDC(hWindow);
	double y = 1;
	double x = 1;
	double t, t2, xx;

	while (y < 300)
	{
		x = 1;
		while (x < 650)
		{
			if (radius*radius - (y - center.Y)*(y - center.Y) >= 0)
				t = sqrt(radius*radius - (y - center.Y)*(y - center.Y));
			else
				t = 0;
			if ((radius + width)*(radius + width) - (y - center.Y)*(y - center.Y) >= 0)
				t2 = sqrt((radius + width)*(radius + width) - (y - center.Y)*(y - center.Y));
			else
				t2 = 0;
			if (((x*radius / bradius >= (t + center.X*radius / bradius+bradius/2)) && (x*radius / bradius < (t2 + center.X*radius / bradius + bradius / 2))) || ((x*radius / bradius > -t2 + center.X*radius / bradius + bradius / 2) && (x*radius / bradius <= -t + center.X*radius / bradius + bradius / 2)))
			{

				hPen = CreatePen(0, pero, RGB(color_type.r+y, color_type.g, color_type.b));
				SelectObject(hDeviceContext, hPen);
				POINT p_dot[] = { { x, y } };
				MoveToEx(hDeviceContext, p_dot[0].x, p_dot[0].y, NULL);
				LineTo(hDeviceContext, p_dot[0].x, p_dot[0].y);
				DeleteObject(hPen);
			}
			x += accuracy;
		}
		y += accuracy;
	}
}