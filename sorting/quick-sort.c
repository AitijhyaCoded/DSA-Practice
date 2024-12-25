#include<stdio.h>

int partition(int arr[], int beg, int end){
    int pivot = arr[end];
    int i = beg-1;
    for(int j = beg; j < end; j++){
        if(arr[j] < pivot){
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = t;
    return (i+1);
}

void quick_sort(int arr[], int beg, int end){
    if(beg < end){
        int piv = partition(arr, beg, end);
        quick_sort(arr, beg, piv - 1);
        quick_sort(arr, piv + 1, end);
    }
}

int main(){
    int arr[100]; 
    int n; 
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Array: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
