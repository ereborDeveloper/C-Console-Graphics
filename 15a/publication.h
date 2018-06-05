using namespace std;
class publication
{

public:
	publication():title(""),price(0.0) {}
	void get_data()
	{
		cout << "������� �������� ����������: ";
		cin >> title;
		cout << "������� ���������: ";
		cin >> price;
	}
	void put_data()
	{
		cout << "\n���������: "<<title<<"\n����: "<<price;
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
		cout << "\n������� ����� ������ �� 3 ������:\n����� 1:";
		cin >> sale[0];
		cout << "����� 2:";
		cin >> sale[1];
		cout << "����� 3:";
		cin >> sale[2];
	}
	void put_data()
	{
		cout << "\n������� �� ����� 1:" << sale[0] << endl;
		cout << "������� �� ����� 2:" << sale[1] << endl;
		cout << "������� �� ����� 3:" << sale[2] << endl;
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
		cout << "������� ����� �������: ";
		cin >> pages;
		if (eight)sales::get_data();
	}
	void put_data()
	{
		publication::put_data();
		cout << "\n�������: " << pages;
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
		cout << "������� ����� ��������: ";
		cin >> time;
		if (eight)sales::get_data();
	}
	void put_data()
	{
		publication::put_data();
		cout << "\n����� ��������: " << time;
		if (eight)sales::put_data();
	}
private:
	float time;
};
