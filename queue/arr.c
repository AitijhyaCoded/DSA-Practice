#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int i, n, choice, front = -1, rear = -1;

void insert(){
    int val;
    if(rear==MAX-1){
        printf("Overflow");
    }
    else{
        if(front==-1 && rear==-1){
            front=0; rear=0;
        }
        printf("Enter elements:");
        for(i=0;i<n;i++){
            scanf("%d",&val);
            rear++;
            queue[rear]=val;
        }
    }
}

int delete(){
    if(front==-1||front>rear){
        printf("Underflow");
    }
    else{
        int val=queue[front];
        front++;
        return val;
    }
}

void display(){
    printf("Queue:\n");
    for(i=front+1;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    if(front==-1 && rear==-1){
        printf("Empty queue!");
    }
}

int main(){
    printf("Enter n:");
    scanf("%d",&n);
    while (1) {
        printf("\nChoose:\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                insert();
                break;
            case 2:
                delete();
                break; 
            case 3:
                display();
                break;
            case 4:
                printf("Bye");
                return 0; 
                break;
            default:
                printf("Invalid Input\n");
        }
    }
}