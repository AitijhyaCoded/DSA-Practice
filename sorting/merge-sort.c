#include<stdio.h>

void merge(int arr[], int beg, int mid, int end){
    int i= beg, j= mid+1, k=0;
    int temp[100];
    while((i<=mid)&&(j<=end)){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=end){
            temp[k]=arr[j];
            k++; j++;
        }
    }
    else{
        while(i<=mid){
            temp[k]=arr[i];
            k++; i++;
        }
    }
    for(int l=0;l<k;l++){
        arr[beg+l]=temp[l];
    }
}

void merge_sort(int arr[], int beg, int end){
    if(beg<end){
        int mid=(beg+end)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}

int main(){
    int arr[100]; int n;
    printf("Enter n:");
    scanf("%d",&n);
    printf("Array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr, 0, n-1);
    printf("Sorted Array:");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}

