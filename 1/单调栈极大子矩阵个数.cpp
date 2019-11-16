#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int up[3005][3005];
pair<int,int > sta[3005];

int main(){
	int n,m;
	for(int i=0;i<3005;i++)
	  for(int j=0;j<3005;j++){
	  	up[i][j]=0;
	  }
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			scanf("%c",&c);
			if(c=='1') {
				up[i][j]=up[i-1][j]+1;	
			}
		}
		getchar();
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=0;
		int l=-1;
		for(int j=1;j<=m+1;j++){
			int pos=j;
			while(cnt&&sta[cnt].first>up[i][j]){
				if(sta[cnt].second<=l) ans++;
				pos=sta[cnt].second;
				cnt--;
			}
			if(!up[i+1][j]) l=j;
			if(up[i][j]&&(!cnt||sta[cnt].first<up[i][j]))
			  sta[++cnt]={up[i][j],pos};
		}
	} 
	printf("%d\n",ans);
	return 0; 
}
