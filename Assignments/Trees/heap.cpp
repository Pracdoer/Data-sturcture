#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    int data;
    int lh;
    node *left, *right;
};

class heap
{
private:
    node *temp, *temp2;
public:
    node *root;
    int h, n_count, num;
    bool flag = false;
    heap()
    {
        root = temp = temp2 = NULL;
        n_count = 0;
    }

    int height(node *temp) {
    if (!temp)
    	return -1;

    return 1 + max(height(temp->left), height(temp->right));
    }

    // void travere(node *temp)
    // {
    //     if(temp->left != NULL)
    //         travere(temp->left);
    //     cout << temp->data << "  " ;
    //     if(temp->right != NULL)
    //         travere(temp->right);
    // }

    void min_heap(node *temp, int value)
    {
        if(root == NULL)
        {
            temp = new node;
            temp->data = value;
            temp->left = temp->right = NULL;
            h = 0;
            temp->lh = h;
            n_count++;
            root = temp;
            flag = true;
            return;
        }
        if(temp->left != NULL){
            min_heap(temp->left, value); 
            flag = true;
        }
        
        if(temp->left != NULL && temp->right == NULL)
	    	{
		        temp2 = new node;
		        temp->right = temp2;
		        temp2->data = value;
		        temp2->right = temp2->left = NULL;
		        temp2->lh = h;
		        n_count++;
		        flag = true;
		        return;
	    	}
        

        if(temp->lh == h-1  && flag == false )
        {
        	
            if(temp->left == NULL && temp->right == NULL)
            {
                temp2 = new node;
                temp->left = temp2;
                temp2->data = value;
                temp2->left = temp2->right = NULL;
                temp2->lh = h;
                n_count++;
                flag = true;
                return;
            }
        }
        if(n_count == (pow(2,h+1) - 1))
        {

            temp2 = new node;
            temp->left = temp2;
            temp2->data = value;
            temp2->left = temp2->right = NULL;
            h++;
            temp2->lh = h;
            n_count++; 
            flag = true;
            return;
        }
       
        if(temp->right != NULL){
        	//flag = false;
            min_heap(temp->right, value);
            flag = false;	
        }
        
        
        return;
    }

};

int main()
{
    heap a;
    a.num = 13;
    a.min_heap(a.root, a.num);
    a.num = 21;
    a.min_heap(a.root, a.num);
    a.num = 19;
    a.min_heap(a.root, a.num);
    a.num = 6;
    a.min_heap(a.root, a.num);
    a.num = 16;
    a.min_heap(a.root, a.num);
    a.num = 68;
    a.min_heap(a.root, a.num);
    a.num = 65;
    a.min_heap(a.root, a.num);
    a.num = 26;
    a.min_heap(a.root, a.num);
    cout << endl;
    cout << "\n Min heap\n";
    a.travere(a.root);
    cout << endl;
    // cout << "\n Max heap\n";
    // a.num = 13;
    // a.max_heap(a.root, a.num);
    // a.num = 24;
    // a.max_heap(a.root, a.num);
    // a.num = 16;
    // a.max_heap(a.root, a.num);
    // a.num = 21;
    // a.max_heap(a.root, a.num);
    // a.num = 31;
    // a.max_heap(a.root, a.num);
    // a.num = 19;
    // a.max_heap(a.root, a.num);
    // a.num = 68;
    // a.max_heap(a.root, a.num);
    // cout << endl;
    // a.travere(a.root);
   
    
    return 0;
}