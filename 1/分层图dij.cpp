#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int u[40001000],v[40001000],w[40001000],fir[40001000],nxt[40001000],cnt,n,m,k,s,t,dis[40000100],vis[40001000];
struct QNode{
    int dis,x;
    bool operator < (const QNode &b) const{
        return dis>b.dis;
    }
};
priority_queue<QNode> q;
void addedge(int ui,int vi,int wi){
    ++cnt;
    u[cnt]=ui;
    v[cnt]=vi;
    w[cnt]=wi;
    nxt[cnt]=fir[ui];
    fir[ui]=cnt;
}
void dij(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    q.push((QNode){0,s});
    while(!q.empty()){
        QNode u=q.top();
        q.pop();
        if(vis[u.x])
            continue;
        vis[u.x]=true;
        for(int i=fir[u.x];i;i=nxt[i]){
            if(dis[v[i]]>dis[u.x]+w[i]){
                dis[v[i]]=dis[u.x]+w[i];
                q.push((QNode){dis[v[i]],v[i]});
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d%d",&n,&m,&s,&t,&k);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        for(int j=1;j<=k+1;j++){
            addedge(a+(n*(j-1)),b+(n*(j-1)),c);
            addedge(b+(n*(j-1)),a+(n*(j-1)),c);
        }
        for(int j=1;j<=k;j++){
            addedge(a+(n*(j-1)),b+(n*(j)),0);
            addedge(b+(n*(j-1)),a+(n*(j)),0);    
        }
    }
    for(int i=1;i<=k;i++)
        addedge(t+(n*(i-1)),t+(n*i),0);
    dij(s);
    printf("%d\n",dis[t+k*n]);
    return 0;
}
