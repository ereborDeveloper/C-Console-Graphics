#include "Fraction.h"
#include "move_rect.h"
#include "publication.h"
#include "circle.h"
#include "Stack.h"
#include "linklist.h"
#include "end_q.h"
using namespace std;
//13.1
void first();
void second(int,int,int,double,double,double,int);
void third();
void fourth();
void fifth();
void sixth();
void seventh();
void eight();
void fraction::print_fraction()
{
	cout << "Результат: ";
	if (q != 0)
	{

		if (p%q != 0)
			cout << p << "/" << q << endl;
		else
			cout << p / q << endl;
	}
	else
		cout << 0 << endl;
}