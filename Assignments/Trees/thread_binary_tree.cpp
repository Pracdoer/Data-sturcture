#include <iostream>
using namespace std;

struct node
{
    
    int info;
    node *left, *right;
    int lth;
    int rth;

};

class trees
{
private:
    node *current, *temp1, *temp2;
public:
    int num , thread = 1, child = 0;
    node *root, *dummy;
    trees()
    {
        temp1 = temp2 = NULL;    
        root = NULL;
        current = NULL;
        dummy = new node;
        dummy->info = 999;
        dummy->right = dummy->left = dummy;
        dummy->lth = dummy->rth = child;
    }
    void insert(node *temp)
    {
        if (root == NULL)
        {
            temp = new node;
            temp->info = num;
            temp->right = dummy;
            temp->left = dummy;
            temp->lth = temp->rth = thread;
            dummy->left = temp;
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
            if (temp->rth != thread)
                insert(temp->right);
            else
            {
                current = new node;
                current->info = num;
                current->right = temp->right;
                temp->right = current;
                temp->rth = child;
                current->lth = current->rth = thread;
                current->left = temp;
            }
        }
        if(num < temp->info)
        {
            if(temp->lth != thread)
                insert(temp->left);
            else
            {
                current = new node;
                current->info = num;
                current->left = temp->left;
                temp->left = current;
                temp->lth = child;
                current->lth = current->rth = thread;
                current->right = temp;
            }
        }
    }

    node* nextInorder(node *temp) 
    {   
        if(temp->rth == thread)
            return(temp->right);
        else
        { 
            temp = temp->right;   
            while(temp->lth == child)          
                temp = temp->left;       
            return temp; 
        } 
    } 

    node* fastInorder(node *temp) 
    {   
        while(  ( temp = nextInorder(temp) ) != dummy )  
            cout << temp->info << "  "  ;
    } 


     void delte(node *temp, int value)
     {
    // 	if(root->lth == thread && root->rth == thread)
    // 	{
    // 		cout << "tree is empty\n";
    // 		return;
    // 	}
    // 	if(value == temp->info)
    // 	{
    // 		if(temp->right == NULL and temp->left == NULL)
    // 			delete temp;
    // 		if(temp->right != NULL and temp->left == NULL)
    // 			temp  = temp->right;
    // 		if(temp->left != NULL and temp->right == NULL)
    // 			temp = temp->left; 
    // 	}
     	if (value > temp->info)
     	{
	     	if (temp->rth != thread)
	     	{
		     	if(temp->right->info == value)
		     	{
		      		if(temp->right->rth == thread and temp->right->lth == thread)
		     		{
                        temp2 = temp->right->right;
                        temp->rth = thread;
		                delete temp->right;
                        temp->right = temp2;
		     			return;
               		}
		    		if(temp->right->rth == child and temp->right->lth == thread)
		    		{

		    			temp1 = temp->right;
		    			temp->right = temp->right->right;
                        //temp->right->right = temp1->right;
		    			delete temp1;
		    			return;
		    		}
		    		if(temp->right->rth == thread and temp->right->lth == child)
		    		{
		    			temp1 = temp->right;
		    			temp->right = temp->right->left;
                        temp->right->left = temp1->left;
		    			delete temp1; 
		    			temp1 = NULL;
		    			return;
		    		}
		    		if(temp->right->rth == child && temp->right->lth == child)
		    		{
		    			if(temp->right->right->lth == thread)
		    			{
		    				swap(temp->right->info, temp->right->right->info);
		    				if(temp->right->right->rth == child)		    					
		    				{
                                // delte(temp->right->right, value);
                                // return;
		    					temp1 = temp->right->right;
		    					temp->right->right = temp->right->right->right;
                                temp->right->right->left = temp->right;
		    					delete temp1;
		    					temp1 = NULL;
		    					return;
		    				}
		    				else
		    				{
                                // delte(temp->right, value);
                                // return;
                                temp->right->rth = thread;
                                delete temp->right->right;
                                temp->right->right = dummy;
		    					return;
		    				}
		    			}
		    			else
		    			{
		    				temp1 = temp->right->right;
		    				while(temp1->left->lth !=  thread)
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
	    	if (temp->lth != thread)
	    	{
		    	if(temp->left->info == value)
		    	{
		    		if(temp->left->rth == thread && temp->left->lth == thread)
		    		{
                        temp2 = temp->left->left;
                        temp->lth = thread;
                        delete temp->left;
                        temp->left = temp2;
                        return;
		    			// delete temp->left;
		    			// temp->left = NULL;
		    			// return;
		    		}
		    		if(temp->left->rth == thread && temp->left->lth == child)
		    		{

                        temp1 = temp->left;
                        temp->left = temp->left->left;
                        temp->left->right = temp;
                        delete temp1;
                        temp1 = NULL;
                        return;
		    		}
		    		if(temp->left->rth == child and temp->left->lth == thread)
		    		{
		    			temp1 = temp->left;
		    			temp->left = temp->left->right;
                        temp->left->left = temp1->left;
		    			delete temp1;
		    			temp1 = NULL;
		    			return;
		    		}

                    if(temp->right->rth == child && temp->right->lth == child)
                    {
                        if(temp->left->left->rth == thread)
                        {
                            swap(temp->left->info, temp->left->left->info);
                            if(temp->left->left->lth == child)                                
                            {
                                // delte(temp->right->right, value);
                                // return;
                                temp1 = temp->left->left;
                                temp->left->left = temp->left->left->left;
                                temp->left->left->right = temp->left;
                                delete temp1;
                                temp1 = NULL;
                                return;
                            }

                            else
                            {
                                // delte(temp->left, value);
                                //  return;
                                temp->left->lth = thread;
                                delete temp->left->left;
                                temp->left->left = dummy;
                                return;
                            }
                        }
                        else
                            {
                                temp1 = temp->left->left;
                                while(temp1->right->rth !=  thread)
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

};

int main()
{
    trees a;
    int s, d;
    for(int i = 0; i < 6; i++)
    {
        cout << "enter the number\n";
        cin >> a.num;
        a.insert(a.root);
    }
    cout << endl;
    a.fastInorder(a.dummy);
    cout << "enter the element you wanna delete\n";
    cin >> d;
    a.delte(a.root,d);
    cout << endl;
    a.fastInorder(a.dummy);
    // //cout << "\nenter the element you wanna search\n";
    // //int n;
    // //cin >> n;
    // //a.search(a.root, n);
    // //cout << "\nEnter the value you wanna delete\n";
    // //cin >> d;
    // //a.delte(a.root, d);
    // cout << endl;
    // //a.travere(a.root);
    // //cout << a.root->info;
   	


    return 0;
}





