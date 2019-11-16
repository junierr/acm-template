#include<bits/stdc++.h>
#define maxn 200005
using namespace std;

int lc[maxn<<5],rc[maxn<<5],h[maxn],rt[maxn],len[maxn<<5];
int tot;
double sum[maxn<<5];
double s[maxn];

void insert(int &now,int l,int r,int pos){
	lc[++tot]=lc[now];//����� 
	rc[tot]=rc[now];//�Ҷ��� 
	len[tot]=len[now]+1;//��¼������м������� 
	sum[tot]=sum[now]+pos;//ǰ׺�� 
	now=tot;
	if(l==r) return;
	int mid=(l+r)>>1;
	if(pos<=mid) insert(lc[now],l,mid,pos);
	else insert(rc[now],mid+1,r,pos);
}

double find(int u,int v,int l,int r,double p){
	if(!u&&!v) return 0;//�������������ڷ���0 
	if(p>r) return 0;//���궼����ֱ�ӷ���0 
	if(p<=l) return (sum[u]-sum[v])-(len[u]-len[v])*p;//��ȥ���ֵ��ܳ��� 
	int mid=(l+r)>>1;
	return find(lc[u],lc[v],l,mid,p)+find(rc[u],rc[v],mid+1,r,p); 
}


int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	tot=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
		insert(rt[i]=rt[i-1],1,100000,h[i]);//���� 
		s[i]=s[i-1]+h[i];//ǰ׺�� 
	}
	while(q--){
		int l,r,x,y;
		scanf("%d%d%d%d",&l,&r,&x,&y);
		double L=0,R=100000;
		double eps=1e-8;
		while(R-L>eps){  //�����Ҹ߶� 
			double mid=(L+R)*0.5;
			if(find(rt[r],rt[l-1],1,100000,mid)>=x*1.0/y*(s[r]-s[l-1]))
			  L=mid;
			else R=mid;   
		}
		printf("%.15lf\n",R);
	}
	return 0;
} 
