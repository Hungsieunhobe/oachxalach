#include <stdio.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a=*b;
	*b=tmp;
}
int partition(int a[], int l, int r){
	int pivot = a[r];
	int i = l-1;
	for(int j=l ; j<r ; j++){
		if( a[j] <= pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	++i;
	swap(&a[i], &a[r]);
	return i;
} 

void quicksort(int a[], int l, int b){
	if(l>=b) return;
	int p = partition(a, l, b);
	quicksort(a,l,p-1);
	quicksort(a,p+1,b);
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0 ; i<n ; i++){
		scanf("%d", &a[i]);
	}
	quicksort(a,0,n-1);
	for(int i=0 ;  i<n ; i++){
		printf("%d ",a[i]);
	}
}
