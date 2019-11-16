/*
1e18�Ļ���ֻҪ����1/5�η�����4000������������
Ȼ��ʣ�µ������Ϊp1,p2,p3,p4,p2*q2
�жϼ��� 
*/

#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#define inf 0x3f3f3f3f 
using namespace std;

const int maxn=4000+5;
int num=0;        //num ������ɸ���ڼ�������
int prime[maxn];      //���Ǹ�������
bool sf[maxn];        //�ж�������ǲ���������sf[i]�е�i�Ǵ�1��maxn����
typedef long long ll;
ll po(ll a,int b){
  ll ret=1;
  while(b--)ret*=a;
  return ret;
}

bool check(ll n,int k){  //�ж�һ������k�θ����Ƿ�Ϊ���� 
  ll t=pow(n,1.0/k);
  t-=5;
  if(t<1)t=1;
  while(po(t+1,k)<=n)t++;
  return po(t,k)==n;
}
void sushu(){         //���� ŷ��ɸ����
    
    memset(sf,true,sizeof(sf));
    for(int i=2;i<=maxn;i++){          //���ö��1~maxn
        if(sf[i]) prime[++num]=i;      //����������ͼ���������
        for(int j=1;j<=num;j++){       //�ڲ�ö��num���ڵ�����
            if(i*prime[j]>maxn) break; //ɸ�����
            sf[i*prime[j]]=false;      //ɸ��...
            if(i%prime[j]==0) break;   //�����ظ�ɸ
        }
    }
    sf[1]=false;
    sf[0]=false;  //1 0 ���� 
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
	//freopen("14156.in","r",stdin); //�����ض����������ݽ���in.txt�ļ��ж�ȡ
    //freopen("out.txt","w",stdout); //����ض���������ݽ�������out.txt�ļ���
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		printf("%d\n",solve(n));
	}
	//fclose(stdin);
	//fclose(stdout); 
	return 0;
} 
