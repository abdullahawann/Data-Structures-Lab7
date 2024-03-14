#include <iostream>
using namespace std;

class doublylinkedlist;

struct node
{
	friend class doublylinkedlist;
	node *next, *prev;
	char data;
};

class doublylinkedlist
{
	node *head, *tail;

public:
	doublylinkedlist()
	{
		head = NULL;
		tail = NULL;
	}

	void input(char val)
	{
		node *temp = new node;
		temp->data = val;
		if (head == NULL)
		{
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
			tail = temp;
		}

		else 
		{
			temp->next = head;
			head->prev = temp;
			temp->prev = NULL;
			head = temp;
		}
	}

	bool palindrome(node *h, node *t)
	{
		if (h != t && h->next != t)
		{
			if (h->data == t->data)
			{
				palindrome(h->next, t->prev);                  // recursive function
				return true;
			}
			else
			{
				return false;
			}
		}

		else if (h == t)
		{
			return true;
		}
		else if(h->next == t)
		{
			if (h->data == t->data)
				return true;
			else
				return false;
		}

	}

	node *h()
	{
		return head;
	}
	node *t()
	{
		return tail;
	}

	~doublylinkedlist()
	{
		while (head != NULL)
		{
			node *cur = head;
			head = head->next;
			cur = NULL;
			delete cur;
		}
	}
};

int main()
{
	int a;
	doublylinkedlist l1;
	l1.input('c');
	l1.input('i');
	l1.input('v');
	l1.input('i');
	l1.input('c');

	a = l1.palindrome(l1.h(), l1.t());
	if(a==1)
		cout << "The string is palindrome" << endl;
	else
		cout << "The string is not a palindrome" << endl;

	system("pause");
	return 0;
}