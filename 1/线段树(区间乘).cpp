#include<cstdio>
#include<cstring>
#define N 100005
using namespace std;

long long number[N<<2],bz[N<<2],bz2[N<<2];
int a[N];
long long mod;

void pushup(int rt){
	number[rt]=(number[rt*2]+number[rt*2+1])%mod;
}

void pushdown(int rt,int l,int r){  //lazy 
	int mid=(l+r)/2;
	number[rt*2]=(number[rt*2]*bz2[rt]+(mid-l+1)*bz[rt])%mod;
	number[rt*2+1]=(number[rt*2+1]*bz2[rt]+(r-mid)*bz[rt])%mod;
	bz2[rt*2]=bz2[rt*2]*bz2[rt]%mod;
	bz2[rt*2+1]=bz2[rt*2+1]*bz2[rt]%mod;
	bz[rt*2]=(bz[rt]+bz[rt*2]*bz2[rt])%mod;
	bz[rt*2+1]=(bz[rt]+bz[rt*2+1]*bz2[rt])%mod;
	bz[rt]=0;
	bz2[rt]=1;
} 



void ins1(int L,int c,int l,int r,int rt){ //单点更新 
	if(l==r){
		number[rt]+=c;
		return;
	}
	int mid=(l+r)/2;
	if(L<=mid) ins1(L,c,l,mid,rt*2);
	else ins1(L,c,mid+1,r,rt*2+1);
	pushup(rt);
}



void ins2(int L,int R,int c,int l,int r,int rt){ //区间更新 + 
	if(L<=l&&r<=R){
		number[rt]=(number[rt]+c*(r-l+1))%mod;
		bz[rt]=(bz[rt]+c)%mod;
		return;
	}
	int mid=(l+r)/2;
	pushdown(rt,l,r);
	if(L<=mid) ins2(L,R,c,l,mid,rt*2);
	if(R>mid) ins2(L,R,c,mid+1,r,rt*2+1);
	pushup(rt);
}

void ins3(int L,int R,int c,int l,int r,int rt){ //区间更新 * 
	if(L<=l&&r<=R){
		number[rt]=number[rt]*c%mod;
		bz2[rt]=bz2[rt]*c%mod;
		bz[rt]=(bz[rt]*c)%mod;
		return;
	}
	int mid=(l+r)/2;
	pushdown(rt,l,r);
	if(L<=mid) ins3(L,R,c,l,mid,rt*2);
	if(R>mid) ins3(L,R,c,mid+1,r,rt*2+1);
	pushup(rt);
}

long long query(int L,int R,int l,int r,int rt){//区间和 
	if(L<=l&&r<=R){
		return number[rt]%mod;
	}
	if(L>r||R<l) return 0;
	int mid=(l+r)/2;
	pushdown(rt,l,r);
	return (query(L,R,l,mid,rt*2)+query(L,R,mid+1,r,rt*2+1))%mod;
}


int main(){
	int n,m;
	scanf("%d%d%lld",&n,&m,&mod);
	for(int i=0;i<=4*n;i++){
		number[i]=0;
		bz[i]=0;
		bz2[i]=1;
	}
	for(int i=1;i<=n;i++){
	  scanf("%d",&a[i]);  
      ins1(i,a[i],1,n,1);
	}
	while(m--){
		int p,x,y,k;
		scanf("%d",&p);
		if(p==2){
			scanf("%d%d%d",&x,&y,&k);
			ins2(x,y,k,1,n,1);
		}
		else if(p==1){
			scanf("%d%d%d",&x,&y,&k);
			ins3(x,y,k,1,n,1);
		}
		else{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(x,y,1,n,1)%mod);
		}
	}
	return 0;
} 
