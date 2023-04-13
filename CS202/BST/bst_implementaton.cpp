#include <iostream>
using namespace std;
class bstnode
{
public:
    int data;
    bstnode *left = NULL;
    bstnode *right = NULL;

    bstnode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//Insert Node
bstnode *insertBST(bstnode *&root, int data)
{
    if (root == NULL)
    {
        root = new bstnode(data);
        return root;
    }

    // Insert to right subtree
    if (data > root->data)
    {
        root->right = insertBST(root->right, data);
    }
    // Insert to left subtree
    else
    {
        root->left = insertBST(root->left, data);
    }
    return root;
}

// Take Data
void takeInput(bstnode *&root)
{
    int data;
    cout << "\nEnter data and to stop inserting enter -1: ";
    cin >> data;
    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
}

// Preorder Traversal
void preorder(bstnode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal
void inorder(bstnode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal
void postorder(bstnode *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Minimum Value
bstnode *minval(bstnode *root)
{
    bstnode *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// Delete Element from BST
bstnode *deleteBSTnode(bstnode *root, int data)
{
    // No root
    if (root == NULL)
    {
        return root;
    }

    if (root->data == data)
    {
        // For 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // For 1 child

        // Left child only
        if (root->left != NULL && root->right == NULL)
        {
            bstnode *temp = root->left;
            delete root;
            return temp;
        }
        // Right child only
        if (root->left == NULL && root->right != NULL)
        {
            bstnode *temp = root->right;
            delete root;
            return temp;
        }

        // For 2 child
        if (root->left != NULL && root->right != NULL)
        {
            // Smallest from right subtree;
            int min = minval(root->right)->data;

            // Copy the smallest value from right subtree which is greater than left subtree
            root->data = min;

            // Delete that smallest value
            root->right = deleteBSTnode(root->right, min);

            return root;
        }
    }

    else if (root->data > data)
    {
        // Go to left subtree
        root->left = deleteBSTnode(root->left, data);
    }
    else
    {
        // Go to right subtree;
        root->right = deleteBSTnode(root->right, data);
    }
        return root;
}

int main()
{
    bstnode *root = NULL;
    cout << "\nPress 1 to insert element : ";
    cout << "\nPress 2 to delete element : ";
    cout << "\nPress 3 for Preorder Traversal : ";
    cout << "\nPress 4 for Inorder Traversal : ";
    cout << "\nPress 5 for Postorder Traversal : ";
    cout << "\nPress 6 to exit : ";
    int choice;
    while (1)
    {
        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            takeInput(root);
            break;
        case 2:
            if (root == NULL)
            {
                cout << "\nBST is already Empty";
            }
            else
            {
                int data;
                cout << "\nEnter element to delete : ";
                cin >> data;
                deleteBSTnode(root, data);
            }
            break;
        case 3:
            if (root == NULL)
                cout << "\nBST is Empty";
            else
                cout<<"\nPreOrder : ";
                preorder(root);
            break;
        case 4:
            if (root == NULL)
                cout << "\nBST is Empty";
            else
                cout<<"\nInOrder : ";
                inorder(root);
            break;
        case 5:
            if (root == NULL)
                cout << "\nBST is Empty";
            else
                cout<<"\nPostOrder : ";
                postorder(root);
            break;
        case 6:
            cout << "\nProgram Ended ! ";
            exit(0);
            break;

        default:
            cout << "\nInvalid Choice .";
            break;
        }
    }
    return 0;
}
/*

Press 1 to insert element : 
Press 2 to delete element : 
Press 3 for Preorder Traversal : 
Press 4 for Inorder Traversal : 
Press 5 for Postorder Traversal : 
Press 6 to exit : 
Enter Choice : 1

Enter data and to stop inserting enter -1: 50 30 60 20 25 27 26 28 55 70 79 75 -1

Enter Choice : 3
PreOrder : 50 30 20 25 27 26 28 60 55 70 79 75 

Enter Choice : 4
InOrder : 20 25 26 27 28 30 50 55 60 70 75 79 

Enter Choice : 5
PostOrder : 26 28 27 25 20 30 55 75 79 70 60 50 

Enter Choice : 2

Enter element to delete : 28

Enter Choice : 3
PreOrder : 50 30 20 25 27 26 60 55 70 79 75 

Enter Choice : 2

Enter element to delete : 20

Enter Choice : 4
InOrder : 25 26 27 30 50 55 60 70 75 79 

Enter Choice : 2

Enter element to delete : 60

Enter Choice : 5
PostOrder : 26 27 25 30 55 75 79 70 50 

Enter Choice : 2

Enter element to delete : 50

Enter Choice : 3
PreOrder : 55 30 25 27 26 70 79 75 

Enter Choice : 1

Enter data and to stop inserting enter -1: 100 45 34 20 56 -1

Enter Choice : 3
PreOrder : 55 30 25 20 27 26 45 34 70 56 79 75 100 

Enter Choice : 4
InOrder : 20 25 26 27 30 34 45 55 56 70 75 79 100 

Enter Choice : 5
PostOrder : 20 26 27 25 34 45 30 56 75 100 79 70 55 

Enter Choice : 6

Program Ended !

*/