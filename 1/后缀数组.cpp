#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int>P;
typedef pair<P,int>PI;
const int N=100010;
int n,i,j,k,t,cnt[N],rk[N],sa[N],h[N];char a[N];PI q[N],tmp[N];
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	for(i=1;i<=n;i++)rk[i]=a[i];//�õ�һλ����
	for(k=1;k<=n;k<<=1){
		for(i=1;i<=n;i++)q[i]=PI(P(rk[i],i+k<=n?rk[i+k]:0),i);//����ǰkλ�������֣����ú�kλ��������
			if(k==1)	sort(q+1,q+n+1);//��һ�ֲ��ܱ�֤a[i]��[0,n]��Χ
		else{
		//�ȶ�second���л�������
		for(i=0;i<=n;i++)cnt[i]=0;
		for(i=1;i<=n;i++)cnt[q[i].first.second]++;
		for(i=1;i<=n;i++)cnt[i]+=cnt[i-1];
		for(i=1;i<=n;i++)tmp[cnt[q[i].first.second]--]=q[i];
		//�ٶ�first���л�������
		for(i=0;i<=n;i++)cnt[i]=0;
		for(i=1;i<=n;i++)cnt[tmp[i].first.first]++;
		for(i=1;i<=n;i++)cnt[i]+=cnt[i-1];
		//�����Ա�֤first��ͬʱ��second������ں���
		for(i=n;i;i--)q[cnt[tmp[i].first.first]--]=tmp[i];
		}
		for(t=i=1;i<=n;i++){
			if(i>1&&q[i].first>q[i-1].first)t++;
			rk[q[i].second]=t;
		}
		if(t==n)break;//���к�׺�����ֳ�����
	}
	for(i=1;i<=n;i++)sa[rk[i]]=i;
	for(i=1,k=0;i<=n;i++){
		if(k)k--;//����f[i]>=f[i-1]-1
	if(rk[i]>1){
		j=sa[rk[i]-1];
		while(i+k<=n&&j+k<=n&&a[i+k]==a[j+k])k++;
	}
	h[rk[i]]=k;
	}
	for(i=1;i<=n;i++)printf("%d%c",sa[i],i<n?' ':'\n');
	for(i=2;i<=n;i++)printf("%d%c",h[i],i<n?' ':'\n');
}
