#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;
int map[1005][1005];
int v[1005];
int cost[1005][1005];
int n,m;
void dd(int s,int t)
{
	int i,j,min,next=s;
	int dis[1005],dcost[1005];
	for(i=1;i<=n;i++)
	{
		dis[i]=map[s][i];
		dcost[i]=cost[s][i];
		v[i]=0;
	}
	v[s]=1;
	for(i=1;i<=n;i++)
	{
		min=99999;
		for(j=1;j<=n;j++)
		{
			if(v[j]==0&&min>dis[j])
			{
				next=j;
				min=dis[j];
			}
		}
		v[next]=1;
		for(j=1;j<=n;j++)
		{
			if(v[j]==0)
			{
				if(dis[j]>dis[next]+map[next][j])
				{
					dis[j]=dis[next]+map[next][j];
					dcost[j]=dcost[next]+cost[next][j];
				}
				else if(dis[j]==dis[next]+map[next][j]&&dcost[j]>dcost[next]+cost[next][j])
				  dcost[j]=dcost[next]+cost[next][j];
			}
		}
	}
	printf("%d %d\n",dis[t],dcost[t]);
	return;
}



int main()
{
	int i,j,s,t,a,b,d,p;
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		for(i=1;i<=n;i++)
		  for(j=1;j<=n;j++)
		  {
		  	if(i==j)
		  	{
		  		map[i][j]=0;
		  		cost[i][j]=0;
			}
			else 
			{
				map[i][j]=99999;
				cost[i][j]=99999;
			}
		  }
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&a,&b,&d,&p);
			if(map[a][b]>d)
			{
				map[a][b]=map[b][a]=d;
				cost[a][b]=cost[b][a]=p;
			}
			else if(map[a][b]==d&&cost[a][b]>p)
			  cost[a][b]=cost[b][a]=p;
		}
		scanf("%d%d",&s,&t);
		dd(s,t);
	}
	return 0;
}

