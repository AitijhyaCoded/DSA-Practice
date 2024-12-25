#include<stdio.h>
int main() {
	int l,n,p,temp;
	printf("Enter length:");
	scanf("%d",&l);
	int ar[100];
	printf("Enter elements in array:");
	for(int i=0;i<l;i++) {
		scanf("%d",&ar[i]);
	}
	//Insertion
	printf("Enter element to be inserted:");
	scanf("%d",&n);
	printf("Enter index to insert:");
	scanf("%d",&p);
	for(int i=p;i<=l;i++) {
		temp=ar[i];
		ar[i]=n;
		n=temp;
	}
	
	printf("The array:");
	for(int i=0;i<=l;i++) {
		printf("%d ",ar[i]);
	}
	return 0;
}