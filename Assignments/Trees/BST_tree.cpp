#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    
    int info;
    node *left, *right;

};

class trees
{
private:
    node *temp1;
public:
    int num, lh = 0, count = 0;
    node *root;
    trees()
    {
        root = NULL;
        temp1 = NULL;
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
/////////////////////
    /// cheak if all leaves are at same level 

    bool travere1(node *temp)
    {
        int static h = height(root);
        bool static flag = 1;
        if(temp->left != NULL)
        {
            lh++;
            travere1(temp->left);
            lh--;
        }
        if(temp->left == NULL && temp->right == NULL)
        {
            if(h - 1 != lh)
            {
                flag = 0;
                return flag;
            }
        }
        if(temp->right != NULL)
        {
            lh++;
            travere1(temp->right);
            lh--;
        }
        return flag;
    }

//////////////

///    Printing level order //

    void get_level()
    {
        int h = height(root);
        for(int i = 1 ; i <= h; i++)
        {
            print_level(root, i);
        }
    }

    void print_level(node *temp, int level)
    {
        if(temp == NULL)
        {
            return;
        }

        if(level == 1)
        {
            cout << temp->info << "  ";
            return; 
        }
        if(level > 1)
        {
            print_level(temp->left, level -1);
            print_level(temp->right, level -1);
        }
    }




    /////  cheak if two nodes are cousin or not /////

    bool cheak_cousin(node *temp, int v1, int v2)
    {

        if (temp->left != NULL)
        {
            lh++;
            cheak_cousin(temp->left, v1, v2);
            lh--;
        }

        if(temp->info == v1)
        {
            bool static flag = find_cousin(root, v1, v2, lh);
            if(flag)
            {
                cout << "yes " << v1 << " and " << v2 << " are cousins\n";
                return flag;
            }
            else
            {
                cout << "no " << v1 << " and " << v2 << " are not  cousins\n";
                return flag;
            }
        }


        if (temp->right != NULL)
        {
            lh++;
            cheak_cousin(temp->right, v1, v2);
            lh--;
        }

    }

    bool find_cousin(node *temp , int v1, int v2, int lh1)
    {

        bool static flag = 1;
        if (temp->left != NULL)
        {
            lh++;
            find_cousin(temp->left, v1, v2, lh1);
            lh--;
        }

        if(lh - 1 == lh1 )
        {
            cout << temp->left->info << endl;
            cout << temp->right->info << endl;
            if(temp->left->info == v2 && temp->right->info == v1)
            {
                flag = 0;
                return flag;
            }
            if(temp->right->info == v2 && temp->left->info == v1)
            {
                flag = 0;
                return flag;
            }
            else{
                flag = 1;
                return flag;}
        }



        if (temp->right != NULL)
        {
            lh++;
            find_cousin(temp->right, v1, v2, lh1);
            lh--;
        }   

       
    }



    void insert(node *temp)
    {
        if (root == NULL)
        {
            temp = new node;
            temp->info = num;
            temp->right = NULL;
            temp->left = NULL;
            root = temp;
            return;
        }
        if(num == temp->info)
        {
        	cout << "element is already in tree\n";
        	return;
        }
        if(num > temp->info)
        {
            if (temp->right != NULL)
                insert(temp->right);
            else
            {
                temp->right = new node;
                temp->right->info = num;
                temp->right->right = NULL;
                temp->right->left  = NULL;
            }
        }
        if(num < temp->info)
        {
            if(temp->left != NULL)
                insert(temp->left);
            else
            {
                temp->left = new node;
                temp->left->info = num;
                temp->left->right = NULL;
                temp->left->left  = NULL;
            }
        }
    }
    void search(node *temp, int value)
    {
    	if(temp == NULL)
    	{
    		cout << " Tree is empty\n";
    		return;
    	}
    	if(temp->left != NULL)
    		search(temp->left, value);
    	if (temp->info == value)
    	{
    		cout << "Element is in tree\n";
    		return;
    	}
    	if(temp->right != NULL)
    		search(temp->right, value);
    	else
    	{
    		cout << "element is not in the list\n";
    		return;
    	}
    }
    void travere(node *temp)
    {
    	if(temp == NULL)
    	{
    		cout << " Tree is empty\n";
    		return;
    	}
    	if(temp->left != NULL)
    		travere(temp->left);
    	cout << temp->info << "  " ;
    	if(temp->right != NULL)
    		travere(temp->right);
    }
    void delte(node *temp, int value)
    {
    	if(temp == NULL)
    	{
    		cout << "tree is empty\n";
    		return;
    	}
    	if(value == temp->info)
    	{
    		if(temp->right == NULL and temp->left == NULL)
    			delete temp;
    		if(temp->right != NULL and temp->left == NULL)
    			temp  = temp->right;
    		if(temp->left != NULL and temp->right == NULL)
    			temp = temp->left; 
    	}
    	if(value > temp->info)
    	{
	    	if (temp->right != NULL)
	    	{
		    	if(temp->right->info == value)
		    	{
		    		if(temp->right->right == NULL and temp->right->left == NULL)
		    		{
		    			delete temp->right;
		    			temp->right = NULL;
		    			return;
		    		}
		    		if(temp->right->right != NULL and temp->right->left == NULL)
		    		{
		    			temp1 = temp->right;
		    			temp->right = temp->right->right;
		    			delete temp1;
		    			temp1 = NULL;
		    			return;
		    		}
		    		if(temp->right->right == NULL and temp->right->left != NULL)
		    		{
		    			temp1 = temp->right;
		    			temp->right = temp->right->left;
		    			delete temp1;
		    			temp1 = NULL;
		    			return;
		    		}
		    		if(temp->right->right != NULL and temp->right->left != NULL)
		    		{
		    			if(temp->right->right->left == NULL)
		    			{
		    				swap(temp->right->info, temp->right->right->info);
		    				if(temp->right->right->right != NULL)		    					
		    				{
		    					temp1 = temp->right->right;
		    					temp->right->right = temp->right->right->right;
		    					delete temp1;
		    					temp1 = NULL;
		    					return;
		    				}
		    				else
		    				{
		    					delete temp->right->right;
		    					temp->right->right = NULL;
		    					return;
		    				}
		    			}
		    			else
		    			{
		    				temp1 = temp->right->right;
		    				while(temp1->left->left !=  NULL)
		    				{
		    					temp1 = temp1->left;
		    				}
		    				swap(temp1->left->info, temp->right->info);
		    				delte(temp1, value);
		    			}
		    		}
	    		}
	    		else
	    			delte(temp->right, value);
	    	}
	    	else
	    	{
	    		cout << "element is not in the list\n";
	    		return;
	    	}
	    }
	    if(value < temp->info)
	    {
	    	if (temp->left != NULL)
	    	{
		    	if(temp->left->info == value)
		    	{
		    		if(temp->left->right == NULL and temp->left->left == NULL)
		    		{
		    			delete temp->left;
		    			temp->left = NULL;
		    			return;
		    		}
		    		if(temp->left->right != NULL and temp->left->left == NULL)
		    		{
		    			temp1 = temp->left;
		    			temp->left = temp->left->right;
		    			delete temp1;
		    			temp1 = NULL;
		    			return;
		    		}
		    		if(temp->left->right == NULL and temp->left->left != NULL)
		    		{
		    			temp1 = temp->left;
		    			temp->left = temp->left->left;
		    			delete temp1;
		    			temp1 = NULL;
		    			return;
		    		}
		    		if(temp->left->right != NULL and temp->left->left != NULL)
		    		{
		    			if(temp->left->left->right == NULL)
		    			{
		    				swap(temp->left->info, temp->left->left->info);
		    				if(temp->left->left->left != NULL)		    					
		    				{
		    					temp1 = temp->left->left;
		    					temp->left->left = temp->left->left->left;
		    					delete temp1;
		    					temp1 = NULL;
		    					return;
		    				}
		    				else
		    				{
		    					delete temp->left->left;
		    					temp->left->left = NULL;
		    					return;
		    				}
		    			}
		    			else
		    			{
		    				temp1 = temp->left->left;
		    				while(temp1->right->right !=  NULL)
		    				{
		    					temp1 = temp1->right;
		    				}
		    				swap(temp1->right->info, temp->left->info);
		    				delte(temp1, value);
		    			}
		    		}

	    		}
	    		else
	    			delte(temp->left, value);
	    	}
	    	else
	    	{
	    		cout << "element is not in the list\n";
	    		return;
	    	}
	    }
    }

    int min(node *temp)
    {
    	static int mini = temp->info;
    	if(temp == NULL)
    	{
    		cout << " Tree is empty\n";
    		return 0;
    	}
    	if(temp->info < mini)
    		mini = temp->info;
    	if(temp->left != NULL)
    		min(temp->left);
    	return mini;	
    }

    int max(node *temp)
    {
    	static int maxi = temp->info;
    	if(temp == NULL)
    	{
    		cout << " Tree is empty\n";
    		return 0;
    	}
    	if(temp->info > maxi)
    		maxi = temp->info;
    	if(temp->right != NULL)
    		max(temp->right);
    	return maxi;	
    }

};

int main()
{
    trees a;
    int s, d;
    for(int i = 0; i < 5; i++)
    {
        cout << "enter the number\n";
        cin >> a.num;
        a.insert(a.root);
    }
    a.cheak_cousin(a.root, 3, 6);
    //a.get_level();
    //cout << a.travere1(a.root);

    //cout << "\nenter the element you wanna search\n";
    //int n;
    //cin >> n;
    //a.search(a.root, n);
    //cout << "\nEnter the value you wanna delete\n";
    //cin >> d;
    //a.delte(a.root, d);
    cout << endl;
    //a.travere(a.root);
    //cout << a.root->info;
   	
   	//cout << "the minimun value in tree is :  "  << a.min(a.root) << endl;
   	//cout << "the maximum value in tree is :  "  << a.max(a.root) ;


    return 0;
}





