#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef pair<int,int>pii;
typedef long long LL;
const int N=1e3+5;
const int mod=1e9+7;
int n,m,s,k,t,cnt,idl[N<<1],idr[N<<1];
bool vis[N][1001];
LL d[N][1001];
vector<pii>edg[1000005];
struct man{
    int v;
    int c;
    LL w;
    bool operator<(const man &e)const{
        return w>e.w;
    }
};
priority_queue<man>q;
void dij(int s){
    memset(d,-1,sizeof d);memset(vis,0,sizeof vis);
    d[s][0]=0;
    q.push(man{s,0,0});
    while(!q.empty()){
        int u=q.top().v,c=q.top().c;q.pop();

        if(vis[u][c])continue;
        vis[u][c]=1;
        for(int i=0;i<edg[u].size();++i){
            int v=edg[u][i].first,w=edg[u][i].second;
            if(!vis[v][c]&&(d[v][c]==-1||d[v][c]>d[u][c]+w)){
                d[v][c]=d[u][c]+w;
                q.push(man{v,c,d[v][c]});
            }
            if(c<k){
                if(!vis[v][c+1]&&(d[v][c+1]==-1||d[v][c+1]>d[u][c])){
                    d[v][c+1]=d[u][c];
                    q.push(man{v,c+1,d[v][c+1]});
                }
            }
        }
    }
}
int main()
{
    int x,y,w;
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&s,&t);
    while(m--)
    {
        scanf("%d%d%d",&x,&y,&w);
        edg[x].push_back(make_pair(y,w));
        edg[y].push_back(make_pair(x,w));
    }
    dij(s);
    LL ans=1000000000000;
    for(int i=0;i<=k;i++)ans=min(ans,d[t][i]);
    printf("%lld\n",ans);
    return 0;
}
