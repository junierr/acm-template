#include<iostream>
#include<cstring>
#include<algorithm> 
#define maxn 55
using namespace std;
int A[maxn][maxn],V[maxn];
int cn,bestn;  //当前节点数，最大节点数
int n;
int check(int x){
    for (int i=1;i<x;i++){
        if (V[i] && !A[x][i]) return 0;
    }
    return 1;
}
void dfs(int x){
    if (x>n){  //此处记录最大团 
        bestn=max(cn,bestn);
        return ;
    }
    if (check(x)){
        cn++;
        V[x]=1;
        dfs(x+1);
        cn--;
    }
    if (cn+n-x>bestn){
        dfs(x+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while (cin >> n && n){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++) cin >> A[i][j];
        }
        cn=bestn=0;
        memset(V,0,sizeof(V));
        dfs(1);
        cout << bestn << endl;
    }
    return 0;
}
