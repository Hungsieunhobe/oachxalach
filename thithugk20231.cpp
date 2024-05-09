#include <stdio.h>
#include <string.h>
#include <math.h>
int res[20];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int icon[n][2];
	for(int i=0 ; i<n ; i++){
		scanf("%d %d",&icon[i][0],&icon[i][1]); 
	}
	int xe[m+1];
	for(int i=1 ; i<m+1 ; i++){
		scanf("%d",&xe[i]); 
	}
	int time[n][m+1];
	for(int i=0 ; i<n ;i++){
		for(int j=0 ; j<m+1 ; j++){
			scanf("%d",&time[i][j]); 
		} 
	}
	
	for(int i=0 ; i<n ; i++){
		int dem = 0; 
		int stx=0, stn=0, endx=0, endn=0; 
		for(int j=1 ; j<m+1 ; j++){
			endn = time[i][j] + stn;
			endx = xe[j] + stx;
			int a = fmin(endx,endn) - fmax(stx,stn);
			if(a>0) dem+= a;
			stx += xe[j];
			stn += time[i][j];
			res[i] = dem;  
		} 
	} 
	int x; scanf("%d",&x);
	if(x==-2){
		int cnt=0;
		for(int i= 0 ; i<n ; i++){
			if(icon[i][0]==-1 && icon[i][1]==-1) cnt+= res[i]; 
		}printf("%d",cnt); 
	} 
	if(x==-1){
		int cnt=0;
		for(int i=0 ; i<n ; i++){
			if((icon[i][0]==-1 && icon[i][1]==0)||(icon[i][0]==0 &&icon[i][1]==-1)) cnt+=res[i]; 
		} printf("%d",cnt); 
	} 
	if(x==0){
		int cnt=0;
		for(int i=0 ; i<n ; i++){
			if((icon[i][0]==-1 &&icon[i][1]==1)||(icon[i][0]==1 &&icon[i][1]==-1)||(icon[i][0]==0 &&icon[i][1]==0)) cnt+=res[i]; 
		}
		printf("%d",cnt); 
	} 
	if(x==1){
		int cnt=0;
		for(int i=0 ; i<n ; i++){
			if((icon[i][0]==0&&icon[i][1]==1)||(icon[i][0]=1&&icon[i][1]==0)||(icon[i][0]==2&&icon[i][1]==-1)) cnt+=res[i]; 
		} printf("%d",cnt); 
	} 
	if(x==2){
		int cnt=0; 
		for(int i= 0 ;i<n ; i++){
			if((icon[i][0]==1&&icon[i][1]==1)||(icon[i][0]==2 && icon[i][1]==0 )) cnt+= res[i]; 
		} printf("%d", cnt); 
	} 
	if(x==3){
		int cnt=0;
		for(int i=0 ; i<n ; i++){
			if(icon[i][0]==2&& icon[i][1]==1) cnt+= res[i]; 
		} printf("%d",cnt); 
	} 
	if(x==4){
		int cnt=0;
		for(int i=0 ; i<n ; i++){
			if((icon[i][0]==1&&icon[i][1]==1)||(icon[i][0]==2&&icon[i][1]==1)) cnt+= res[i]; 
		} printf("%d",cnt); 
	} 
	if(x==5){
		int cnt=0;
		for(int i=0 ; i<n ; i++){
			if(icon[i][1]==-1) cnt+= res[i]; 
		} printf("%d", cnt); 
	} 
	if(x==6) printf(">1");
	
	return 0; 
	} 

