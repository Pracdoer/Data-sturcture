#include <iostream>
using namespace std;

//////////////////			LINK list  ////////////////

struct node 
{
	int value;
	node *next;
};


class link_list 
{

public:
	node *head, *temp, *temp2;
	int num;

	link_list()    /// Constructor
	{
		head = NULL;
		temp = NULL;
		temp2 = NULL;
	}

	~link_list()   //// Distructor
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
	}

	void insert_at_first()    //// Insert at first 
	{
		if(head == NULL)
		{
			head = new node;
			head->value = num;
			head->next = NULL;
			return;
		}
		temp = new node;
		temp->value = num;
		temp->next = head;
		head = temp;
	}

	void insert_random(int key)  /// Inseration at random
	{
		if (head == NULL)
		{
			cout << "list is empty\n";
			return;
		}
		temp = head;
		while(temp != NULL)
		{
			if(temp->value == key)
			{ 
				temp2 = new node;
				temp2->value = num;
				temp2->next = temp->next;
				temp->next = temp2;
				return;
			}
			temp = temp->next;
		}
		return;
	}

	void insert_at_last()    //// Insert at last 
	{
		if(head == NULL)
		{
			head = new node;
			head->value = num;
			head->next = NULL;
			return;
		}
		temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new node;
		temp->next->value = num;
		temp->next->next = NULL;
	}

	
	bool search(int key)    /// Search
	{
		if(head == NULL)
		{
			cout << "list is empty \n";
			return 0;
		}
		temp = head;
		while(temp != NULL)
		{
			if(temp->value == key)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	
	void print()  //// Printin the link list 
	{
		if(head == NULL)
		{
			cout << "list is empty \n";
			return;
		}
		temp = head;
		while(temp != NULL)
		{
			cout <<"  " << temp->value << " ";
			temp = temp->next; 
		}
		cout << endl;
	
	}


	void delte(int key)
	{
		temp = head;
		while(temp != NULL)
		{
			if(key == temp->value)
			{
				temp2 = temp;
				temp = temp->next;
				delete temp2;
				temp2 = NULL;
				return;	
			}	
			temp = temp->next;
		}
		return;
	}
};

int main()
{
	link_list a;
	a.num = 1;
	a.insert_at_last();
	a.num = 2;
	a.insert_at_last();
	a.num = 3;
	a.insert_at_last();
	a.num = 4;
	a.insert_at_last();
	a.num = 5;
	a.insert_at_last();
	a.print();
	cout << endl;
	a.num = 12;
	a.delte(3);
		a.print();
		cout << endl;


	// cout << endl;
	// cout << "enter the element you wannna search\n";
	// cin >> key1;
	// a.search(key1);
	// cout << endl;
	// cout << "enter the element you wannna add a element next to it\n";
	// cin >> key2;
	// a.insert(key2);
	// a.print();
	// cout << "\nenter the element you wannna delete\n";
	// cin >> key3;
	// a.delte(key3);
	// a.print();
	return 0;
}



