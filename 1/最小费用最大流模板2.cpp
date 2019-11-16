#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

 
const int N=4e2+5,M=1e5+5;
const int INF=0x3f3f3f3f;
int n,m,tot,lnk[N],cnr[N],ter[M],nxt[M],cap[M],cost[M],dis[N],ret;
bool vis[N];

void init(){
	tot=1;
	ret=0;
	memset(lnk,-1,sizeof(lnk));
}
void add(int u,int v,int w,int c) {
    ter[++tot]=v,nxt[tot]=lnk[u],lnk[u]=tot,cap[tot]=w,cost[tot]=c;
}
void addedge(int u,int v,int w,int c) {
    add(u,v,w,c),add(v,u,0,-c);
}
int spfa(int s,int t) {
    memset(dis,0x3f,sizeof(dis));
    memcpy(cnr,lnk,sizeof(lnk));
    queue<int> q;
    q.push(s),dis[s]=0,vis[s]=1;
    while(!q.empty()) {
        int u=q.front(); q.pop(),vis[u]=0;
        for(int i=lnk[u];i!=-1;i=nxt[i]) {
            int v=ter[i];
            if(cap[i]&&dis[v]>dis[u]+cost[i]) {
                dis[v]=dis[u]+cost[i];
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    return dis[t]!=INF;
}
int dfs(int u,int t,int flow) {
    if(u==t) return flow;
    vis[u]=1;
    int ans=0;
    for(int i=cnr[u];i!=-1;i=nxt[i]) {
        cnr[u]=i;
        int v=ter[i];
        if(!vis[v]&&cap[i]&&dis[v]==dis[u]+cost[i]) {
            int x=dfs(v,t,min(cap[i],flow-ans));
            if(x) ret+=x*cost[i],cap[i]-=x,cap[i^1]+=x,ans+=x;
        }
    }
    vis[u]=0;
    return ans;
}
int mcmf(int s,int t) {
    int ans=0;
    while(spfa(s,t)) {
        int x;
        while((x=dfs(s,t,INF))) ans+=x;
    }
    return ans;
}
int main() {
    scanf("%d%d",&n,&m);  //n个点,m条边 
	init();
	while(m--) {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        addedge(u+n,v,1,c);//建边，容量1，费用c （自动反向建边） 
    }
    for(int i=1;i<=n;++i) addedge(i,i+n,1,0);//拆点 
    int s=1+n,t=n;//起点终点 
    int ans=mcmf(s,t);//网络流 
    printf("%d %d\n",ans,ret);
    return 0;
}
