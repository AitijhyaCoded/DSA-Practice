#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top=-1;
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==MAX-1;
}
void push(char val){
    if(isFull())
        printf("Overflow");
    else
        stack[++top]=val;
}
char pop(){
    if(isEmpty()){
        printf("Underflow");
        return '\0';
    }
    else
        return stack[top--];
}
int priority(char x){
    switch (x) {
        case '+':
        case '-': 
            return 1;
        case '*':
        case '/':
        case '%': 
            return 2;
        case '^': 
            return 3; 
        default:
            return -1;
    }
}
int main(){
    char exp[MAX];
    printf("Enter infix expression:");
    fgets(exp, MAX, stdin);
    printf("Postfix expression:");
    char *e=exp;
    while(*e!='\0'){
        if(isalnum(*e))
            printf("%c", *e);
        else if(*e=='(')
            push(*e);
        else if(*e==')'){
            while(!isEmpty() && stack[top]!='('){
                printf("%c", pop());
            }
            pop(); //remove (
        }
        else{
            while(!isEmpty() && (priority(*e)<=priority(stack[top]))){
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while(!isEmpty()){
        printf("%c", pop());
    }
    return 0;
}