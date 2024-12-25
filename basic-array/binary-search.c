#include <stdio.h>
//comment out for: for loops
int main() {
    int n, lb, ub, mid, p, s, c=0;
    printf("Enter n:");
    scanf("%d",&n);
    lb=0;
    ub=n; 
    //ub=n-1;
    int arr[100];
    printf("Array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search:");
    scanf("%d",&s);
    while(lb<=ub){ 
    //for(int i=0;i<n;i++){
        mid=(lb+ub)/2;
        if(arr[mid]==s){
            p=mid+1;
            c++;
            break;
        }
        else if(s>arr[mid]){
            lb=mid+1;
        }
        else if(s<arr[mid]){
            ub=mid-1;
        }
    }
    if(c>0){
        printf("Element %d in array at %dth position.",s,p);
    }
    else{
        printf("Element %d not found.",s);
    }
    return 0;
}