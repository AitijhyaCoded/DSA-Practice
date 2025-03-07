#include<stdio.h>
int stack[100],i,choice,n,top=-1;
void push(){
    int val;
    if(top==n-1){
        printf("Overflow");
    }
    else{
        printf("Enter Elements: ");
        for (i = 0; i < n; i++) {
            scanf("%d", &val);
            top++;
            stack[top]=val;
        }
        printf("Element pushed");
    }
}
void pop(){
   if(top==-1){
    printf("Underflow");
   } 
   else{
    top--;
    printf("Element popped");
   }
}
void display(){
    printf("\nStack:");
    for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);  
    }
    if(top==-1){
        printf("Stack empty!");
    }
}
int main(){
    printf("Enter n: ");
    scanf("%d", &n);
    while (1) {
        printf("\nChoose:\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(); display();
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