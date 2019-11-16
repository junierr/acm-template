/*
若要求所有，则乘上a的质因数即可 
*/

#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
} 

int main(){
	int T;
	long long a,b,c;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&a,&c);
		long long b=c/a;
		long long num=gcd(a,b);
		while(num>1){
			a=a/num;
			b=b*num;
			num=gcd(a,b);
		}
		printf("%lld\n",b);
	}
	return 0;
}
