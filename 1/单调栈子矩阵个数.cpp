
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int a[N][N],A[N][N];                    //A[][] ԭ���� , a[][]����������
int Stk[N],top;                         //����ջ����������
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);                //����
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&A[i][j]);
        }
    }
 
    for(int i=1;i<=n;i++){              //Ԥ����
        for(int j=1;j<=n;j++){
            if( A[i][j] ) a[i][j] = a[i-1][j] + 1;
            else          a[i][j] = 0;
        }
    }
 
    long long ans = 0,cnt =0;
    for(int i=1;i<=n;i++){
        top = cnt = 0;      //����ջ(����),ջ�����ÿһ�е�������
        for(int j=1;j<=m;j++){
            cnt += a[i][j];
            while( top && a[i][j] <= a[i][Stk[top]] ) {
                cnt -= ( Stk[top] - Stk[top-1] ) * ( a[i][Stk[top]] - a[i][j] );
                //(ջ��Ԫ��) - (�ڶ����Ԫ��)   =  ����
                //(ջ��Ԫ��) - (��ǰԪ��)  = ��ֵ
                // ���� �� ��ֵ = �������׵ĸ���
                top--;
            }
            ans += cnt;
            Stk[++top] = j;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
