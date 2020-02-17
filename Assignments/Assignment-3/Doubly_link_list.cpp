#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

/////////////// Doubly Link List //////////////////////

struct node
{
	int value;
	node *next;
	node *prev;
};

class doubly_list
{
private:
	node *head, *temp, *temp2, *tail;
	int count = 0;
public:
	doubly_list()
	{
		head = NULL;
		temp = NULL;
		temp2 = NULL;
	}
	~doubly_list()
	{
		while(head != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
			 
		}
		delete head;
		delete temp;
		delete temp2;
		delete tail;
		count = 0;
	}

	void insert()
	{
		if(head == NULL)
		{
			head = new node;
			cin >> head->value;
			head->next = NULL;
			head->prev = NULL;
			return;
		}
		temp = head;
		while(temp->next != NULL)
			temp = temp->next;

		temp->next = new node;
		cin >> temp->next->value;
		temp->next->prev = temp;
		temp->next->next = NULL;
	}

	void print()
	{
		if(head == NULL)
		{
			cout <<"the list is empty\n";
			return;
		}
		temp = head;
		while(temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void Rprint()
		{
			temp = head;
			while(temp->next != NULL)
				temp = temp->next;

			while(temp != NULL)
			{
				cout<< temp->value<<"  ";
				temp = temp->prev;
			}
			cout << endl;
		}

	int search(int key)
	{
		count = 0;
		if(head == NULL)
		{
			cout << "list is empty \n";
			return 0 ;
		}

		temp = head;
		while(temp != NULL)
		{
			if(temp->value == key)
			{
				count = count + 1;
			}
			temp = temp->next;
		}
		if(count == 0)
		{
			cout << "element is not in the list\n";
			return  0;
		}
		else
		{
			cout << "element is in the list\n";
			return 1;
		}
		
		
	}

	void insert(int key)
	{
		int x, n = 0;
		bool flag1 = search(key);
		if (flag1 == 1)
		{
			cout << "there are " << count << " same elements \nHow many you wanna choise\n";
			cin >> x;
			if (x >> count or x <= 0)
			{
				cout << "No element is edit\n";
				return;
			}
			temp = head;
			while(temp != NULL)
			{
				if(key == temp->value)
				{
					if(n == x)
						return;
					temp2 = new node;
					cout << "enter the element you wannna add next to it\n";
					cin >> temp2->value;
					temp2->prev = temp;
					temp2->next = temp->next;
					temp->next = temp2;
					temp->prev = temp;
					n++;
				}
				temp = temp->next;		
			}
			
		}
		return;
	}

	void delte(int key)
	{
		int n = 0, x;
		bool flag = search(key);
		if (flag == 1)
		{
			cout << "There are " << count << " same elements \nHow many you wanna delete\n";
			cin >> x;
			if (x > count or x <= 0)
			{
				cout << "No element is deleted\n";
				return;
			}
			temp = head;

			while(temp != NULL)
			{
				if(temp->prev == NULL and key == temp->value)
				{
					temp = temp->next;
					delete temp->prev;
				}
				if(temp->next == NULL and key == temp->value)
				{
					temp->prev->next = NULL;
					delete temp;
				}
				if(key == temp->value)
				{
					if(n == x)
						return;
					temp2 = temp;
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					temp = temp->prev;	
					delete temp2;
					n++;
				}	
				temp = temp->next;		
			}

		}
		return;
	}

	void reverse()
    {
        if(head == NULL)
        {
            cout << " list is empty\n";
            return;
        }
        tail = head;
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        tail = temp;
        temp = head;
        while(temp->next != NULL)
        {
            swap(temp->value, tail->value);
            temp = temp->next;
            tail = tail->prev;
            if(temp->value == tail->value)
            	return;
        }
    }
};



int main()
{
	doubly_list a;
	int size, key1, key2, key3;
	cout << "enter the size \n";
	cin >> size;
	for(int i = 0; i < size; i++)
	{
		cout << "enter the elements\n";
		a.insert();
	}
	a.print();
	cout << endl;
	 a.Rprint();
	 cout << "enter the element you wanna search\n";
	 cin >> key1;
	 a.search(key1);
	 cout << "\nenter the element you wannna add a element next to it\n";
	 cin >> key2;
	 a.insert(key2);
	 a.print();
	 cout << "\nenter the element you wanna delete\n";
	 cin >> key3;
	 a.delte(key3);
	a.print();
	a.reverse();
	cout << endl;
	a.print();
	return 0;
}