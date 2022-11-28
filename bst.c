// Day 12:
// Problem 1: Write a program in C to implement Binary Search Tree (BST) to perform the following operations:
// 1.	Creation  2.	In order traversal 3.	Post order traversal 4.	Pre order traversal 5.	Searching
// 6.	Insertion  7.	Deletion
// void insert(Node*& root, int key)

#include <stdio.h>
#include <stdlib.h>
typedef struct Treenode
{
    int data;
    struct Treenode *left;
    struct Treenode *right;
} tn;
tn *root = NULL;
void Searching()
{
    int n;
    printf("Please enter the value - ");
    scanf("%d", &n);
    if (!root)
    {
        printf("No element present!!!!!");
        return;
    }
    else
    {
        tn *temp = root;
        while (1)
        {
            if (n == temp->data)
            {
                printf("Data is  present!!! ");
                return;
            }
            else if (n < temp->data)
            {
                if (temp->left)
                    temp = temp->left;
                else
                {
                    printf("Data is not present!!! ");
                    return;
                }
            }
            else
            {
                if (temp->right)
                    temp = temp->right;
                else
                {
                    printf("Data is not present!!!! ");
                    break;
                }
            }
        }
    }
}


void insert()
{
    tn *node = (tn *)malloc(sizeof(tn *));
    printf("Please enter the value - ");
    scanf("%d", &node->data);
    node->left = NULL;
    node->right = NULL;
    if (!root)
    {
        root = node;
        return;
    }
    tn *temp = root;
    while (1)
    {
        if (node->data < temp->data)
        {
            if (temp->left)
                temp = temp->left;
            else
            {
                temp->left = node;
                break;
            }
        }
        else
        {
            if (temp->right)
                temp = temp->right;
            else
            {
                temp->right = node;
                break;
            }
        }
    }
    return;
}


void creat()
{
    printf("Enter the number of data you want to insert----");
    int n;
    scanf("%d", &n);
    while (n--)
    {
        insert();
    }
}


void inorder(tn *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


void Preordertraversal(tn *root)
{
    if (!root)
    {
        return;
    }
    printf("%d ", root->data);
    Preordertraversal(root->left);
    Preordertraversal(root->right);
}


void Postordertraversal(tn *root)
{
    if (!root)
    {
        return;
    }
    Postordertraversal(root->left);
    Postordertraversal(root->right);
    printf("%d ", root->data);
}


int maximum(tn *root)
{
    if (root->right == NULL)
        return root->data;
    return maximum(root->right);
}


tn* delete (tn *root, int key)
{
    if (!root)
    {
        printf("no data !!!!!!!");
        return NULL;
    }
    if (key > root->data)
        root->right = delete (root->right, key);
    else if (key < root->data)
        root->left = delete (root->left, key);
    else
    {
        if (!root->left && !root->right)
            return NULL;
        else if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        else
        {
            root->data = maximum(root->left);
            root->left = delete(root->left,root->data);
        }
    }
    return root;
}


int main()
{
    while (1)
    {
        printf("\n1.creat \n2.IN order traversal \n3.Post order traversal\n4.Pre order traversal\n5.Searching\n6.Insertion \n7.Deletion \n8 exit\n");
        printf("please choose what you want-");
        int choise;
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            creat();
            break;
        case 2:
            printf("The inorder traversal is--");
            inorder(root);
            break;
        case 3:
            printf("The postorder traversal is--");
            Postordertraversal(root);
            break;
        case 4:
            printf("The preorder traversal is--");
            Preordertraversal(root);
            break;
        case 5:
            Searching();
            break;
        case 6:
            insert();
            break;
        case 7:
            printf("Please enter the key-");
            int k;
            scanf("%d",&k);
            root=delete(root,k);
            printf("The inorder traversal is--");
            inorder(root);
            printf("\n");
            printf("The postorder traversal is--");
            Postordertraversal(root);
            printf("\n");
            printf("The preorder traversal is--");
            Preordertraversal(root);
            break;
        case 8:
            exit(0);
        default:
            printf("choose currect number----");
        }
    }
    return 0;
}