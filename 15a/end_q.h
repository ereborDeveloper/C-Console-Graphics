
class end_list :public linklist
{
private:
	link* first;
	link* last;
	int i = 0;
public:
	end_list()
	{
		first = NULL;
	}
	void additem(int k)
	{
		link* newlink = new link;
		newlink->data = k;
		newlink->next = NULL;
		cout << newlink->data<<endl;
		if (!first)
		{
			first = newlink;
			last = first;	
		}
		else {
			last->next = newlink;
			last = newlink;
		}
	}
	~end_list()
	{
		while (first)
		{
			link* ab = first->next;
			cout << "Ёлемент " << first->data << " удален" << endl;
			delete first;
			first = ab;
		}
	}
};