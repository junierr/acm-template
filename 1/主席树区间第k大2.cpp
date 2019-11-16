#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+6;
int n,m,rt[maxn];
int h[maxn];
vector<int> v;
int getid(int x) { //ÀëÉ¢»¯ 
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}


struct Chairman_tree
{
    int cnt;
    struct node{
        int l,r;
        int sum;
    }a[40*maxn];
    void update(int l,int r,int &x,int y,int pos,int v)
    {
        a[++cnt]=a[y];
        x=cnt; a[x].sum++;
        if(l==r) return;
        int mid=(l+r)>>1;
        if(pos<=mid)
            update(l,mid,a[x].l,a[y].l,pos,v);
        else
            update(mid+1,r,a[x].r,a[y].r,pos,v);
    }
    int query(int l,int r,int x,int y,int k)
    {
      	if(l==r) return l;
		int mid=l+r>>1;
		int sum=a[a[y].l].sum-a[a[x].l].sum;
		//int sum=a[y].sum-a[x].sum;
		if(sum>=k) return query(l,mid,a[x].l,a[y].l,k);
		else return query(mid+1,r,a[x].r,a[y].r,k-sum); 
    }
}seg;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		v.clear();
		seg.cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&h[i]);
			v.push_back(h[i]);
		}
		sort(v.begin(),v.end());
		for(int i=1;i<=n;i++){
			int id=getid(h[i]);
			seg.update(1,n,rt[i],rt[i-1],id,h[i]);
		}
		while(m--){
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",v[seg.query(1,n,rt[l-1],rt[r],k)-1]);
		}
	}
	return 0;
} 
