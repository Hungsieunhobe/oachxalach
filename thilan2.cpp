#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int D,M,Y,H,m,S;
	char id[20];
	char ans[20];
}Hihi;


void removeSpaces(char a[], char b[]){
    int i, j = 0;

    for (i = 0; i < strlen(a); i++) {
        if (a[i] != ' ' && a[i] != '\t' && a[i] != '\n') {
            b[j++] = a[i];
        }
    }
    b[j] = '\0'; // Thêm kí t? k?t thúc chu?i
}
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	Hihi ng[20];
	for(int i=0 ; i<N ; i++){
		scanf("%d-%d-%d-%d-%d-%d", &ng[i].D,&ng[i].M,&ng[i].Y,&ng[i].H,&ng[i].m,&ng[i].S);
		scanf("%s", ng[i].id);
		getchar();
		for(int j=0 ; j<M ; j++){
			scanf("%c", &ng[i].ans[j]);
			getchar();
		}
	}
	
	char str[20];
	scanf("%s",str);
	
	if(strcmp(str,"2020")==0 || strcmp(str,"2021")==0 || strcmp(str,"2022")==0 || strcmp(str,"2023")==0 || strcmp(str,"2024")==0){
		int x= atoi(str);
		int cnt=0;
		for(int i=0 ; i<N ; i++){
			if(ng[i].Y== x-2000){
				int dem=0;
				for(int k=0 ; k<i ; k++){
					if(strcmp(ng[i].id,ng[k].id)==0) dem++;
				}
				if(dem==0) cnt++; 
			}
		}
		printf("%d",cnt);
	}
	
	if(strcmp(str,"At")==0){
		int S; scanf("%d", &S);
		getchar();
		char B;scanf("%c",&B);
		getchar();
		int cnt=0;		
		
		for(int i=0 ; i<N ; i++){
			if(ng[i].ans[S] == B){
				int dem=0;
				for(int j=0 ; j<i ; j++){
					if(strcmp(ng[i].id,ng[j].id)==0) dem++;
				}
				if(dem==0)cnt++;
			}
		}
		printf("%d",cnt);
	}
	
	if(strcmp(str,"Hour:")==0){
		int x; scanf("%d",&x);
		getchar();
		int cnt = 0;
		for(int i=0 ; i<N ; i++){
			if(ng[i].H==x){
				int dem=0;
				for(int j=0 ; j<i ; j++){
					if(strcmp(ng[i].id,ng[j].id)==0) dem++;
				}
				if(dem==0) cnt++;
			}
		}
		printf("%d", cnt);
	}
	
	if(strcmp(str,"Time:")==0){
		int x;scanf("%d",&x);getchar();
		char a;scanf("%c",&a);getchar();
		int cnt=0;
		for(int i=0 ; i<N ; i++){
			int count=0;
			for(int j=0 ; j<M ; j++){
				if(ng[i].ans[j]==a){
					count++;
				}
			}
			if(count==x){
				int dem=0;
				for(int k=0 ; k<i ; k++){
					if(strcmp(ng[i].id,ng[k].id)==0) dem++;
				}
				if(dem==0) cnt++;
			}
		}
		
	 printf("%d",cnt);
	} 
	
	if(strcmp(str,"Review:")==0){
		char a[20];
		fgets(a,sizeof(a),stdin);
		char A[20];
		removeSpaces(a,A);
		int cnt=0;
		int b[N];
		for(int i=0 ; i<N ; i++){
			int count=0;
	        for(int j=0 ; j<M ; j++){
	        	if(ng[i].ans[j]==A[j]) count++;
			}
			b[i] = count;
		} 
		int max = b[0]; 
		int index; 
		for(int i=1 ; i<N ; i++){
			if(b[i]>max){
				max = b[i];
				index = i; 
			}
		}
		int ct=0;
		for(int i=0 ; i<N ; i++){
			if(b[i]==max) ct++; 
		} 
		for(int i=0 ; i<N ; i++){
			for(int k=0 ; k<i ; k++){
				if(strcmp(ng[i].id,ng[k].id)==0) ct--;
			}
		}
		if(ct == 1) printf("%s",ng[index].id);
		else printf("%d",ct); 
	}
	
	return 0;
} 
