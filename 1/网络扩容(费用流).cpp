/*
扩容k，扩容1需要w的费用 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#define MAXN 1010
#define MAXM 5010
using namespace std;
 
const double eps=1e-6;
const int N=20000+10,maxn=50000+10,inf=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3f;
 
struct edge{
    int to,Next,c;
    int cost;
}e[maxn];
int cnt,head[N];
int s,t;
int dis[N],pre[N],path[N];
bool vis[N];
void add(int u,int v,int c,int cost)
{
    e[cnt].to=v;
    e[cnt].c=c;
    e[cnt].cost=cost;
    e[cnt].Next=head[u];
    head[u]=cnt++;
    e[cnt].to=u;
    e[cnt].c=0;
    e[cnt].cost=-cost;
    e[cnt].Next=head[v];
    head[v]=cnt++;
}
bool spfa()
{
    memset(pre,-1,sizeof pre);
    memset(dis,inf,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[s]=0;
    vis[s]=1;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];~i;i=e[i].Next)
        {
            int te=e[i].to;
            if(e[i].c>0&&dis[x]+e[i].cost<dis[te])
            {
                dis[te]=dis[x]+e[i].cost;
                pre[te]=x;
                path[te]=i;
                if(!vis[te])q.push(te),vis[te]=1;
            }
        }
    }
    return pre[t]!=-1;
}
int maxflow()
{
    int flow=0;
    while(spfa())
    {
        int f=inf;
        for(int i=t;i!=s;i=pre[i])
            if(e[path[i]].c<f)
               f=e[path[i]].c;
        flow+=f;
        for(int i=t;i!=s;i=pre[i])
        {
            e[path[i]].c-=f;
            e[path[i]^1].c+=f;
        }
    }
    return flow;
}
int mincostmaxflow()
{
    int cost=0,flow=0;
    while(spfa())
    {
        int f=inf;
        for(int i=t;i!=s;i=pre[i])
            if(e[path[i]].c<f)
               f=e[path[i]].c;
        flow+=f;
        cost+=dis[t]*f;
        for(int i=t;i!=s;i=pre[i])
        {
            e[path[i]].c-=f;
            e[path[i]^1].c+=f;
        }
    }
    return cost;
}
void init()
{
    memset(head,-1,sizeof head);
    cnt=0;
}
struct node{int u,v,c,w;}te[N];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    init();
    for(int i=0;i<m;i++)
    {
        int u,v,c,w;
        scanf("%d%d%d%d",&u,&v,&c,&w);
        add(u,v,c,0);
        te[i]={u,v,c,w};
    }
    s=1,t=n;
    int ans=maxflow();
    printf("%d ",ans);
    for(int i=0;i<m;i++)
        add(te[i].u,te[i].v,inf,te[i].w);
    s=n+1;add(s,1,k,0);
    printf("%d\n",mincostmaxflow());
    return 0;
}
