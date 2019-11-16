#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

char a[100];
int f[100];
char s[100];
int lens,len; 
void setnext(){
	f[0]=-1;
	f[1]=0;
	int k=0;
	for(int i=2;i<=lens;i++){
		while(s[k]!=s[i-1]&&k)
		  k=f[k];
		if(s[k]==s[i-1]) k++;
		f[i]=k;  
	}
	return;
}

int kmp(){
	setnext();
	int i=0,j=0;
	while(i<len){
		if(j==lens-1&&s[j]==a[i]){
			return 1;
		}
		if(s[j]==a[i]){
			i++;j++;
		}
		else{
			j=f[j];
			if(j==-1){
				i++;j++;
			}
		}
	}
	return 0;
}

int main(){
	int n;
    scanf("%d",&n);
    scanf("%s",&s);
    lens=strlen(s);
    int ans=0;
    for(int i=2;i<=16;i++){
    	len=0;
    	for(int j=1;j<=n;j++){
    		int cnt=0;
    		int tmp=j;
    		int num[100];
    		while(tmp>0){
    			num[cnt++]=tmp%i;
    			tmp/=i;
			}
			for(int k=cnt-1;k>=0;k--){
				if(num[k]<10)
				  a[len++]=num[k]+'0';
				else
				  a[len++]=num[k]-10+'A';  
			}
		}
		ans=max(ans,kmp());
		if(ans>0) break;
	}
	if(ans>0) printf("yes\n");
	else printf("no\n");
	return 0;
} 
