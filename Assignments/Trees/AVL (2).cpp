#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left, *right;
};

class Tree
{
private:
	node *root;
	node *temp;
	bool checkBalance;
public:
	Tree()
	{
		root = temp = NULL;
		checkBalance = false;
	}

	int height(node *p)
	{
		if (p == NULL)
			return 0;
		else
		{
			int l = height(p->left);
			int r = height(p->right);
			if (l > r)
			{
				l++;
				return l;
			}
			else
			{
				r++;
				return r;
			}
		}
	}

	int balance(node *p)
	{
		int l = height(p->left);
		int r = height(p->right);

		return l - r;
	}

	void insert(int x, node *&p)
	{
		checkBalance = false;
		if (root == NULL)
		{
			root = new node;
			root->data = x;
			root->left = root->right = NULL;
			return;
		}
		if (p == NULL)
		{
			p = new node;
			p->data = x;
			p->left = p->right = NULL;
			checkBalance = true;
			return;
		}

		if (x == p->data)
		{
			cout << x << " already exists\n";
			return;
		}
		else if (x < p->data)
		{
			insert(x, p->left);
		}
		else if (x > p->data)
		{
			insert(x, p->right);
		}

		if (checkBalance == true)
		{
			int difference = balance(p);

			if (difference == 2)
			{
				if (x < p->left->data)
					zigzig(p);
				else
					zigzag(p);
			}
			else if (difference == -2)
			{
				if (x < p->right->data)
					zagzig(p);
				else
					zagzag(p);
			}
		}
	}

	void zigzig(node *&p)
	{
		temp = p->left;
		p->left = temp->right;
		temp->right = p;
		p = temp;
	}

	void zagzag(node *&p)
	{
		temp = p->right;
		p->right = temp->left;
		temp->left = p;
		p = temp;
	}

	void zigzag(node *&p)
	{
		zagzag(p->left);
		zigzig(p);
	}

	void zagzig(node* &p)
	{
		zigzig(p->right);
		zagzag(p);

	}

	void remove(int x, node *&p)
	{
		if (root == NULL)
		{
			cout << "Tree is Empty\n"; return;
		}

		checkBalance = false;
		int preBalance = 0;

		if (p == NULL)
		{
			cout << x << " does not exist\n";
			return;
		}

		preBalance = balance(p);

		if (p->data == x)
		{
			if (p->left == NULL && p->right == NULL) //If No Child is present
			{
				delete p;
				p = NULL;
			}
			else if (p->left == NULL && p->right != NULL) //If 1 Child is present
			{
				temp = p;
				p = p->right;
				delete temp;
				temp = NULL;
			}
			else if (p->left != NULL && p->right == NULL) //If 1 Child is present
			{
				temp = p;
				p = p->left;
				delete temp;
				temp = NULL;
			}
			else									//If 2 Children are present
			{
				temp = p->right;
				while (temp->left != NULL)	//find predecessor. p points to actual predecessor node
				{
					temp = temp->left;
				}
				int suc = temp->data;
				remove(temp->data, root);	//incase it has a child node
				p->data = suc;
				
			}
			checkBalance = true;
			return;
		}
		else if (x < p->data)
			remove(x, p->left);
		else if (x > p->data)
			remove(x, p->right);

		if (checkBalance == true)
		{

			if (preBalance == 0 && (balance(p) == 1 || balance(p) == -1))	//Case 1A and 1B. Do Nothing
				checkBalance = false;
			else if ((preBalance == 1 || preBalance == -1) && balance(p) == 0)	//Case 2A and 2B. Check balance above
				return;
			else if (preBalance == -1 && x < p->data && balance(p->right) == 0)	//Case 3A. Rotate and stop
			{
				zagzag(p);
				checkBalance = false;
			}
			else if (preBalance == 1 && x > p->data && balance(p->left) == 0)	//Case 3B. Rotate and stop
			{
				zigzig(p);
				checkBalance = false;
			}
			else if (preBalance == -1 && x < p->data && balance(p->right) == 1)	//Case 4A. Double Rotate and check above
				zagzig(p);
			else if (preBalance == 1 && x > p->data && balance(p->left) == -1)	//Case 4B. Double Rotate and check above
				zigzag(p);
			else if (preBalance == -1 && x < p->data && balance(p->right) == -1)	//Case 5A. Rotate and check above
				zagzag(p);
			else if (preBalance == 1 && x > p->data && balance(p->left) == 1)	//Case 5B. Rotate and check above
				zigzig(p);
		}

	}

	void print(node *p)
	{
		if (root == NULL)
		{
			cout << "Tree is Empty\n"; return;
		}

		if (p != NULL)
			cout << "Node: " << p->data;
		if (p->left != NULL)
			cout << "\nLeft: " << p->left->data;
		if (p->right != NULL)
			cout << "\nRight: " << p->right->data;
		cout << "\n\n";
		if (p->left != NULL && (p->left->left != NULL || p->left->right != NULL))
			print(p->left);
		if (p->right != NULL && (p->right->left != NULL || p->right->right != NULL))
			print(p->right);
	}

	node*& Root()
	{
		return root;
	}
};

void main()
{
	Tree a;

	a.insert(1, a.Root());
	a.insert(2, a.Root());
	a.insert(3, a.Root());
	a.insert(4, a.Root());
	a.insert(5, a.Root());
	a.insert(6, a.Root());
	a.insert(7, a.Root());
	a.insert(8, a.Root());
	a.insert(9, a.Root());
	a.insert(10, a.Root());

	a.print(a.Root());

	a.remove(7,a.Root());

	cout << "\n\n------------\n\n";

	a.print(a.Root());

	cout << endl << endl;

	system("pause");

}