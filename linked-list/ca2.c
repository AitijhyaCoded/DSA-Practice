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
    new->next = NULL;
    if (start == NULL)
        start = new;
    else {
        ptr = start;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
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

void delete(int pos){
    struct Node *ptr, *preptr, *postptr;
    ptr = start;
    if (pos == 1) {
            start = ptr->next;
            free(ptr);
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

int main(){
    int choice, val, pos, n, ans=1;
    while (ans==1) {
        printf("\nChoose:\n1.Create\n2.Display\n3.Delete\nEnter choice:");
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