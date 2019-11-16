#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long lcm,a[100],b[100];
bool flag;

long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}

long long e_gcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	long long ans=e_gcd(b,a%b,y,x);
	y-=a/b*x;
	return ans;
}



long long china(long long m){
	long long a1=a[0],b1=b[0];
	long long a2,b2,k1,k2,c,g,x0;
	lcm=a[0];
	for(int i=1;i<m;i++){
		a2=a[i];
		b2=b[i];
		c=b2-b1;
		g=e_gcd(a1,a2,k1,k2);
		lcm=lcm*a[i]/gcd(lcm,a[i]);
		if(c%g){
			flag=false;
			return 0;
		} 
		//Çó³Ë·¨ÄæÔª£º 
		x0=k1*c/g;
	    long long t=a2/g;
	    x0=(x0%t+t)%t;
	    b1+=a1*x0;
	    a1=a2/g*a1;
	}
	return b1;
}


int main(){
		long long n,m;
		scanf("%lld%lld",&n,&m);
		for(int i=0;i<n;i++)
		  scanf("%lld",&a[i]);
		for(int i=0;i<n;i++)
		  scanf("%lld",&b[i]);
		flag=true;
		long long ans=china(n);    
		if(!flag){
			printf("he was definitely lying\n");
		}
		else if(ans<=0){
			ans+=lcm;
			ans=(m-ans)/lcm+1;
			if(ans>m)
			  printf("he was probably lying\n");
			else 
			  printf("%lld\n",ans);  
		}
		else printf("%lld\n",ans);
	return 0;
} 
