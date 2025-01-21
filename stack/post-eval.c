#include<stdio.h>
#include<string.h>
#define MAX 100
int stack[MAX];
int top=-1;
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==MAX-1;
}
void push(int val){
    if(isFull())
        printf("Overflow");
    else
        stack[++top]=val;
}
int pop(){
    if(isEmpty()){
        printf("Underflow");
        return 0;
    }
    else
        return stack[top--];
}
int isOper(char x){
    switch (x) {
        case '+':
        case '-': 
        case '*':
        case '/':
        case '%': return 1;
        default: return 0;
    }
}
int main(){
    char exp[MAX]; int dig=0, res=0, oprnd1=0, oprnd2=0;
    printf("Enter postfix expression:");
    fgets(exp, MAX, stdin);
    printf("Result:");
    char *e=exp;
    while(*e!='\0'){
        if(*e>='0' && *e<='9'){
            dig=*e-'0';
            push(dig);
        }
        else if(isOper(*e)){
            oprnd2=pop(); oprnd1=pop();
            switch (*e) {
                case '+': res=oprnd1+oprnd2; break;
                case '-': res=oprnd1-oprnd2; break;
                case '*': res=oprnd1*oprnd2; break;
                case '/': res=oprnd1/oprnd2; break;
                case '%': res=oprnd1%oprnd2; break;
            }
            push(res);
        }
        e++;
    }
    res=pop();
    printf("%d", res);
    return 0;
}