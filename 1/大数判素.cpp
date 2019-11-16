#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<queue>
#include<set>
#include<vector> 
#include<map>
#define inf 0x3f3f3f3f
using namespace std;

long long add(long long a,long long b,long long mod){
	long long ans=0;
	while(b){
		if(b&1)ans=(ans+a)%mod;
		a=(a*2)%mod;
		b=b>>1;
	}
	return ans;
}
long long pow(long long a,long long n,long long mod){
	if(n>1){
		long long tmp=pow(a,n>>1,mod)%mod;
		tmp=add(tmp,tmp,mod);
		if(n&1)tmp=add(tmp,a,mod);
		return tmp;
	}
	return a;
}
bool check(long long n,long long a){
	long long d=n-1;
	long long s=0;
	long long i;
	while(!(d&1)){
		d=d>>1;
		s++;
	}
	long long tmp=pow(a,d,n);
	if(tmp==1||tmp==-1){
		return 1;
	}
	for(i=0;i<s;i++){
		if(tmp==n-1)return 1;
		tmp=add(tmp,tmp,n);
	}
	return 0;
}
bool ispri(long long n){
	long long ck[8]={3,4,7,9,11,13,19,23};
	for(int i=0;i<8;i++){
		if(n==ck[i])return 1;
		if(n%ck[i]==0)return 0;
		if(n>ck[i]&&!check(n,ck[i]))return 0;
	}
	return 1;
}

int main(){
	int T;
	long long n,p;
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
			if(ispri(n)){
				printf("1\n");
			}	
			else printf("0\n");
	}
	return 0;
}

