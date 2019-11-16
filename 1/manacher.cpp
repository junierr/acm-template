#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[10005];
char ss[30005];
int p[100005];

int init(){
	int i,len=strlen(s);
	ss[0]='@';
	for(i=1;i<=2*len;i+=2){
		ss[i]='#';
		ss[i+1]=s[i/2];
	}
	ss[2*len+1]='#';
	ss[2*len+2]='!';
	return 2*len+1;
}

int manacher(int len){
	int pos=0,mx=0,ans=0;
	for(int i=1;i<=len;i++){
		if(i<mx) p[i]=min(p[pos*2-i],mx-i);
		else p[i]=1;
		while(ss[i+p[i]]==ss[i-p[i]]) p[i]++;
		if(mx<p[i]+i) mx=p[i]+i,pos=i;
		ans=max(p[i]-1,ans); 
	}
	return ans;
}

int main(){
	int len,len1;
	scanf("%s",s);
	len1=init();
	len=manacher(len1);
	printf("%d\n",len);
	return 0;
} 
