#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

queue<int>dd;

int map[20][20],dis[20];
int n,m;


bool bfs()
{
    int i;
    dd=queue<int>();
    memset(dis,-1,sizeof(dis));
    dis[1]=0;
    dd.push(1);
    while(!dd.empty())
    {
        int cur=dd.front();
        dd.pop();
        for(i=1;i<=n;i++)
        {
            if(map[cur][i]&&dis[i]==-1)
            {
                dis[i]=dis[cur]+1;
                dd.push(i);
            }
        }
    }
    if(dis[n]>0) return 1;
    else return 0;
}

int dfs(int point,int maxx)
{
    int a,i;
    if(point==n) return maxx;
    for(i=1;i<=n;i++)
    {
        if(map[point][i]&&dis[i]==dis[point]+1&&(a=dfs(i,min(maxx,map[point][i]))))
        {
            map[point][i]-=a;
            map[i][point]+=a;
            return a;
        }
    }
    return 0;
}



int main()
{
    int T,x,y,c,i;
    scanf("%d",&T);
    int t=1;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(map,0,sizeof(map));
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&c);
            map[x][y]+=c;
        }
        int ans=0;
        while(bfs())
        {
            int a=dfs(1,999999);
            ans+=a;
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
