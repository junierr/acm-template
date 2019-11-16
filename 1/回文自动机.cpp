/*
求出现次数最多的回文子串的个数 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1e6+100;
char s[maxn];
int next[maxn][26],fail[maxn],len[maxn];
int txt[maxn];
int cnt[maxn];
int tot,root0,root1,last,size;

int getfail(int x){
        while(txt[size-len[x]-1]!=txt[size]) x=fail[x];
        return x;
    }

int newnode(int l){
        len[tot]=l;
        memset(next[tot],0,sizeof(next[tot]));
        tot++; return tot-1;
    }

void init(){
        memset(cnt,0,sizeof(cnt)); 
		last=tot=size=0; txt[size]=-1;
        root0=newnode(0); root1=newnode(-1);
        fail[root0]=1; fail[root1]=0;
    }

void extend(int c){
        txt[++size]=c; int now=getfail(last);
        if(!next[now][c]){
            int tmp=newnode(len[now]+2);
            fail[tmp]=next[getfail(fail[now])][c];
            next[now][c]=tmp;
        }
        last=next[now][c];
        cnt[last]++;//
    }
    
int main(){
	scanf("%s",s);
	init();
    for(int i=0;s[i];i++){
    	extend(s[i]-'a');
	}
	long long ans=0;
	for(int i=tot-1;i>=0;i--){
		cnt[fail[i]]+=cnt[i];
		ans=max(ans,1LL*cnt[i]*len[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
