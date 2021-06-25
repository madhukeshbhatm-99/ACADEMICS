#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}node;

node* create(int x)
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->data=x;
    ptr->lchild=0;
    ptr->rchild=0;
    return ptr;
}
node* insert(node *root,int x)
{
    if(root==0)
    {
        root=create(x);
        return root;
    }
    else if(x <= root->data)
     root->lchild=insert(root->lchild,x);
    else
     root->rchild=insert(root->rchild,x);
    return root;

}
void display_inorder(node *temp)
{
    if(temp==0)
     return;
    else
    {
       display_inorder(temp->lchild);
       printf("%d ",temp->data);
       display_inorder(temp->rchild);
    }

}

void display_preorder(node *temp)
{
    if(temp==0)
     return;
    else
    {
       printf("%d ",temp->data);
       display_preorder(temp->lchild);
       display_preorder(temp->rchild);
    }

}

void display_postorder(node *temp)
{
    if(temp==0)
     return;
    else
    {
       display_postorder(temp->lchild);
       display_postorder(temp->rchild);
       printf("%d ",temp->data);
    }

}

void main()
{
    int n=1,x;
    node *root=0;
    while(n!=0)
    {
        printf("\nOptions\n1. Adding an element to the BST\n2. Inorder traversal \n3. Preorder traversal\n3. Postorder traversal\nPress 0 to EXIT\n");
        printf("Your option: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1 : printf("Enter the element: ");
                     scanf("%d",&x);
                     root=insert(root,x);break;

            case 2 :printf("inorder : "); display_inorder(root);break;
            case 3 :printf("preorder : "); display_preorder(root);break;
            case 4 :printf("postorder : "); display_postorder(root);break;
            default :printf("INVALID INPUT!!!");
        }
    }
}
