#include <iostream>
using namespace std;

struct node
{
    
    int info, BF;
    node *left, *right;

};

class trees
{
private:
    node *temp1, *temp2, *temp3;
public:
    int num, LH = 0 , RH = 0, H = 0;
    node *root;
    trees()
    {
        root = NULL;
        temp1 = temp2 = NULL;
    }

    // ~trees()
    // {
    //     if(temp == NULL)
    //     {
    //         cout << " Tree is empty\n";
    //         return;
    //     }
    //     if(temp->left != NULL)
    //         travere(temp->left);
    //     if(temp->right != NULL)
    //         travere(temp->right);
    //     delete temp;
    // }

    // void Balance_Factor(node *temp)
    // {
    //     if(temp->left != NULL)
    //         Balance_Factor(temp->left);
    //     L_hight(temp->left);
    //     R_hight(temp->right);
    //     temp->BF = LH - RH;
    //     LH = 0;
    //     RH = 0;
    //     if(temp->right != NULL)
    //         Balance_Factor(temp->right);
    //     return ;
    // }

    int hight(node *temp)
    {
        if (temp == NULL)  
            return 0; 
        else 
        { 
            int lh = hight(temp->left); 
            int lr = hight(temp->right); 
            if (lh > lr) 
            { 
                return lh + 1;; 
            }
            else
            { 
                return lr+1;; 
            }
        }
    }

    void zigzig(node *temp)
    {
        if(temp->left->right != NULL)
        {
            temp3 = temp;
            temp1 = temp->right;
            temp2 = temp->left;
            temp = temp->left;
            temp->right = temp3;
            temp->right->right = temp3->right;
            return;
        }
    }

    // void cheak_Balance(node *temp)
    // {
    //     if(temp->BF > 1 or temp->BF < 1)
    //     {
    //         if(num < temp->info and num < temp->left->info)
    //         {
    //             zigzig(temp);
    //         }

    //     }
    // }

    void insert(int x, node *&temp)
    {
        //checkBalance = false;
        if (root == NULL)
        {
            root = new node;
            root->data = num;
            root->left = root->right = NULL;
            temp = root;
            return;
        }
        if (temp == NULL)
        {
            temp = new node;
            temp->data = num;
            temp->left = temp->right = NULL;
            //checkBalance = true;
            return;
        }

        if (num == temp->data)
        {
            cout << num << " already exists\n";
            return;
        }
        else if (num < temp->data)
        {
            insert(num, temp->left);
        }
        else if (num > temp->data)
        {
            insert(num, temp->right);
        }

        int bf = hight(temp->left) - hight(temp->right);

    void travere(node *temp)
    {
    	if(temp == NULL)
    	{
    		cout << " Tree is empty\n";
    		return;
    	}
    	if(temp->left != NULL)
    		travere(temp->left);
    	cout << temp->info << "  "  << ", BF = " << temp->BF << " " << endl;
    	if(temp->right != NULL)
    		travere(temp->right);
    }
};
int main()
{
    trees a; 
    // a.num = 5;
    // a.insert(a.root);
    // a.num = -3;
    // a.insert(a.root);
    // // a.num = 8;
    // a.insert(a.root);
    // a.num = -5;
    a.insert(a.root);
    a.num = 17;
    a.insert(a.root);
    a.num = 7;
    a.insert(a.root);
    a.num = 2;
    // a.insert(a.root);
    // a.num = -4;
    // a.insert(a.root);
    // a.num = 1;
    // a.insert(a.root);
    // a.num = 3;
    // a.insert(a.root);


    // for(int i = 0; i < 5; i++)
    // {
    //     cout << "enter the number\n";
    //     cin >> a.num;
    //     a.insert(a.root);
    // }
    a.travere(a.root);
    return 0;
}



//////////    Working ////////

// #include <iostream>
// using namespace std;

// struct node
// {
    
//     int data, BF;
//     node *left, *right;

// };

// class trees
// {
// private:
//     node *temp1, *temp2, *temp3;
// public:
//     int num, LH = 0 , RH = 0, H = 0;
//     node *root;
//     trees()
//     {
//         root = NULL;
//         temp1 = temp2 = NULL;
//     }

//     void Balance_Factor(node *temp)
//     {
//         if(temp->left != NULL)
//             Balance_Factor(temp->left);
//         L_hight(temp->left);
//         R_hight(temp->right);
//         temp->BF = LH - RH;
//         LH = 0;
//         RH = 0;
//         if(temp->right != NULL)
//             Balance_Factor(temp->right);
//         return ;
//     }

//     int R_hight(node *temp)
//     {
//         if (temp == NULL)  
//             return 0; 
//         else 
//         { 
//             int lh = R_hight(temp->left); 
//             int lr = R_hight(temp->right); 
//             if (lh > lr) 
//             { 
//                 RH = lh + 1;
//                 return RH; 
//             }
//             else
//             { 
//                 RH = lr+1;
//                 return RH; 
//             }
//         }
//     }

//     int L_hight(node *temp)
//     {
//         if (temp == NULL)  
//             return 0; 
//         else 
//         { 
//             int lh = L_hight(temp->left); 
//             int lr = L_hight(temp->right); 
//             if (lh > lr) 
//             { 
//                 LH = lh + 1;
//                 return LH; 
//             }
//             else
//             { 
//                 LH = lr+1;
//                 return LH; 
//             }
//         } 
//     }

//     void zigzig(node *temp)
//     {
//         temp1 = temp->left;
//         temp->left = temp1->right;
//         temp1->right = temp;
//         temp = temp1;
//     }
//     void cheak_Balance(node *temp)
//     {
//         if(temp->BF > 1 or temp->BF < -1)
//         {
//             if(num < temp->data and num < temp->left->data)
//             {
//                 zigzig(temp);
//             }

//         }
//     }

//       void insert(node *temp)
//     {
//         if (root == NULL)
//         {
//             temp = new node;
//             temp->data = num;
//             temp->right = NULL;
//             temp->left = NULL;
//             root = temp;
//             return;
//         }
//         if (temp == NULL)
//         {
//             temp = new node;
//             temp->data = num;
//             temp->left = temp->right = NULL;
//             //checkBalance = true;
//             return;
//         }

//         if (num == temp->data)
//         {
//             cout << num << " already exists\n";
//             return;
//         }
//         if (num < temp->data)
//         {
//             insert(temp->left);
//         }
//         if (num > temp->data)
//         {
//             insert(temp->right);
//         }
        
//         Balance_Factor(temp);
//         cheak_Balance(temp);
//     }
//     void travere(node *temp)
//     {
//         if(temp == NULL)
//         {
//             cout << " Tree is empty\n";
//             return;
//         }
//         if(temp->left != NULL)
//             travere(temp->left);
//         cout << temp->data << "  "  << ", BF = " << temp->BF << " " << endl;
//         if(temp->right != NULL)
//             travere(temp->right);
//     }
// };
// int main()
// {
//     trees a; 
//     a.num = 17;
//     a.insert(a.root);
//     a.num = 7;
//     a.insert(a.root);
//     a.num = 2;
//     a.insert(a.root);
//     a.travere(a.root);
//     return 0;
// }


//////



#include<stdio.h> 
#include<stdlib.h>  
int num, LH = 0 , RH = 0, H = 0;
struct node
{
    int key;
    node *left, *right;
};
node *temp = NULL;

    int R_hight(node *temp)
    {
        if (temp == NULL)  
            return 0; 
        else 
        { 
            int lh = R_hight(temp->left); 
            int lr = R_hight(temp->right); 
            if (lh > lr) 
            { 
                RH = lh + 1;
                return RH; 
            }
            else
            { 
                RH = lr+1;
                return RH; 
            }
        }
    }
    int L_hight(node *temp)
    {
        if (temp == NULL)  
            return 0; 
        else 
        { 
            int lh = L_hight(temp->left); 
            int lr = L_hight(temp->right); 
            if (lh > lr) 
            { 
                LH = lh + 1;
                return LH; 
            }
            else
            { 
                LH = lr+1;
                return LH; 
            }
        } 
    }  
    int Balance_Factor(node *temp){
        if(temp->left != NULL)
            Balance_Factor(temp->left);
        L_hight(temp->left);
        R_hight(temp->right);
        int bf = LH - RH;
        LH = 0;
        RH = 0;
        if(temp->right != NULL)
            Balance_Factor(temp->right);
        return bf;
        }

        void insert(int x, node *&p)
        {
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
int main() { 
    Node *root = NULL; 
      root = insert(root, 10); 
      root = insert(root, 20); 
      root = insert(root, 30); 
      root = insert(root, 25); return 0;}