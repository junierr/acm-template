#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

const int N = 1e6+10,M = 100;
char s[N],t[N];
map<int,char>ma;
vector<int>a,G[N];
vector<char>ans;
int vis[30],du[N],n,m;

void tobo()
{
    int res=0;
    int tt=n;
    while(1){
        int tmp=-1;
        for(int i=0;i<a.size();++i){  //找到第一名标记为tmp; 
            if(du[a[i]]==0){
                tmp=a[i];
                break;
            }
        }
        if(tmp==-1) break;
        ans.push_back(ma[tmp]);
        res++;
        du[tmp]=-1;
        for(int i=0;i<G[tmp].size();++i) du[G[tmp][i]]--;//将前驱中含有第一名的前驱数-- 
    }
    if(res==n) for(int i=0;i<res;++i) printf("%c",ans[i]);
    else printf("-1");
}

int main(){
	int q;
	scanf("%d%d",&n,&m);
	a.clear();
	for(int i=0;i<N;i++)
		G[i].clear();
	ans.clear();  
	for(int i=1;i<=m*(m-1)/2;i++){
		scanf("%s%d",s+1,&q);
		if(q>0) scanf("%s",t+1);
		memset(vis,0,sizeof(vis));
		int pre=-1;
		for(int j=1;j<=q;j++){
			vis[t[j]-'a']++;
			int num=vis[t[j]-'a'];
			int cnt=num*M+t[j]-'a';
			ma[cnt]=t[j];
			a.push_back(cnt);
			if(pre==-1){
				pre=cnt;
				continue;
			}
			du[cnt]++;
			G[pre].push_back(cnt);
			pre=cnt;
		}
	}	
		sort(a.begin(),a.end());
		a.erase(unique(a.begin(),a.end()),a.end());
		if(a.size()!=n) printf("-1\n");
		else tobo();
	
	return 0;
} 
