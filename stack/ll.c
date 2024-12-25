#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int val){
    struct Node *new, *ptr;
    new = malloc(sizeof(struct Node));
    new->data = val;
    new->next = NULL;
    if (top == NULL)
        top = new;
    else {
        new->next = top;
        top = new;
    }
}

void pop(){
    struct Node *ptr = top;
    if(top == NULL){
        printf("Underflow");
    }
    else{
        top = ptr->next;
        free(ptr);
        printf("Element popped\n");
    }
}

void display(){
    struct Node *ptr = top;
    printf("Linked List:\n");
    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    int choice, val, n;
    while (1) {
        printf("\nChoose:\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter n: ");
                scanf("%d", &n);
                int i;
                printf("Enter Elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &val);
                    push(val);
                }
                printf("Element pushed\n");
                display();
                break;
            case 2:
                pop(); display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...");
                return 0;
            default:
                printf("Invalid Input\n");
        }
    }
}