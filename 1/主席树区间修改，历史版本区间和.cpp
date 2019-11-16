#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+6;
int rt[maxn];
vector<int> v;
int getid(int x) { //ÀëÉ¢»¯ 
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}


struct Chairman_tree
{
    int cnt;
    struct node{
        int l,r;
        ll sum;
        ll ans;
    }a[40*maxn];
    void pushup(int x){
    	a[x].ans=a[a[x].l].ans+a[a[x].r].ans;
	}
    
	int build(int l,int r){
		int x=(++cnt);
		a[x].sum=0;
		if(l==r){
			scanf("%lld",&a[x].ans);
			a[x].l=a[x].r=0;
			return x;
		}
		int mid=(l+r)>>1;
		a[x].l=build(l,mid);
		a[x].r=build(mid+1,r);
		pushup(x);
		return x;		
	}
	
	void update(int &x,int y,int L,int R,int l,int r,ll v)
    {
        a[++cnt]=a[y];
        x=cnt;
		a[x].ans=a[y].ans+v*(R-L+1); 
        if(L<=l&&r<=R){
        	a[x].sum+=v;
        	return;
		}
        int mid=(l+r)>>1;
        if(R<=mid)
            update(a[x].l,a[y].l,L,R,l,mid,v);
        else if(L>mid)
            update(a[x].r,a[y].r,L,R,mid+1,r,v);
        else{
        	update(a[x].l,a[y].l,L,mid,l,mid,v);
        	update(a[x].r,a[y].r,mid+1,R,mid+1,r,v);
		}    
    }
    ll query(int x,int L,int R,int l,int r){
      	ll sum=a[x].sum*(R-L+1);
      	if(L<=l&&r<=R) 
      	  return a[x].ans;
      	int mid=(l+r)>>1;
		if(R<=mid)
		    sum+=query(a[x].l,L,R,l,mid);
		else if(L>mid)
		    sum+=query(a[x].r,L,R,mid+1,r);
		else{
			sum+=query(a[x].l,L,mid,l,mid);
			sum+=query(a[x].r,mid+1,R,mid+1,r);
		}		  
		return sum;
    }
}seg;


int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		seg.cnt=0;
		int time=0;
		rt[0]=seg.build(1,n);
		while(m--){
			char s[5];
			scanf("%s",s);
			if(s[0]=='Q'){
				int l,r;
				scanf("%d%d",&l,&r);
				printf("%lld\n",seg.query(rt[time],l,r,1,n));
			}
			else if(s[0]=='C'){
				int l,r;
				ll x;
				scanf("%d%d%lld",&l,&r,&x);
				seg.update(rt[time+1],rt[time],l,r,1,n,x);
				time++;
			}
			else if(s[0]=='H'){
				int l,r,root;
				scanf("%d%d%d",&l,&r,&root);
				printf("%lld\n",seg.query(rt[root],l,r,1,n));
			}
			else{
				scanf("%d",&time);
			}
		}
	}
	return 0;
} 
