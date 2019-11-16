#include<cstdio>
#include<cstring>
using namespace std;

int map[105][105],mat[105],vis[105];
int n,m;

bool dfs(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(map[x][i]&&!vis[i])
        {
            vis[i]=1;
            if(!mat[i])
            {
                mat[i]=x;
                return 1;
            }
            else if(dfs(mat[i]))
            {
                mat[i]=x;
                return 1;
            }
        }
    }
    return 0;
}


int main()
{
    int k,i,x,y,j;
    int T=1;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        memset(map,0,sizeof(map));
        memset(mat,0,sizeof(mat));
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=1;
        }
        int ans=0;
        for(i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i)) ans++;
        }
        int sum=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                int ret=0;
                memset(mat,0,sizeof(mat));
                if(map[i][j]==1)
                {
                    map[i][j]=0;
                    for(int t=1;t<=n;t++)
                    {
                      memset(vis,0,sizeof(vis));
                      if(dfs(t)) ret++;
                    }
                    if(ret!=ans) sum++;
                    map[i][j]=1; 
                }
            }
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",T++,sum,ans);
    }
    return 0;
}
