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
		init ();  //��ʼ������������ 
		if(n==0)
		break;
		for(i=0;i<n;i++)
		  scanf("%d%d%d",&road[i].u,&road[i].v,&road[i].w);
		sort(road,road+n,cmp); 
		int sum=0,cnt=1;
		for(i=0;i<n;i++)
		{
			if(join(road[i].u,road[i].v))//����֮ǰ��������������ɻ���һ�����Ǵ�����С 
			{
				sum=sum+road[i].w;
				cnt++;
			}
		}
		if(cnt==m)  //���������ӵķ��������ܷ������٣�Ҳ���������⣬ֻ��������� 
		printf("%d\n",sum);
		else
		printf("?\n");
	}
	return 0;	
}


