#include <stdio.h>
//O(n^2)
int main() {
    int n, t, i, j, k;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[100];
    printf("Array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++){
        for(j=i;j>0;j--){
            if(arr[j-1]>arr[j]){
                t=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=t;
            }
        }
    }
    printf("Sorted array:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        }
}