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
	int p=lt,np=lt=++poi; t[np].len=t[p].len+1; t[np].sz=1;//��Ϊÿ���½��ĳ���Ϊi�ĵ�һ���Ƕ�����Ҷ�ӽڵ�
	for(;p&&!t[p].ch[c];p=t[p].fa) t[p].ch[c]=np;//�ҵ�һ����������
	if(!p){t[np].fa=rt;return;}//û�еĻ�ֱ�������
	int q=t[p].ch[c];//�ҵ���
	if(t[q].len==t[p].len+1){t[np].fa=q;return;}//����һ���ڵ㳤�Ⱥ���
	int nq=++poi;t[nq].len=t[p].len+1;//���̽ڵ� Ȼ��ԭ���Ľ��ڸ��̵�����
	memcpy(t[nq].ch,t[q].ch,sizeof(t[nq].ch));//ԭ��������Ҳ��Ҫ����
	t[nq].fa=t[q].fa;t[q].fa=t[np].fa=nq;//����ÿһ���ڵ����ӵ���Ӧ�ĸ���
	for(;p&&t[p].ch[c]==q;p=t[p].fa)	t[p].ch[c]=nq;//�޸ı�������ԭ�ڵ��
}
void build(){for(int i=2;i<=poi;i++)	add(t[i].fa,i);}//��������
int ans;
void dfs(int x)//��ֵ
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
