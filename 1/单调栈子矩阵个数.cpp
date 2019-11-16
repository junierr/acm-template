
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int a[N][N],A[N][N];                    //A[][] 原数组 , a[][]处理后的数组
int Stk[N],top;                         //单调栈，单调递增
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);                //输入
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&A[i][j]);
        }
    }
 
    for(int i=1;i<=n;i++){              //预处理
        for(int j=1;j<=n;j++){
            if( A[i][j] ) a[i][j] = a[i-1][j] + 1;
            else          a[i][j] = 0;
        }
    }
 
    long long ans = 0,cnt =0;
    for(int i=1;i<=n;i++){
        top = cnt = 0;      //单调栈(递增),栈存的是每一行的列坐标
        for(int j=1;j<=m;j++){
            cnt += a[i][j];
            while( top && a[i][j] <= a[i][Stk[top]] ) {
                cnt -= ( Stk[top] - Stk[top-1] ) * ( a[i][Stk[top]] - a[i][j] );
                //(栈顶元素) - (第二大的元素)   =  距离
                //(栈顶元素) - (当前元素)  = 差值
                // 距离 × 差值 = 不作贡献的个数
                top--;
            }
            ans += cnt;
            Stk[++top] = j;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
