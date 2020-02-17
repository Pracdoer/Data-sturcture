#include <iostream>
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
    int num;
    node *root;
    trees()
    {
        root = NULL;
        temp1 = NULL;
    }

    ~trees()
    {
        delete root->right;
        delete root->left;
        delete root;  // will recursively delete all nodes below it as well
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
};


int main()
{
    // int n;
    // trees a;

    // cout << "enter the size\n";
    // cin >> n;
    // int count = 1;
    // cout  << 2*n - 1 << " possible BST trees can be construct\n";
    // for(int i = 1; i <= n; i++)
    // {
    //     a.num = i;
    //     a.insert(a.root);
    //     for(int j  = 1; j <= n; j++)
    //     {
    //         if(j == i)
    //         {
    //             continue;
    //         }
    //         a.num = j;
    //         a.insert(a.root);
    //         cout << endl;
            
    //     }
    //     a.travere(a.root);
    //     count++;
    //     a.~trees();
    // }
    // cout << endl;
    // cout << count << endl;
    cout << 7/2;
}