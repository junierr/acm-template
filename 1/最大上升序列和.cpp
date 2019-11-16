#include <cstdio>
using namespace std;

#define Max(x, y) (x > y ? x : y)

__int64 sum[1005];
int a[1005];

void LIS(int n)
{
    for(int i=1; i<=n; i++)
    {
        __int64 max=0;
        for(int j=1; j<i; j++)
        {
            if(a[i] > a[j])
            {
                max = Max(max, sum[j]);
            }
        }
        sum[i] = a[i] + max;
    //    printf("sum[%d]=%d+%I64d\n",i,a[i],max);
    }
}

int main()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        for(int i=1; i<=n; i++)
            scanf("%d", a+i);

        LIS(n); //求出各个上升和sum[i]

        //找出最大的和
        __int64 ans=0;
        for(int i=1; i<=n; i++)
            ans = Max(ans, sum[i]);
        printf("%I64d\n", ans);
    }
    return 0;
}
