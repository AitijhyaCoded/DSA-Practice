#include <stdio.h>  
#include <stdlib.h>  

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height; //balance factor
};
struct Node *root = NULL;

int getHeight(struct Node *root){
    if(root==NULL)
        return 0;
    return root->height;
}

struct Node *createNode(int val){
    struct Node *new; 
    new = malloc(sizeof(struct Node));
    new->data=val;
    new->left=NULL;
    new->right=NULL;
    new->height=1;
    return new;
}

int max(int a, int b){
    return a>b?a:b;
}

int getbf(struct Node *root){
    if(root==NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

struct Node *rightrotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right),getHeight(x->left)) + 1;

    return x;
}

struct Node *leftrotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right),getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right),getHeight(x->left)) + 1;

    return y;
}

struct Node *insert(struct Node *root, int val){
    if(root==NULL)
        return createNode(val);
    else if(val < root->data)
        root->left = insert(root->left,val);
    else
        root->right = insert(root->right,val);   

    root->height = max(getHeight(root->right),getHeight(root->left)) + 1;
    int bf = getbf(root);

    //left left case
    if(bf>1 && val < root->left->data){
        return rightrotate(root); 
    }
    //right right case
    if(bf<-1 && val > root->right->data){
        return leftrotate(root); 
    }
    //left right case
    if(bf>1 && val > root->left->data){
        root->left = leftrotate(root->left);
        return rightrotate(root); 
    }
    //right left case
    if(bf<-1 && val < root->right->data){
        root->right = rightrotate(root->right);
        return leftrotate(root); 
    }
    return root;
}

void preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);    
}

int main(){
    root=insert(root, 1);
    root=insert(root, 2);
    root=insert(root, 4);
    root=insert(root, 5);
    root=insert(root, 6);
    root=insert(root, 3);
    preorder(root);
    return 0;
}


/*
    y                              x
   / \                            / \
  x  T3    -right rotation->     T1  y  
 / \                                / \
T1 T2                              T2 T3
*/