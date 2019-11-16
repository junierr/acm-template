#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[20];
int dp[20][2];

int dfs(int pos,int pre,int sta,bool limit){// sta状态：有6无6 
	if(pos==-1) return 1; //找完了 
	if(!limit&&dp[pos][sta]!=-1) return dp[pos][sta]; //记忆化(上一位没有达到上限，说明这个dp可以直接用) 
	int up=limit?a[pos]:9;//取上限，ture说明上一位已经达到上限，当前位有限制，false说明无限制 
	int tmp=0;
	for(int i=0;i<=up;i++){
		if(pre==6&&i==2) continue;
		if(i==4) continue;
		tmp+=dfs(pos-1,i,i==6,limit&&i==a[pos]);
	}
	if(!limit) dp[pos][sta]=tmp;
	return tmp;
}


int solve(int x){  //分解数位 
 	int pos=0;
	while(x){
		a[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1,-1,0,true);
}

int main(){
	int l,r;
	while(~scanf("%d%d",&l,&r)){
		memset(dp,-1,sizeof(dp));
		printf("%d\n",solve(r)-solve(l-1));
	}
	return 0;
} 
