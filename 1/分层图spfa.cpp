#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define inf 0x3f3f3f3f
const int M=1e6+10,N=1e3+10,S=1e3+10;
int n,m,k,s,t;
struct mdzz1{
    int next,to,val;
}edge[M];
int head[M],cnt;
void addedge(int u,int v,int w){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    edge[cnt].val=w;
    head[u]=cnt;
}
int dis[N][S],vis[N][S];
struct mdzz{
    int sign,num;
}q[M];
int top;
bool cmp(mdzz p,mdzz q) {
    return dis[p.sign][p.num]>dis[q.sign][q.num];
}
#define push(x,y) q[top++]=(mdzz){x,y};push_heap(q,q+top,cmp)
#define pop() pop_heap(q,q+top--,cmp)
#define top() *q
#define empty() (!top)
void spfa(){
    memset(dis,inf,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s][0]=0;
    vis[s][0]=1;
    push(s,0);
    while(!empty()){
        mdzz u=top();
        pop();
        vis[u.sign][u.num]=0;
        for(int i=head[u.sign];i!=-1;i=edge[i].next){
            int tox=edge[i].to;
            //不用免费的情况
            if(dis[tox][u.num]>dis[u.sign][u.num]+edge[i].val){
                dis[tox][u.num]=dis[u.sign][u.num]+edge[i].val;
                if(!vis[tox][u.num])push(tox,u.num),vis[tox][u.num]=1;
            }
            //用免费的情况
            if(u.num+1<=k&&dis[tox][u.num+1]>dis[u.sign][u.num]){
                dis[tox][u.num+1]=dis[u.sign][u.num];
                if(!vis[tox][u.num+1])push(tox,u.num+1),vis[tox][u.num+1]=1;
            }       
        }
    }
}
int main(){
    scanf("%d%d%d%d%d",&n,&m,&s,&t,&k); 
	memset(head,-1,sizeof(head));
	cnt=0; 
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }
    spfa();
    printf("%d\n",dis[t][k]);
    return 0;
}
