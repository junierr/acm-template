#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int z[100];
char s[1000];

int main(){
	scanf("%s",s);
	int len=strlen(s);
	int l=0,r=0;
	memset(z,0,sizeof(z));
	for(int i=1;i<len;i++){
		if(i<=r) z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<len&&s[i+z[i]]==s[z[i]]) z[i]++;
		if(i+z[i]-1>r){
			l=i;
			r=i+z[i]-1;
		}
	}
	for(int i=0;i<len;i++)
	  printf("%d ",z[i]);
	  return 0;
}
