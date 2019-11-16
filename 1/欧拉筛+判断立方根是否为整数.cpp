/*
1e18的话，只要考虑1/5次方，即4000以内质数即可
然后剩下的情况即为p1,p2,p3,p4,p2*q2
判断即可 
*/

#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define inf 0x3f3f3f3f 
using namespace std;

const int maxn=4000+5;
int num=0;        //num 用来记筛到第几个质数
int prime[maxn];      //就是个素数表
bool sf[maxn];        //判断这个数是不是素数，sf[i]中的i是从1到maxn的数
typedef long long ll;
ll po(ll a,int b){
  ll ret=1;
  while(b--)ret*=a;
  return ret;
}

bool check(ll n,int k){  //判断一个数的k次根号是否为整数 
  ll t=pow(n,1.0/k);
  t-=5;
  if(t<1)t=1;
  while(po(t+1,k)<=n)t++;
  return po(t,k)==n;
}
void sushu(){         //核心 欧拉筛代码
    
    memset(sf,true,sizeof(sf));
    for(int i=2;i<=maxn;i++){          //外层枚举1~maxn
        if(sf[i]) prime[++num]=i;      //如果是质数就加入素数表
        for(int j=1;j<=num;j++){       //内层枚举num以内的质数
            if(i*prime[j]>maxn) break; //筛完结束
            sf[i*prime[j]]=false;      //筛掉...
            if(i%prime[j]==0) break;   //避免重复筛
        }
    }
    sf[1]=false;
    sf[0]=false;  //1 0 特判 
}

int solve(long long n){
	int ans=inf;
	for(int i=1;i<=num;i++){
				int now=0;
				
				if(ans==1) break;
				while(n%prime[i]==0){
					n=n/prime[i];
					now++;
				}
				if(now!=0) ans=min(now,ans);
				if(n==1) break;
			}					
	if(n==1&&ans!=inf) return ans;	
	else if(check(n,4)) return 4;
	else if(check(n,3)) return 3;
	else if(check(n,2)) return 2;
	else return 1;
}


int main(){
	long long n;
	sushu();
	int T;
	//freopen("14156.in","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
    //freopen("out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		printf("%d\n",solve(n));
	}
	//fclose(stdin);
	//fclose(stdout); 
	return 0;
} 
