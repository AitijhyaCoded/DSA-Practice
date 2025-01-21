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
void reverse(char *s){
    int lb=0; int ub=strlen(s)-1; 
    char t;
    while(lb<ub){
        t=s[lb];
        s[lb]=s[ub];
        s[ub]=t;
        lb++; ub--;
    }
}
int main(){
    char exp[MAX]; char res[MAX]; int i=0; char t;
    printf("Enter infix expression:");
    fgets(exp, MAX, stdin);
    printf("Prefix expression:");
    reverse(exp);
    char *e=exp;
    while (exp[i] != '\0'){
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
        i++;
    }
    i = 0;
    while(*e!='\0'){
        if(isalnum(*e))
            res[i++]=*e;
        else if(*e=='(')
            push(*e);
        else if(*e==')'){
            while(!isEmpty() && stack[top]!='('){
                res[i++]=pop();
            }
            pop();
        }
        else{
            while(!isEmpty() && (priority(*e)<=priority(stack[top]))){
                res[i++]=pop();
            }
            push(*e);
        }
        e++;
    }
    while(!isEmpty()){
        res[i++]=pop();
    }
    res[i] = '\0';
    reverse(res);
    puts(res);
    return 0;
}