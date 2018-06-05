using namespace std;
class publication
{

public:
	publication():title(""),price(0.0) {}
	void get_data()
	{
		cout << "Введите название публикации: ";
		cin >> title;
		cout << "Введите стоимость: ";
		cin >> price;
	}
	void put_data()
	{
		cout << "\nЗаголовок: "<<title<<"\nЦена: "<<price;
	}
private:
	string title;
	float price;
};
class sales
{
protected:float sale[3];
public:
	void get_data()
	{
		cout << "\nВведите объем продаж за 3 месяца:\nМесяц 1:";
		cin >> sale[0];
		cout << "Месяц 2:";
		cin >> sale[1];
		cout << "Месяц 3:";
		cin >> sale[2];
	}
	void put_data()
	{
		cout << "\nПродажи за месяц 1:" << sale[0] << endl;
		cout << "Продажи за месяц 2:" << sale[1] << endl;
		cout << "Продажи за месяц 3:" << sale[2] << endl;
	}
};
class book :public publication,public sales
{
public:
	book() :publication(),pages(0) {}
	bool eight = false;
	void get_data()
	{
		publication::get_data();
		cout << "Введите число страниц: ";
		cin >> pages;
		if (eight)sales::get_data();
	}
	void put_data()
	{
		publication::put_data();
		cout << "\nСтраниц: " << pages;
		if (eight)sales::put_data();
	}
private:
	int pages;
};
class tape :public publication,public sales
{
public:
	tape() :publication(),time(0.0) {}
	bool eight = false;
	void get_data()
	{
		publication::get_data();
		cout << "Введите время звучания: ";
		cin >> time;
		if (eight)sales::get_data();
	}
	void put_data()
	{
		publication::put_data();
		cout << "\nВремя звучания: " << time;
		if (eight)sales::put_data();
	}
private:
	float time;
};
