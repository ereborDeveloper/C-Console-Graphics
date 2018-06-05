#include <typeinfo>
#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip> 
#include <conio.h>
#include <stdio.h>
#include "main.h"
using namespace std;

#define PRINTER(name) printer(#name, (name))
int main()
{
	book d;
	
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int getche = 0,getche2=0;

	while (getche != 27)
	{
		cout << "1. Дроби extended\n2. Rect extended\n3. Publication\n4. Ellipse\n5. Очистка\n6. Стэк\n7. Связный список extended\n8. Publication extended" << endl;
		getche = _getche();
		system("cls");
		if (getche == 49)
		{
			cout << "1. Дроби extended" << endl;
			first();
			
			
		}
		if (getche == 50)
		{
			int a,b,c;
			double d, e, f;
			int z;
			cout << "2. Rect extended" << endl;
			cout << "Введите: step, i, k, r, g, b:" << endl;
			cin >> a >> b >> c >> d >> e >> f;
			cout << "Введите число повторений: ";
			cin>>z;
				second(a, b, c, d, e, f,z);
				cout << "\n\nLoop - any key" << endl;
				cout << "Exit - ESC" << endl;
				getche2 = _getche();
				
				while (getche2 != 27)
				{
					second(a, b, c, d, e, f, z);
				}

		}
		if (getche == 51)
		{
			cout << "3. Publication" << endl;
			third();
			getche2 = _getche();
			while (getche2 != 27)
			{
				third();
				getche2 = _getche();
			}
		}
		if (getche == 52)
		{
			cout << "4. Ellipse" << endl;
			fourth();
			cout << "\n\nLoop - any key" << endl;
			cout << "Exit - ESC" << endl;
			getche2 = _getche();

			while (getche2 != 27)
			{
				fourth();
			}
		}
		if (getche == 53)
		{
			Rect2 b({ 0,0 }, { 600,300 }, { 0,0,0 });
			b.draw_rect();
		}
		if (getche == 54)
		{
			cout << "6. Stack extended" << endl;
			sixth();
			while (_getche() != 27)
			{
				_getche();
			}
		}
		if (getche == 55)
		{
			cout << "7. Связный список extended" << endl;
			seventh();
			while (_getche() != 27)
			{
				_getche();
			}
		}
		if (getche == 56)
		{
			cout << "8. Publication extended" << endl;
			eight();
			while (_getche() != 27)
			{
				_getche();
			}
		}
		
			cout << "Выполнено успешно" << endl;
			Sleep(200);
			system("cls");
		
	}
	system("pause");
	return 0;
}
//16.1
void first()
{

	long a, b, c, d;
	int key = 0;
	char s;
	string sign;

	cout << "Введите дробь в формате 'a/b' ";
	cin >> a >> s >> b;
	cout << "Отлично! Дробь введена, теперь сделайте с ней что-нибудь" << endl;
	fraction one(a, b);
	while (sign != "выход")
	{
		cin >> sign;
		if (sign != "выход")
		{
			
				if (sign == "+" || sign == "plus" || sign == "плюс" || sign == "сложить")
				{
					cout << "дробь (c/d): ";
					cin >> c >> s >> d;
					fraction two(c, d);
					one=one + two;
					one.less();
					one.print_fraction();
				}
				if (sign == "-" || sign == "minus" || sign == "минус" || sign == "вычесть")
				{
					cout << "дробь (c/d): ";
					cin >> c >> s >> d;
					fraction two(c, d);
					one=one - two;
					one.less();
					one.print_fraction();
				}
				if (sign == "*" || sign == "x" || sign == "multiply" || sign == "умножить")
				{
					cout << "дробь (c/d): ";
					cin >> c >> s >> d;
					fraction two(c, d);
					one=one*two;
					one.less();
					one.print_fraction();
				}
				if (sign == "/" || sign == "divide" || sign == "разделить")
				{
					cout << "дробь (c/d): ";
					cin >> c >> s >> d;
					fraction two(c, d);
					one=one / two;
					one.less();
					one.print_fraction();
				}
				if (sign == "^" || sign == "pow" || sign == "степень")
				{

					cout << "степерь n: ";
					int n;
					cin >> n;
					fraction_full o(one.p,one.q);
					o = o^n;
					o.print_fraction();
					one.p = o.p;
					one.q = o.q;
				}
				if (sign == ">" || sign == "more" || sign == "больше")
				{

					cout << "чем дробь (c/d): ";
					cin >> c >> s >> d;
					fraction_full o(c,d);
					fraction_full o2(one.p, one.q);
					cout<< (o2> o)<<endl;
				}
				if (sign == "<" || sign == "less" || sign == "меньше")
				{

					cout << "чем дробь (c/d): ";
					cin >> c >> s >> d;
					fraction_full o(c, d);
					fraction_full o2(one.p, one.q);
					cout << (o2< o) << endl;
				}
				if (sign == "="||sign == "==" || sign == "equals" || sign == "равно")
				{

					cout << "дроби (c/d): ";
					cin >> c >> s >> d;
					fraction_full o(c, d);
					fraction_full o2(one.p, one.q);
					cout << (o2== o) << endl;
				}
				if (sign == "!=" || sign == "notequals" || sign == "неравно")
				{

					cout << "дроби (c/d): ";
					cin >> c >> s >> d;
					fraction_full o(c, d);
					fraction_full o2(one.p, one.q);
					cout << (o2!= o) << endl;
				}

				if (sign == "упростить")
				{
					one.less();
					one.print_fraction();
					cout << "Дробь максимально упрощена" << endl;
				}
		}
	}
}
//16.2
void second(int k, int ii, int koef, double r, double g, double b,int z)
{
	move_rect a(k, koef);
	
	
		for (int i = 1; i < ii; i++)
		{
			a.increase({ (int)((((rand()) % i) - ii - 1)*r / 100), (int)(((rand() % i) - ii - 1)*g / 100), (int)(((rand() % i) - ii - 1)*b / 100) });
			Sleep(10);
		}
	
	while (z > 0)
	{
		COORD one, two;
		one = a.left_bottom;
		two = a.right_top;
		
		for (int i = ii; i > 0; i--)
		{
			a.setcre(i,i);
			a.decrease({ (int)abs(-i*k*rand() % 20 + r), (int)abs(-i*k + g), (int)abs(-i*k + b) });
			Sleep(10);
		}
		//
		a.set_rect(one, two);
		z--;
	}
}
void third()
{
	book a;
	tape b;
	a.get_data();
	b.get_data();
	a.put_data();
	b.put_data();
}
void fourth()
{
	ellipse_ring a,b;
	int x=rand()%30, xx=rand()%30, xxx=rand()%50;
	a.setellipse({ 270,140 }, 20, 1, { rand(),rand(),rand() }); 
	for (int i = 1; i < 20; i++)
	{
		a.center.X -= a.bradius / a.radius;
		b.setellipse({ 260,140 }, 1, 1, {x+i*2,abs(xx-i*2),xxx });
		b.show_ellipse(15, 25, 450);
		a.bradius = i;
		a.show_ellipse(1, 3, 20);
		Sleep(100);
	}
	a.setellipse({ a.center.X,140 }, 20, 1, { rand(),rand(),rand() });
	for (int i = 20; i > 1; i--)
	{
		a.center.X += a.bradius / a.radius;
		b.setellipse({ 260,140 }, 1, 1, { x + i * 2,abs(xx-i*2),xxx });
		a.bradius = i;
		a.show_ellipse(1, 3, 20);
		Sleep(100);
		b.show_ellipse(15, 25, 450);
	}
}
void sixth()
{
	Stack2 b;
	COORD a[4] = { {1,2},{3,4},{5,6},{7,8} };
	//a[9].color_type = { 0, 55, 55 };
	cout
		<< "input:" << endl;
	for (int i = 0; i < 4; i++)
	{
		
		b.push(a[i]);
	}
	cout << endl << "output:" << endl;
	for (int i = 0; i < 4; i++)
		b.pop();
}
void seventh()
{
	linklist list;
	
	list.additem(25);
	list.additem(36);
	list.additem(49);
	list.additem(64);
	
	list.display();
	end_list l;
	l.additem(25);
	l.additem(36);
	l.additem(49);
	l.additem(64);
	l.display();
}
void eight()
{

	book a;
	tape b;
	a.eight = true;
	b.eight = true;
	a.get_data();
	b.get_data();
	a.put_data();
	b.put_data();
	
}