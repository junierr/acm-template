#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1e5;
struct node
{
int val,i;
bool operator<(node x)const {
	return val<x.val;
}
}sn[inf];
int tree[inf],b[inf],n;
void add(int i,int x)
{
while(i<=n){
	tree[i]+=x;
	i+=i&-i;
}
}
int query(int i)
{
int sum=0;
while(i>=1)
{	
	sum+=tree[i];
	i-=i&-i;
}
return sum;
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>sn[i].val;sn[i].i=i;
}
sort(sn+1,sn+n+1);
int cnt=1;
for(int i=1;i<=n;i++)
{	
	if(i>1&&sn[i].val>sn[i-1].val)
		cnt++;
	b[sn[i].i]=cnt;
}
int ans=0;
for(int i=1;i<=n;i++)
{
	add(b[i],1);
	ans+=i-query(b[i]);
}
cout<<ans<<endl;
return 0;
}
