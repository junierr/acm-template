#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;


template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

template <typename T> void write(T x)
{
    if(x < 0) x = -x, putchar('-');
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}


__int128 a[105],m[105],mi;
int n;
__int128 exgcd(__int128 a,__int128 b,__int128 &x,__int128 &y) {
	if (b==0) {x=1,y=0;return a;}
	__int128 d=exgcd(b,a%b,y,x);y-=(a/b)*x;
	return d;
}
inline void excrt() {
	__int128 M=1,A=0;
	int flag=0;
	for (int i=1;i<=n;i++) {
		__int128 x,y,d=exgcd(M,m[i],x,y),mm=m[i]/d;
		if ((a[i]-A)%d) {printf("he was definitely lying\n");return;}
		x=(x%mm+mm)%mm;
		__int128 k=((a[i]-A)/d*x%mm+mm)%mm;
		__int128 nM=M*mm;
		A=((A+k*M)%nM);
		M=nM;
		if(A>mi*(LL)1e15) {
			printf("he was probably lying\n");
			flag=1;
			break;
		}
		
	}
	if(flag==0){
		if(A>mi)		
		  printf("he was probably lying\n");
		else  write(A);
	} 
	  
}
int main() {
	read(n);
	read(mi);
	for (int i=1;i<=n;i++) {
		read(m[i]);
		read(a[i]);
		
	}
	excrt();
	return 0;
}

