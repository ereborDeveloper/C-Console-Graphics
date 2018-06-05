struct link
{
	int data;
	link* next;
};

class linklist
{
private:
	link* first;
public:
	linklist()
	{
		first = NULL;
	}
	~linklist()
	{
		while (first)
		{
			link* ab = first->next;
			cout << "Ёлемент " << first->data << " удален" << endl;
			delete first;
			first = ab;
		}
	}
	void additem(int d);
	void display();
};
void linklist::additem(int d)
{
	link* newlink = new link;
	newlink->data = d;
	newlink->next = first;
	first = newlink;
}
void linklist::display()
{
	link* current = first;
	while (current)
	{
		cout << current->data << endl;
		current = current->next;
	}
}