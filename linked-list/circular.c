#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *start = NULL; 

void create(int val) {
    struct Node *new, *ptr;
    new = malloc(sizeof(struct Node));
    new->data = val;
    if (start == NULL)
        start = new;
    else {
        ptr = start;
        while (ptr->next != start){
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    new->next = start; 
}

void display(){ 
    struct Node *ptr, *postptr;
    ptr = start;
    postptr = ptr;
    printf("Linked List:");
    while(postptr != start->next){    
        printf("%d ", ptr->data);
        ptr = ptr->next;
        postptr = ptr-> next;
    }
}

void insert(int val, int pos){
    struct Node *new, *ptr, *preptr;
    new = malloc(sizeof(struct Node)); 
    new->data = val;
    if(pos==1){
        new->next = start;
        ptr = start; 
        while(ptr->next != start){    
            ptr = ptr->next;
        }
        ptr->next = new;
        start = new;
    }
    else{
        int i=1; ptr = start; preptr = ptr;
        while(i<pos){
            preptr = ptr;
            ptr = ptr->next;
            i++;
        }
        preptr->next = new;
        new->next = ptr;
    }
}

void delete(int pos){
    struct Node *ptr, *preptr, *postptr, *temp=start;
    if (pos == 1) {
        ptr = start; 
        start = ptr->next;
        while(ptr->next != temp){    
            ptr = ptr->next;
        }
        ptr->next = start;
    }
    else{
        int i=1; ptr = start; preptr = ptr;
        while(i<pos){
            preptr = ptr;
            ptr = ptr->next;
            postptr = ptr->next;
            i++;
        }
        preptr->next = postptr;
        free(ptr);
    }
}

void search(int val){
    struct Node *ptr, *postptr;
    ptr = start;
    postptr = ptr;
    int i=1;
    while(postptr != start->next){
        if(ptr->data==val){
            printf("Element found at %dth position",i);
            return;
        }
        ptr = ptr->next;
        postptr = ptr-> next;
        i++;
    }
    printf("Element not found :(");
}


int main(){
    int choice, val, pos, n, ans=1;
    while (ans==1) {
        printf("\nChoose:\n1.Create\n2.Display\n3.Search\n4.Insert\n5.Delete\nEnter choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter n: ");
                scanf("%d", &n);
                int i;
                printf("Enter Elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &val);
                    create(val);
                }
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 4:
                printf("Enter the element to insert: ");
                scanf("%d", &val);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insert(val,pos);
                display();
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                delete(pos);
                display();
                break;
            
            default:
                printf("Invalid Input\n");
        }
        printf("\nEnter 1 to continue:");
        scanf("%d",&ans);
    }
    return 0;
}
