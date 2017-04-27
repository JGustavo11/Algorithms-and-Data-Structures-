//lab 6
//OOP - base/derived classes
//Jose Hernandez
#include <iostream>
using namespace std;

class cell
{
	int info;
	cell *next;

	cell(int i)
	{
		info = i; next = this;
	}

	cell(int i, cell *n)
	{
		info = i;
		next = n;
	}

	friend class list;
	friend class NC_list;
};

class NC_list
{
	cell *front;
	cell *rear;

	public:
		// check if empty
		int empty()
		{
			if (front == NULL)
				return 0;

			return rear == rear->next;
		}

		NC_list()
		{
			front = NULL;
			rear = NULL;
		}
	protected:
		void add(int);
		int get();
};
//add to front if its empy, else add to end , then point to next node 
void NC_list::add(int x)
{
	if (front == NULL)
	{
		front = new cell(0);
		front->info = x;
		rear = new cell(NULL);
		front->next = rear;
	}
	else
	{
		rear->info = x;
		rear = rear->next = new cell(NULL);
	}
}

// get info starting at front of list
int NC_list::get()
{
	if (front == NULL)
		return 0;
	int x = front->info;
	front = front->next;
	return x;
}

class queue: public NC_list	//dervied class
{
public:
	queue() {}
	int Qget()
	{
		return NC_list::get();
	}

	void Qput(int x)
	{
		add(x);

	}
};

class stack: private NC_list	//dervied class
{
public:
	stack() {}

	int Spop()
	{
		return get();
	}

	void Spush(int x)
	{
		NC_list::add(x);
	}
	using NC_list::empty;	//make inherited member empty public
};

int main()
{
	queue q1;
	stack s1;

	q1.Qput(3);
	q1.Qput(5);
	q1.Qput(7);

	cout << q1.Qget() << endl;
	cout << q1.Qget() << endl;
	cout << q1.Qget() << endl;
	cout << q1.Qget() << endl;

	s1.Spush(2);
	s1.Spush(4);
	s1.Spush(6);

	cout << s1.Spop() << endl;
	cout << s1.Spop() << endl;
	cout << s1.Spop() << endl;
	cout << s1.Spop() << endl;

	cout << q1.empty();
	cout << s1.empty();
	system("pause");
	return 0;
}
