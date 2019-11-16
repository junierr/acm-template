#include<cstdio>
#include<cstring>
using namespace std;

int a[10],b[10];
int c1[55],c2[55]; 

int main(){
	int T,n,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(int i=1;i<=k;i++){
			scanf("%d%d",&a[i],&b[i]);
		}	
		c1[0]=1;
		for(int l=1;l<=k;l++){
			for(int i=0;i<=n;i++){
				for(int j=0;i-j*a[l]>=0&&j<=b[l];j++){
				    c2[i]+=c1[i-j*a[l]];
				}  
			}
			for(int j=0;j<=n;j++){
					c1[j]=c2[j];c2[j]=0;				
				}
		}
		//for(int i=0;i<=n;i++)
		  printf("%d\n",c1[n]);
	}
	return 0;
}
