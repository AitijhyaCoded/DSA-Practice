#include <stdio.h>
//O(n^2)
int main() {
    int n, t, i, j, k, min;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[100];
    printf("Array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    for(i=0;i<n;i++){
        min=arr[i];
        k=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<min){ //finds min
                min=arr[j];
                k=j;
            }
        }
        t=arr[i]; //swaps min,arr[i]
        arr[i]=arr[k];
        arr[k]=t;
                       
    }
    printf("Sorted array:");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
        }
}