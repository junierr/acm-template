#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1000+15;
int k,s,ass;
int a[maxn][maxn],b[maxn][maxn],p[maxn];
int main()
{
    scanf("%d%d",&k,&s);
    for (int i=1;i<=k;i++)
        for (int j=1;j<=s;j++)
        {
            scanf("%d",&a[i][j]);
            b[i][j]=1;
        }
    for(int i=2;i<=k;i++) 
        for(int j=2;j<=s;j++)
            if(a[i-1][j-1]-a[i-1][j]<=a[i][j-1]-a[i][j]) b[i][j]=b[i-1][j]+1;
    for (int i=1;i<=k;i++)
        for (int j=1;j<=s;j++)
            if (b[i][j]==1) b[i][j]=0;
    p[0]=1;
    for(int i=2;i<=k;i++)
    {
        int tot=0;
        for(int j=2;j<=s;j++)
        {
            while(tot&&b[i][j]<=b[i][p[tot]]) ass=max(ass,b[i][p[tot]]*(j-p[--tot]));
            p[++tot]=j;
        }
        while(tot) ass=max(ass,b[i][p[tot]]*(s+1-p[--tot]));
    }
    printf("%d\n",ass);
    return 0;
}
