#include<stdio.h>
int main() {
	int n,d,f,temp;
	printf("Enter length:");
	scanf("%d",&n);
	int ar[n];
	printf("Enter elements in array:");
	for(int i=0;i<n;i++) {
		scanf("%d",&ar[i]);
	}
	//Deletion
	printf("Enter element to be deleted:");
	scanf("%d",&d);
    for(int i=0;i<n;i++) {
		if(ar[i]==d){
            f=i;
            break;
        }
	}
	for(int i=f+1;i<n;i++,f++) {
		temp=ar[i];
		ar[i]=ar[f];
		ar[f]=temp;
	}
	
	printf("The array:");
	for(int i=0;i<n-1;i++) {
		printf("%d ",ar[i]);
	}
	return 0;
}