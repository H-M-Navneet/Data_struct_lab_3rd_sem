#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *construct_tree()
{
    int data;
    printf("enter the data (enter -1 for no node)\n");
    scanf("%d",&data);
    if(data==-1)
    {
        return NULL;
    }
    struct node *root = create_node(data);
    printf("enter left child for data %d \n",data);
    root->left = construct_tree();
    printf("enter right child for data %d \n",data);
    root->right = construct_tree();
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

int main()
{
    struct node *root=NULL;
    printf("construct a binary tree\n");
    root = construct_tree();
    printf("inorder : ");
    inorder(root);
    printf("\npreorder : ");
    preorder(root);
    printf("\npostorder : ");
    postorder(root);
    return 0;
}