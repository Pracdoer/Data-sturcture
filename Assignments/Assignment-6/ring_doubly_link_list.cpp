#include <iostream>
using namespace std;

////////////////// Doubly Ring list ////////////////////

struct node
{
	int value;
	node *next;
	node *prev;
};

class Rdoubly_list
{
private:
	node *head, *temp, *temp2;
public:

	Rdoubly_list()
	{

		head = NULL;
		temp = NULL;
		temp2 = NULL;
	}


	~Rdoubly_list()
	{
		temp = head;
		while(temp->next != head)
		{
			temp2 = temp;
			temp = temp->next;
			delete temp2;	
		}
		delete temp;
		delete head;
		delete temp2;
	}


	void insert()
	{
		if(head == NULL)
		{
			head = new node;
			cin >> head->value;
			head->prev = head;
			head->next = head;
			return;
		}
		temp = head;
		while(temp->next != head)
			temp = temp->next;
		temp->next = new node;
		cin >> temp->next->value;
		temp->next->prev = temp;
		temp->next->next = head;
		return;
	}

	void print()
	{
		if(head == NULL)
		{
			cout << "circular list is empty\n";
			return;
		}
		temp = head;
		do 
		{
			cout << temp->value << "  ";
			temp = temp->next;
		}
		while(temp->next != head);
		{
			cout << temp->value << "  " ;
		}
		cout << endl;
	}

	
	int search(int key)
	{
		if(head == NULL)
		{
			cout << "circular list is empty\n";
			return 0;
		}
		temp = head;
		while(temp->next != head)
		{
			if(temp->value == key)
			{
				cout << "\nelement is in the list\n";
				return 1;
			}
			temp = temp->next;
		}
		if(temp->next == head and temp->value == key)
		{
			cout << "element is in the list\n";
			return 1;
		}
		cout << "element is not in the list\n";
		return 0;
	}

	void delte(int key)
	{
		bool flag = search(key);
		if(flag == 1)
		{
			
			temp = head->next;
			if(temp->prev == head && temp->prev->value == key)
			{
				delete temp->prev;
				return;
			}
			while(temp != head)
			{
				if(temp->value == key)
				{
					temp->prev->next = temp->next;
					temp = temp->prev;
					delete temp->next->prev;
					temp->next->prev = temp;
					temp = temp->prev;	
				}
				temp = temp->next;
			}
			if(temp->prev->value == key)
			{
				temp = temp->prev->prev;
				delete temp->next;
				temp->next = head;
			}
		}
	}

};

int main()
{
	Rdoubly_list a;
	int key1, key2, key3, size;
	cout << "enter the size \n";
	cin >> size;
	for(int i = 0; i < size; i++)
	{
		cout << "enter the element\n";
		a.insert();
	}
	cout << endl;
	a.print();
	cout << "enter the element you wanna search\n";
	cin >> key1;
	a.search(key1);
	cout << "enter the element you wanna delete\n";
	cin >> key2;
	a.delte(key2);
	a.print();
	return 0;
}