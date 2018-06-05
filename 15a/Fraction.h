

class fraction
{
public:
	long p, q;
	fraction() :p(0), q(1)
	{}
	fraction(int a, int b) :p(a), q(b)
	{}
	void print_fraction();
	fraction less()
	{
		long min = p;
		if (abs(p) < abs(q))
			min = abs(p);
		else min = abs(q);

		for (int i = 2; i <= min; i++)
		{
			//cout << i;
			while (abs(p) % i == 0 && abs(q) % i == 0)
			{
				p /= i;
				q /= i;
			}
		}
		return *this;
	}
	const fraction operator+(const fraction& b) const {
	
		return fraction(p*b.q + b.p*q, q*b.q);
	}
	const fraction operator-(const fraction& b) const {

		return fraction(p*b.q - b.p*q, q*b.q);
	}
	const fraction operator*(const fraction& b) const {

		return fraction(p*b.p, q*b.q);
	}
	const fraction operator/(const fraction& b) const {
		if (b.q != 0)
		{
			return fraction(p*b.q, b.p*q);
		}
		else 
		{
			std::cout << "Операция не выполнена: Деление на ноль!" << std::endl;
			return fraction(p, q); 
		}
	}
};

class fraction_full :public fraction
{
public:
	fraction_full() :fraction() {}
	fraction_full(int p, int q) :fraction(p, q) {}
	fraction_full operator^(const int n){
		return fraction_full(pow(p, n), pow(q, n));
	}
	const bool operator>(const fraction_full& b)const {
		return (p*b.q > b.p*q) ? true : false;
	}
	const bool operator<(const fraction_full& b)const {
		return (p*b.q < b.p*q) ? true : false;
	}
	const bool operator==(const fraction_full& b)const {
		return (p*b.q == b.p*q) ? true : false;
	}
	const bool operator!=(const fraction_full& b)const {
		return (p*b.q != b.p*q) ? true : false;
	}
};