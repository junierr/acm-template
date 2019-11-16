/*
不同子串个数 
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<cstring>
#include<queue>
using namespace std;

struct state{
	int len,link;
	int nex[30];
	long long cnt; 
};

const int MAXLEN=100005;
state st[MAXLEN*2];
int sz,last;

void sam_init(){
	st[0].len=0;
	st[0].link=-1;
	sz++;
	last=0;
}

void sam_extend(int c){
	int cur=sz++;
	st[cur].len=st[last].len+1;
	int p=last;
	while(p!=-1&&!st[p].nex[c]){
		st[p].nex[c]=cur;
		p=st[p].link;
	}
	if(p==-1){
		st[cur].link=0;
	}
	else{
		int q=st[p].nex[c];
		if(st[p].len+1==st[q].len){
			st[cur].link=q;
		}
		else{
			int clone=sz++;
			st[clone].len=st[p].len+1;
			memcpy(st[clone].nex,st[q].nex,sizeof st[q].nex);
			st[clone].link=st[q].link;
			while(p!=-1&&st[p].nex[c]==q){
				st[p].nex[c]=clone;
				p=st[p].link;
			}
			st[q].link=st[cur].link=clone;
		}
	}
	last=cur;
}
char s[MAXLEN];
int b[MAXLEN*2];
bool cmp(int x,int y){
	return st[x].len>st[y].len;
}

int main(){
	
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int len=n;
	sz=0;
	sam_init();
	for(int i=0;i<len;i++){
		sam_extend(s[i]-'a');
	}
	for(int i=0;i<=sz;i++)
	   b[i]=i;
	sort(b,b+sz+1,cmp);   	
	for(int i=0;i<sz;i++)
	  for(int j=0;j<26;j++)
        if(st[b[i]].nex[j])st[b[i]].cnt+=st[st[b[i]].nex[j]].cnt+1;
    printf("%lld\n",st[0].cnt);    
	return 0;
} 
