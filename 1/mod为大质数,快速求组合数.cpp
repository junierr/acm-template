/*
快速求组合数，p为大质数 
*/

#include<iostream>
using namespace std;
int n,m,p;
long long pow(long long x,long long y)
{
    if (y==0) return 1;
    long long z=pow(x,y/2)%p;
    if (y%2==0) return z*z%p;
    return z*z%p*x%p;
}
long long ni(long long x,long long p)
{
    return pow(x,p-2);
}
long long c(int n,int m,int p)
{
    long long x=1,y=1;
    for (int i=n;i>=n-m+1;i--) x=x*i%p;
    for (int i=1;i<=m;i++) y=y*i%p;
    return x*ni(y,p)%p;
}
int main()
{
    cin>>n>>m>>p;
    cout<<c(n,m,p);
}

