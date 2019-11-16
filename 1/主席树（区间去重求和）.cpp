/*
假设加入的数字为x，如果x之前没有出现过，直接加入，否则删除前一个x，再加入x
*/

#include<bits/stdc++.h>
#define N 30005
using namespace std;
typedef long long ll;

int root[N];//加入第i个数之后版本的根 

struct Chairman_tree
{
    int cnt;
    struct node{
        int l,r;
        ll sum;
    }a[40*N];
    void update(int l,int r,int &x,int y,int pos,int v)
    {
        a[++cnt]=a[y];
        x=cnt; a[x].sum+=v;
        if(l==r) return;
        int mid=(l+r)>>1;
        if(pos<=mid)
            update(l,mid,a[x].l,a[y].l,pos,v);
        else
            update(mid+1,r,a[x].r,a[y].r,pos,v);
    }
    ll query(int l,int r,int pos,int x)
    {
        if(l>=pos)
            return a[x].sum;
        if(r<pos)
            return 0;
        int mid=(l+r)>>1;
        return query(l,mid,pos,a[x].l)+query(mid+1,r,pos,a[x].r);
    }
}seg;


int main(){
	int T;
	scanf("%d",&T);
	map<int,int>mp;
	while(T--){
		int n; 
		scanf("%d",&n);
		mp.clear();
		seg.cnt=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(mp[x]){ //存在过 
				seg.update(1,n,root[n+1],root[i-1],mp[x],-x);
				seg.update(1,n,root[i],root[n+1],i,x);
			}
			else
			  seg.update(1,n,root[i],root[i-1],i,x);
			mp[x]=i;  
		}
		int q;
		scanf("%d",&q);
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",seg.query(1,n,l,root[r]));
		}
	}
	return 0; 
}
