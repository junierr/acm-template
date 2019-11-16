#include<cstdio>
#include<algorithm>
using namespace std;
int per[120];
void init ()
{
	for(int i=1;i<=110;i++)
	per[i]=i;
}
struct node
{
	int u,v,w;
}road[150];
int cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(x==per[x])
	return x;
	else
	return per[x]=find(per[x]);	
}
int join(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	{
		per[fx]=fy;
		return 1;
	}
	else
	return 0;
}
int main()
{
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init ();  //初始化！很容易忘 
		if(n==0)
		break;
		for(i=0;i<n;i++)
		  scanf("%d%d%d",&road[i].u,&road[i].v,&road[i].w);
		sort(road,road+n,cmp); 
		int sum=0,cnt=1;
		for(i=0;i<n;i++)
		{
			if(join(road[i].u,road[i].v))//两者之前不能相连，否则成环，一定不是代价最小 
			{
				sum=sum+road[i].w;
				cnt++;
			}
		}
		if(cnt==m)  //如果最后连接的房屋数比总房屋数少，也不符合题意，只能两者相等 
		printf("%d\n",sum);
		else
		printf("?\n");
	}
	return 0;	
}


