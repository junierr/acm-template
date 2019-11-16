#include <iostream>
#include <string>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
bool check[33000];
int phi[33000];
int p[33000];
int tot;
int n;




void pp(){
	memset(check,false,sizeof(check));
	phi[1]=1;
	tot=0;
	for(int i=2;i<=n;i++){
		if(!check[i]){
			p[tot++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<tot;j++){
			if(i*p[j]>n) break;
			check[i*p[j]]=true;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			else{
				phi[i*p[j]]=phi[i]*(p[j]-1);
			}
		}
	}
}


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
	    pp();
	    printf("%d\n",phi[n]);
	} 
	return 0;
}

