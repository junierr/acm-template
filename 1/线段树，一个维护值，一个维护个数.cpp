/*
区间更新 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;

long long a[200010],number[200010<<2],number2[200010<<2],bz[200010<<2],bz2[200010<<2];
//number记录数值，number2记录个数，bz为number的懒惰数组，bz2为number2的懒惰数组 
struct node{
	int id;
	long long b;
}no[200010];

void pushup(int rt){
	number[rt]=number[rt*2];
	if(number[rt*2+1]>number[rt])
	  number[rt]=number[rt*2+1];
}

bool cmp(const node &fi,const node &se){
	if(fi.b==se.b) return fi.id<se.id;
	return fi.b<se.b;
}

int to[200010];

void build(int l,int r,int rt){
	bz[rt]=0;
	number[rt]=0;
	bz2[rt]=0;
	if(l==r){
		number[rt]=0;
		number2[rt]=0;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	pushup(rt);
}

void pushdown(int rt,int l,int r){
	int mid=(l+r)/2;
	if(bz[rt]){
		bz[rt*2]+=bz[rt];
		bz[rt*2+1]+=bz[rt];
		number[rt*2]+=bz[rt];
		number[rt*2+1]+=bz[rt];
		bz[rt]=0;
	}
	if(bz2[rt]){
		bz2[rt*2]+=bz2[rt];
		bz2[rt*2+1]+=bz2[rt];
		number2[rt*2]+=bz2[rt];
		number2[rt*2+1]+=bz2[rt];
		bz2[rt]=0;
	}
}

void change(long long o,int L,int R,int l,int r,int rt){
	if(L>R) return;
	if(l==r){
		number[rt]+=o;
		number2[rt]+=1;
		return;
	}
	if(L<=l&&R>=r){
		number[rt]+=o;
		bz[rt]+=o;
		bz2[rt]+=1;
		return;
	}
	int mid=(l+r)/2;
	pushdown(rt,l,r);
	if(L<=mid) change(o,L,R,l,mid,rt*2);
	if(R>=mid) change(o,L,R,mid+1,r,rt*2+1);
	pushup(rt);
}

int query(long long k,int l,int r,int rt){
	if(l==r) return number2[rt];
	int mid=(l+r)/2;
	pushdown(rt,l,r);
	int ans;
	if(number[rt*2]>k) ans=query(k,l,mid,rt*2);
	else ans=query(k,mid+1,r,rt*2+1);
	pushup(rt);
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		build(1,n+1,1);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			no[i].b=a[i];
			no[i].id=i;
		}
		sort(no+1,no+1+n,cmp);
	//	for(int i=1;i<=n;i++){
	//		printf("%d %lld\n",no[i].id,no[i].b);
	//	}
		change(1e9,n+1,n+1,1,n+1,1);
		for(int i=1;i<=n;i++)
		  to[no[i].id]=i;
	//	for(int i=1;i<=n;i++)
	//	  printf("%d\n",to[i]);  
		for(int i=1;i<=n;i++){
			int k=query(m-a[i],1,n+1,1);
			printf("%d ",i-k);
			change(a[i],to[i],n+1,1,n+1,1);
		}
		
		printf("\n");  
		for(int i=1;i<=15;i++)
		  printf("%d ",number[i]);
	} 
	return 0;
} 
