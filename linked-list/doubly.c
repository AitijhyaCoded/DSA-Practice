#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *start = NULL;

void create(int val) {
    struct Node *new, *ptr;
    new = malloc(sizeof(struct Node));
    new->data = val;
    new->next = NULL;
    if (start == NULL){
        start = new;
        new->prev = NULL; 
    }
    else {
        ptr = start;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
        new-> prev = ptr;
    }
}

void display(){
    struct Node *ptr = start;
    printf("Linked List:");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void insert(int val, int pos){
    struct Node *new, *ptr, *preptr;
    new = malloc(sizeof(struct Node)); 
    new->data = val;
    if(pos==1){
        new->next = start;
        new->prev = NULL;
        start->prev = new;
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
        new->prev = preptr;
        new->next = ptr;
        ptr->prev = new;
    }
}

void delete(int pos){
    struct Node *ptr, *temp1, *temp2;
    ptr = start;
    if (pos == 1) {
            start = ptr->next;
            start->prev = NULL;
            free(ptr);
    }
    else{
        int i=1; ptr = start; 
        while(i<pos-1){
            ptr = ptr->next;
            i++;
        }
        temp1 = ptr->next;
        ptr->next = temp1->next;
        temp2 = temp1->next;
        temp2->prev = ptr;
        free(temp1);
    }
}

void search(int val){
    struct Node *ptr = start; 
    int i=1;
    while(ptr!=NULL){
        if(ptr->data==val){
            printf("Element found at %dth position",i);
            return;
        }
        ptr = ptr->next;
        i++;
    }
    printf("Element not found :(");
}


int main(){
    int choice, val, pos, n, ans=1;
    while(ans==1) {
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
                insert(val,pos); display();
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                delete(pos); display();
                break;
            
            default:
                printf("Invalid Input\n");
        }
        printf("\nEnter 1 to continue:");
        scanf("%d",&ans);
    }

    return 0;
}
