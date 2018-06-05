class Stack
{
private:
	static const int MAX = 8;
	SHORT st[MAX];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	void push(SHORT var)
	{
		st[++top] = var;
	}
	SHORT pop()
	{
		return st[top--];
	}
};
class Stack2 :public Stack
{
private:
	int top;
	static const int MAX = 4;
	COORD st[MAX];
public:
	Stack2()
	{
		top = -1;
	}
	void push(COORD var)
	{
		Stack::push(var.X);
		Stack::push(var.Y);
		st[++top] = var;
		cout << "“очка с координатами ("<< var.X<< ","<<var.Y<< ") помещена в стек" << endl;
	}
	COORD pop()
	{
		cout << "“очка с координатами (" << Stack::pop() << "," << Stack::pop()<< ") извлечена из стека" << endl;
		return st[top--];
	}

};