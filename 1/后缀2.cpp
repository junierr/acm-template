#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 20021225
#define ll long long
#define mxn 1000100
using namespace std;
 
struct node{int ch[26],len,fa,sz;}t[mxn*4];
struct edge{int to,lt;}e[mxn*4];
int poi,lt,rt,cnt,in[mxn*4];char ch[mxn];
void add(int x,int y){e[++cnt].to=y;e[cnt].lt=in[x];in[x]=cnt;}
int id(char c){return c-'a';}
void insert(int c)
{
	int p=lt,np=lt=++poi; t[np].len=t[p].len+1; t[np].sz=1;//因为每次新建的长度为i的点一定是独立的叶子节点
	for(;p&&!t[p].ch[c];p=t[p].fa) t[p].ch[c]=np;//找到一个连接它的
	if(!p){t[np].fa=rt;return;}//没有的话直接连向根
	int q=t[p].ch[c];//找到了
	if(t[q].len==t[p].len+1){t[np].fa=q;return;}//存在一个节点长度合适
	int nq=++poi;t[nq].len=t[p].len+1;//复刻节点 然后原来的接在复刻的上面
	memcpy(t[nq].ch,t[q].ch,sizeof(t[nq].ch));//原本的连接也需要复刻
	t[nq].fa=t[q].fa;t[q].fa=t[np].fa=nq;//对于每一个节点连接到相应的父亲
	for(;p&&t[p].ch[c]==q;p=t[p].fa)	t[p].ch[c]=nq;//修改本来连向原节点的
}
void build(){for(int i=2;i<=poi;i++)	add(t[i].fa,i);}//暴力连边
int ans;
void dfs(int x)//求值
{
	for(int i=in[x];i;i=e[i].lt){int y=e[i].to;dfs(y);t[x].sz+=t[y].sz;	}
	if(t[x].sz!=1)	ans=max(ans,t[x].sz*t[x].len);
}
int main()
{
	scanf("%s",ch+1);
	int len=strlen(ch+1);rt=lt=++poi;
	for(int i=1;i<=len;i++)	insert(id(ch[i]));
	build();dfs(rt);printf("%d\n",ans);
	return 0;
}
