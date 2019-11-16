#include<bits/stdc++.h>
using namespace std;

const int N=1e5+6;
int head[N],du[N],seq[N],t[N];  
int indeg[N];
int ip,k,n; 
 
struct note
{
    int v,next;
} edge[N];
 
void init()
{
    memset(head,-1,sizeof(head));
    ip=0;
}
 
void add(int u,int v)
{
    edge[ip].v=v,edge[ip].next=head[u],head[u]=ip++;
}
 
int topo()///���ˣ�����ģ��
{
    queue<int>q;
    for(int i=1; i<=n; i++)
    {
        indeg[i]=du[i];
        if(indeg[i]==0)
            q.push(i);
    }
    bool res=false;
    while(!q.empty())
    {
        if(q.size()!=1)res=true;
        int u=q.front();
        q.pop();
        seq[k++]=u;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].v;
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }
    if(k<n)return -1;///�������򻷣���֮���ܽ�����������
    if(res)return 0;///���Խ����������򣬲���ֻ��Ψһһ�ַ�ʽ��seq���鼴��������õ�����
    return 1;///���Խ������������ж��������seq����������һ������
}

int main(){
	int m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	init();
	for(int i=1;i<=m1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		du[v]++;
	}
	k=0;
	topo();
	for(int i=0;i<n;i++){
		t[seq[i]]=i;
	}
	for(int i=1;i<=m2;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(t[u]<t[v]){
			printf("%d %d\n",u,v);
		}
		else{
			printf("%d %d\n",v,u);
		}
	}
}
