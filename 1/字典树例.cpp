#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 2000010
using namespace std;
int tot=0,n;
int trie[maxn][26];
bool isw[maxn];
void insert(char *s,int rt)  //²åÈëµ¥´Ê
{
	for(int i=0;s[i];i++)
	{ 
		int x=s[i]-'a';
		if(trie[rt][x]==0)
		{
			trie[rt][x]=++tot;
		}
		rt=trie[rt][x];
	}
	isw[rt]=true;
 } 
 
bool find(char *s,int rt)
{
	for(int i=0;s[i];i++)
	{
		int x=s[i]-'a';
		if(trie[rt][x]==0)return false;
		rt=trie[rt][x];
	}
	return isw[rt];
 } 
 
char s[22];
int main()
{
	memset(trie,0,sizeof(trie));
	memset(isw,0,sizeof(isw));
	int rt=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		insert(s,rt);
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(find(s,rt)) printf("YES\n");
		else printf("NO\n");		
	}
	return 0;
 } 
