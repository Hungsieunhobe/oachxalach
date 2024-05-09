#include <stdio.h>
#define N 8
int a[N];
int n,Q;
// data structure for data input generation
int cand[N];
int sz;

void input(char* filename){
    FILE* f = fopen(filename,"r");
    fscanf(f,"%d%d",&n,&Q);
    for(int i = 0; i< n; i++)        fscanf(f,"%d",&a[i]);
    fclose(f);
}

void swap(int i, int j){
    int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
}

void heapify(int i, int n){
    int L = 2*i + 1;
    int R = 2*i+2;
    int max = i;
    if(L < n && a[L] > a[max]) max = L;
    if(R < n && a[R] > a[max]) max = R;
    if(max != i){
        swap(i,max); heapify(max,n);
    }
}

void buildHeap(){
    for(int i = n/2; i >= 0; i--) heapify(i,n);
}

void heapSort(){
    buildHeap();
    for(int i = n - 1; i > 0; i--){
        swap(0,i); heapify(0, i-1); 
    }
}

int binarySearch(int L, int R, int Y){
    // return 1 if Y appears in the sequence a[L,...,R]
    if(L > R) return 0;
    if(L == R) if(a[L] == Y) return 1; else return 0;
    int m = (L+R)/2;
    if(a[m] == Y) return 1;
    if(a[m] > Y) return binarySearch(L,m-1,Y);
    return binarySearch(m+1,R,Y);
}

void binarySearchSolve(){
    heapSort();
    //for(int i = 0; i < n; i++) printf("%d ", a[i]);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int ok = binarySearch(i+1,n,Q-a[i]);
        cnt += ok;
    }
    printf("\nresult = %d\n",cnt);
}
int main(){
	input("arr.txt") 
    binarySearchSolve();
    
    return 0;
}




