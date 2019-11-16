#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int dfn[10005],low[10005],scc[10005];
bool insta[10005];
int sta[10005];
vector<int> edge[3005];
int dfs_clock,top,scc_clock;
int n;
stack<int> mystack;
bool instack[10005];



void tarjan(int u){
	dfn[u]=low[u]=++dfs_clock;//标记时间戳
	sta[++top]=u;//入栈 
	insta[u]=true;//标记在栈里 
	for(int i=0;i<edge[u].size();i++){
		int v=edge[u][i];
		if(dfn[v]){
			if(insta[v])
			  low[u]=min(low[u],dfn[v]);
		}
		else {
		  tarjan(v);
	      low[u]=min(low[u],low[v]);
		}
	}
		if(dfn[u]==low[u]){
			++scc_clock;
			do{
				scc[u]=scc_clock;
				u=sta[top--];
				insta[u]=false;
			}while(low[u]!=dfn[u]);
		}	
}

 
/*void tarjan(int x)
{
       int i,y,m=edge[x].size();
       dfn[x]=low[x]=++dfs_clock;
       mystack.push(x);
       instack[x]=true;
       for (i=0;i<m;i++)
       {
               y=edge[x][i];
               if (!dfn[y])
               {
                      tarjan(y);
                      low[x]=min(low[x],low[y]);
               }else
               if (instack[y])
                      low[x]=min(low[x],dfn[y]);
       }
       if (low[x]==dfn[x])
       {
               scc_clock++;
               do
               {
                      x=mystack.top();
                      mystack.pop();
                      instack[x]=false;
                      scc[x]=scc_clock;
               }while(low[x]!=dfn[x]);
       }
       return;
} */
	
bool sat(){
	for(int i=1;i<=n*2;i++)
	  if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++)
  	   if(scc[i*2-1]==scc[i*2])
  	     return false;
	return true;
} 

int main(){
	int m,a1,a2,c1,c2;
	while(~scanf("%d",&n)){
		scanf("%d",&m);
		for(int i=1;i<=2*n;i++)
		  edge[i].clear();
		while(m--){
			scanf("%d%d%d%d",&a1,&a2,&c1,&c2);
			a1++;a2++;
			edge[a2*2-c2].push_back(a1*2-(1^c1));
			edge[a1*2-c1].push_back(a2*2-(1^c2));
		}
		memset(dfn,0,sizeof(dfn));
		memset(insta,false,sizeof(insta));
		memset(instack,false,sizeof(instack));
		memset(sta,0,sizeof(sta));
		dfs_clock=0;
		top=0;
		scc_clock=0;
		bool flag=sat();
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
