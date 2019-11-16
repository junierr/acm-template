/*
×ÖµäÐòµÚkµÄ×Ó´® 
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
int c[MAXLEN*2]; 
int a[MAXLEN*2];
int r[MAXLEN*2];
void tosort(){
	for(int i=0;i<sz;i++) c[st[i].len]++;
	for(int i=1;i<=sz;i++) c[i]+=c[i-1];
	for(int i=sz;i>0;i--) a[c[st[i].len]--]=i;
	for(int i=sz;i>0;i--){
		int p=a[i];
		r[p]++;
		for(int j=0;j<26;j++){
			if(st[p].nex[j]){
				r[p]+=r[st[p].nex[j]];
			}
		} 
	} 
}

void query(int k){
	int now=0;
	while(k){
		for(int i=0;i<26;i++){
			if(st[now].nex[i]){
				int p=st[now].nex[i];
				if(r[p]>=k){
					now=p;
					putchar('a'+i);
					k--;
					break;
				}
				else{
					k-=r[p];
				}
			}
		}
	}
	puts("");
}

int main(){
	
	int n,k;
	scanf("%s",s);
	int len=strlen(s);
	sz=0;
	sam_init();
	for(int i=0;i<len;i++){
		sam_extend(s[i]-'a');
	}
	tosort(); 
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		query(k);
	}
	return 0;
} 
