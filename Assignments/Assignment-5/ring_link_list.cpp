#include <iostream>
using namespace std;

///////////// Ring_link_list //////////////////////

struct node
{
	int value;
	node *next;
};

class Rlink_list
{
private:
	node *head, *temp, *temp2;
public:

	Rlink_list()
	{
		head = NULL;
		temp2 = NULL;
		temp = NULL;
	}

	~Rlink_list()
	{
		while(head->next != head)
		{
			temp = head;
			head = head->next;
			delete temp;
			 
		}
		delete head;
		delete temp;
		delete temp2;
	}


	void insert()
	{
		if(head == NULL)
		{
			head = new node;
			cin >> head->value;
			head->next = head;
			return;
		}
		temp = head;
		while(temp->next != head)
			temp = temp->next;
		temp->next = new node;
		cin >> temp->next->value;
		temp->next->next = head;
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

	void insert(int key)
	{
		bool flag = search(key);
		if(flag == 1)
		{
			temp = head->next;
			cout << "enter the value you wanna add\n";
			while(temp != head)
			{
				if(temp->value == key)
				{
					temp2 = new node;
					cin >> temp2->value;
					temp2->next = temp->next->next;
					temp->next = temp2;
					return;
				}
				temp = temp->next;
			}
			if(temp->next == head and temp->value == key)
			{
				temp2 = new node;
				cin >> temp2->value;
				temp2->next = temp->next;
				temp->next = temp2;
			}
		}
		return;
	}

	void delte(int key)
	{
		bool flag = search(key);
		if(flag == 1)
		{
			temp = head;
			while(temp->next != head)
			{
				if(temp->value == key)
				{
					temp2 = temp;
					temp = temp->next;
					delete temp2;
					temp2 = NULL;
					return;
				}
				temp = temp->next;
			}
			if(temp->next == head and temp->value == key)
			{
				temp2 = temp;
				temp = temp->next;
				delete temp2;
				temp2 = NULL;
			}
		}
	}


};




int main()
{

	Rlink_list a;
	int key1, key2, key3, size;
	cout << "enter the size\n";
	cin >> size;
	for(int i = 0; i < size; i++)
	{
		cout << "enter the values\n";
		a.insert();
	}
	a.print();
	cout << "\nenter the value you wanna search\n";
	cin >> key1;
	a.search(key1);
	cout << "\nenter the value you wanna add next to it\n";
	cin >> key3;
	a.insert(key3);
	a.print();
	cout << "\nenter the value you wanna delete\n";
	cin >> key2;
	a.delte(key2);
	a.print();
		return 0;
}