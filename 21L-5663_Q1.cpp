#include<iostream>

using namespace std;

class stack
{
	struct node
	{
		node *next;
		int data;
	};
	node *top;

public:

	stack()
	{
		top = NULL;
	}

	void push(int val)
	{
		node *temp = new node;
		temp->data = val;
		if (top == NULL)
		{
			temp->next = NULL;
			top = temp;
		}

		else
		{
			temp->next = top;
			top = temp;
		}
	}

	void sort(node *t)
	{
		if (t->next != NULL)
		{
			sort(t->next);

			if (t->data > t->next->data)
			{
				int temp;
				temp = t->data;
				t->data = t->next->data;
				t->next->data = temp;
			}
			sort(t->next);
		}
	}

	node*t()
	{
		return top;
	}

	void display()
	{
		node*cur = top;
		while (cur != NULL)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};

int main()
{
	stack s;
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);
	s.push(10);

	cout << "The stack is : ";
	s.display();
	cout << "The stack after sorting is : ";
	s.sort(s.t());
	s.display();
	cout << "endl";

	system("pause");
	return 0;
}