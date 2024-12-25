#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int i, front = -1, rear = -1;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL;
struct Node *queue[MAX];

void insert(struct Node *val){
    if(rear==MAX-1){
        printf("Overflow");
    }
    else{
        if(front==-1 && rear==-1){
            front=0; rear=0;
        }
        else{
            rear++;
        }
        queue[rear]=val;
    }
}

int isEmpty(){
    if(front==-1||front>rear)
        return 1;
    else
        return 0;
}

struct Node *delete(){
    if(isEmpty()==1){
        printf("Underflow");
    }
    else{
        struct Node *val;
        val=queue[front];
        front++;
        return val;
    }
}

struct Node *create(){
    struct Node *new; 
    int ans, val;
    new = malloc(sizeof(struct Node));
    printf("\nPress 1 to create new node or 0 to exit:");
    scanf("%d", &ans);
    if(ans==0){
        return NULL;
    }
    printf("Enter data:"); 
    scanf("%d", &val);
    new->data = val;
    printf("Enter the left child of %d", val);  
    new->left = create();
    printf("Enter the right child of %d", val); 
    new->right = create();
    return new;
}

void preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);    
}
void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);    
}
void postorder(struct Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);  
    printf("%d ", root->data);  
}

void levelorder(struct Node *root){
    struct Node *ptr;
    insert(root);
    while(isEmpty()==0){
        ptr=delete();
        if(ptr->left!=NULL)
            insert(ptr->left);
        if(ptr->right!=NULL)
            insert(ptr->right);
        printf("%d ", ptr->data);     
    }
}

int height(struct Node *root){
    int lheight, rheight;
    if(root==NULL)
        return 0;
    else{
        lheight=height(root->left);
        rheight=height(root->right);
        if(lheight>rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}

int totalnodes(struct Node *root){
    if(root==NULL)
        return 0;
    else{
        return(totalnodes(root->left)+totalnodes(root->right)+1);
    } 
}

int totalintnodes(struct Node *root){
    if((root==NULL)||((root->left==NULL)&&(root->right==NULL)))
        return 0;
    else
        return(totalintnodes(root->left)+totalintnodes(root->right)+1);
}

int totalextnodes(struct Node *root){
    if(root==NULL)
        return 0;
    else if((root->left==NULL)&&(root->right==NULL))
        return 1;
    else
        return(totalextnodes(root->left)+totalextnodes(root->right));
}

void mirror(struct Node *root){
    struct Node *temp;
    if(root!=NULL){
        mirror(root->left);
        mirror(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp; 
    }
}

void removeTree(struct Node *root){
    if(root!=NULL){
        removeTree(root->left);
        removeTree(root->right);
        free(root);
    }
}

int checkBST(struct Node *root){
    static struct Node *prev = NULL; 
    if(root != NULL){
        if(!checkBST(root->left))
            return 0;
        if(prev!=NULL && root->data <= prev->data)
            return 0;
        prev = root;
        return checkBST(root->right);
    }
    return 1;
}

int main(){
    int choice, val;
    while (1) {
        printf("\nChoose:\n1.Create\n2.Preorder\n3.Inorder\n4.Postorder\n5.Levelorder\n6.Height\n7.Total nodes\n8.Total internal nodes\n9.Total external nodes\n10.Mirror\n11.Remove\n12.Check BST\n13.Quit\nEnter choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                root = create();
                break;
            case 2:
                preorder(root);
                break; 
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root); 
                break;
            case 5:
                levelorder(root);
                break;
            case 6:
                printf("Height of tree is %d",height(root)); 
                break;
            case 7:
                printf("Total no. of nodes is %d",totalnodes(root)); 
                break;
            case 8:
                printf("Total no. of non-leaf nodes is %d",totalintnodes(root)); 
                break;
            case 9:
                printf("Total no. of leaf nodes is %d",totalextnodes(root)); 
                break;
            case 10:
                mirror(root); 
                break;
            case 11:
                removeTree(root); 
                root=NULL;
                break;
            case 12:
                if (checkBST(root))
                    printf("Tree is a BST");
                else
                    printf("Tree is not a BST");
                break;
            case 13:
                return 0;
                break;
            default:
                printf("Invalid Input\n");
        }
    }
}



// Example bst:
//       5
//      / \
//     3   6
//    / \
//   1   4 


// Recursive tree:
// checkBST(5)
// ├── checkBST(3)
// │   ├── checkBST(1)
// │   │   ├── checkBST(NULL) → returns 1  (left child of 1)
// │   │   ├── check `prev < 1` → passes (prev is NULL)
// │   │   ├── update prev to 1
// │   │   └── checkBST(NULL) → returns 1  (right child of 1)
// │   ├── returns 1  (subtree rooted at 1 is BST)
// │   ├── check `prev < 3` → passes (prev is 1)
// │   ├── update prev to 3
// │   └── checkBST(4)
// │       ├── checkBST(NULL) → returns 1  (left child of 4)
// │       ├── check `prev < 4` → passes (prev is 3)
// │       ├── update prev to 4
// │       └── checkBST(NULL) → returns 1  (right child of 4)
// │   ├── returns 1  (subtree rooted at 3 is BST)
// ├── check `prev < 5` → passes (prev is 4)
// ├── update prev to 5
// └── checkBST(6)
//     ├── checkBST(NULL) → returns 1  (left child of 6)
//     ├── check `prev < 6` → passes (prev is 5)
//     ├── update prev to 6
//     └── checkBST(NULL) → returns 1  (right child of 6)
//     ├── returns 1  (subtree rooted at 6 is BST)

// Final Result: Tree is a BST