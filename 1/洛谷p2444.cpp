/*
��ac�Զ�������trieͼ�Ļ����ϣ����Σ�ս�㣨e���飩������failָ��Σ�յ�ҲΪΣ�գ�Ȼ��dfs��
������ 
*/


#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int n;
int vis[N],use[N];

namespace AC{
    int tr[N][3],tot;
    int e[N],fail[N];
    
    void init(){
        memset(fail,0,sizeof(fail));
        memset(tr,0,sizeof(tr));
        memset(e,0,sizeof(e));
        tot=0;
    }
    void insert(char *s){ //e�����¼������� 
        int u=0;
        for(int i=1;s[i];i++){
            if(!tr[u][s[i]-'0'])tr[u][s[i]-'0']=++tot;
            u=tr[u][s[i]-'0'];
        }
        e[u]=1;//���Σ�ս�� 
    }
    queue<int> q;
    void build(){
        for(int i=0;i<=1;i++)if(tr[0][i])q.push(tr[0][i]);
        while(q.size()){
            int u=q.front();q.pop();
            for(int i=0;i<=1;i++){
                if(tr[u][i])fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
                else tr[u][i]=tr[fail[u]][i];
                if(e[fail[tr[u][i]]]) e[tr[u][i]]=1;  //failָ��Σ������ҲΪΣ�� 
            }
        }
    }
	bool dfs(int x){  //�һ� 
    	vis[x]=1;
    	for(int i=0;i<=1;i++){
    		int y=tr[x][i];
    		if(!y) continue;
    		if(vis[y]) return true;
			if(use[y]||e[y]) continue;
			use[y]=1;
			if(dfs(y)) return true; 
		}
		vis[x]=0;
		return false;
	}
}

char s[N];
int main(){
	scanf("%d",&n);
	AC::init();
    for(int i=1;i<=n;i++)scanf("%s",s+1),AC::insert(s);
    AC::build();
    memset(vis,0,sizeof(vis)); 
    memset(use,0,sizeof(use));
	bool ans=AC::dfs(0);
	if(ans) printf("TAK\n");
	else printf("NIE\n"); 
    return 0;
}
