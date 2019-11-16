#include<bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////
struct Wint:vector<long long>{
    //用标准库vector做基类，完美解决位数问题，同时更易于实现
    //将低精度转高精度的初始化，可以自动被编译器调用
    //因此无需单独写高精度数和低精度数的运算函数，十分方便
    //默认初始化为0，但0的保存形式为空
	Wint(long long n=0){
        push_back(n);
        check();
    }
    inline Wint& check(){
	    //在各类运算中经常用到的进位小函数，不妨内置
        while(!empty()&&!back())pop_back();//去除最高位可能存在的0
        if(empty())return *this;
        for(int i=1; i<size(); ++i){//处理进位 
            (*this)[i]+=(*this)[i-1]/10;
            (*this)[i-1]%=10;
        }
        while(back()>=10){
            push_back(back()/10);
            (*this)[size()-2]%=10;
        }
        return *this;//为使用方便，将进位后的自身返回引用
    }
    
};
bool operator!=(const Wint &a,const Wint &b){
    if(a.size()!=b.size())return 1;
    for(int i=a.size()-1; i>=0; --i)
        if(a[i]!=b[i])return 1;
    return 0;
}
bool operator==(const Wint &a,const Wint &b){
    return !(a!=b);
}
bool operator<(const Wint &a,const Wint &b){
    if(a.size()!=b.size())return a.size()<b.size();
    for(int i=a.size()-1; i>=0; --i)
        if(a[i]!=b[i])return a[i]<b[i];
    return 0;
}
bool operator>(const Wint &a,const Wint &b){
    return b<a;
}
bool operator<=(const Wint &a,const Wint &b){
    return !(a>b);
}
bool operator>=(const Wint &a,const Wint &b){
    return !(a<b);
}
Wint& operator+=(Wint &a,const Wint &b){
    if(a.size()<b.size())a.resize(b.size());
    for(int i=0; i!=b.size(); ++i)a[i]+=b[i];
    return a.check();
}
Wint operator+(Wint a,const Wint &b){
    return a+=b;
}
Wint& operator-=(Wint &a,Wint b)
{
    if(a<b)swap(a,b);
    for(int i=0; i!=b.size(); a[i]-=b[i],++i)
        if(a[i]<b[i]){//需要借位
            int j=i+1;
            while(!a[j])++j;
            while(j>i){
                --a[j];
                a[--j]+=10;
            }
        }
    return a.check();
}
Wint operator-(Wint a,const Wint &b){
    return a-=b;
}
Wint operator*(const Wint &a,const Wint &b){
    Wint n;
    n.assign(a.size()+b.size()-1,0);
    for(int i=0; i!=a.size(); ++i)
        for(int j=0; j!=b.size(); ++j)
            n[i+j]+=a[i]*b[j];
    return n.check();
}
Wint& operator*=(Wint &a,const Wint &b){
    return a=a*b;
}
Wint divmod(Wint &a,const Wint &b){
    Wint ans;
    for(int t=a.size()-b.size(); a>=b; --t){
        Wint d;
        d.assign(t+1,0);
        d.back()=1;
        Wint c=b*d;
        while(a>=c){
            a-=c;
            ans+=d;
        }
    }
    return ans;
}
Wint operator/(Wint a,const Wint &b){
    return divmod(a,b);
}
Wint& operator/=(Wint &a,const Wint &b){
    return a=a/b;
}
Wint& operator%=(Wint &a,const Wint &b){
    divmod(a,b);
    return a;
}
Wint operator%(Wint a,const Wint &b){
    return a%=b;
}
//快速幂/和普通快速幂几乎无异
Wint pow(Wint &n,Wint &k,const Wint &mod){
    if(k.empty())return 1;
    Wint ans=1;
    while(!k.empty()){
    	if(k.back()%2){
    		ans=(ans*n)%mod;
		}
		k=k/2;
		n=(n*n)%mod;
	}
    return ans;
}
//输入输出
istream& operator>>(istream &is,Wint &n){
    string s;
    is>>s;
    n.clear();
    for(int i=s.size()-1; i>=0; --i)n.push_back(s[i]-'0');
    return is;
}
ostream& operator<<(ostream &os,const Wint &n){
    if(n.empty())os<<0;
    for(int i=n.size()-1; i>=0; --i)os<<n[i];
    return os;
}

int main(){
	Wint a,b;
	int c=5;
	a=c;
	cout<<a;
}

