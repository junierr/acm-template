/*
��ϯ��2�������kС�� 
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
#define ll long long
#define gc getchar
#define maxn 200005
using namespace std;

inline ll read(){
    ll a=0;int f=0;char p=gc();
    while(!isdigit(p)){f|=p=='-';p=gc();}
    while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=gc();}
    return f?-a:a;
}int n,m,cnt,a[maxn],b[maxn];

struct ahaha{
    int v,ch[2];
}t[maxn*20];int num,rt[maxn];
#define lc t[i].ch[0]
#define rc t[i].ch[1]
#define Lc t[j].ch[0]
#define Rc t[j].ch[1]
void update(int &i,int j,int l,int r,int k){
    i=++num;t[i]=t[j];++t[i].v;
    if(l==r)return;
    int m=l+r>>1;
    if(k<=m)update(lc,Lc,l,m,k);
    else update(rc,Rc,m+1,r,k);
}
int query(int i,int j,int l,int r,int k){
    if(l==r)return l;
    int m=l+r>>1,v=t[Lc].v-t[lc].v;
    if(k<=v)return query(lc,Lc,l,m,k);
    return query(rc,Rc,m+1,r,k-v);
}

inline void solve(){
    int x=read(),y=read(),k=read();
    printf("%d\n",b[query(rt[x-1],rt[y],1,cnt,k)]);   //������Ҫ���������ԭ���������ɢ�����ֵ�����
}

int main(){
    n=read();m=read();
    for(int i=1;i<=n;++i)  //��Ҫ��ɢ��������û����
        a[i]=b[i]=read();
    sort(b+1,b+n+1);cnt=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;++i)   //��n��Ȩֵ�߶���
        update(rt[i],rt[i-1],1,cnt,lower_bound(b+1,b+cnt+1,a[i])-b);
    while(m--)
        solve();
    return 0;
}
