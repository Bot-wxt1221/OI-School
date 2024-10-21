#include <iostream>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#define ET return 0
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define ll long long
#define ull unsigned long long
#define inf INT_MAX
#define uinf INT_MIN
#define pii pair<int,int>
#define pll pair<ll,ll>
#define debug puts("--------Chery AK IOI--------");
#define Yes cout<<"Yes"<<endl;
#define No cout<<"No"<<endl;
#define pt puts("")
#define fr1(i,a,b) for(int i=a;i<=b;i++)
#define fr2(i,a,b) for(int i=a;i>=b;i--)
#define fv(i,p) for(int i=0;i<p.size();i++)
#define ld long double
#define il inline
#define ptc putchar
using namespace std;
const int N=1e3+10;
int _tc;
int _n,_m,_lim;
int _Mat[N][N];
int _Col[N][N];
bool _ok;
int _c;
int truth(int n,int m,int lim);
int simons(int _h,int _w,int _px1,int _py1,int _px2,int _py2){
    if(!_ok) return -1;
    _c++;
    if(_h<=0||_w<=0){
        _ok=0;
        return -1;
    }
    if(_c>_lim){
        _ok=0;
        return -1;
    }
    if(_px1<1||_px1+_h-1>_n||_py1<1||_py1+_w-1>_m||_px2<1||_px2+_h-1>_n||_py2<1||_py2+_w-1>_m){
        _ok=0;
        return -1;
    }
    bool _ans=1;
    fr1(_i,1,_h){
        fr1(_j,1,_w){
            if(_Col[_px1+_i-1][_py1+_j-1]==_c){
                _ok=0;
                return -1;
            }
            _Col[_px1+_i-1][_py1+_j-1]=_c;
            if(_Col[_px2+_i-1][_py2+_j-1]==_c){
                _ok=0;
                return -1;
            }
            _Col[_px2+_i-1][_py2+_j-1]=_c;
            _ans&=(_Mat[_px1+_i-1][_py1+_j-1]==_Mat[_px2+_i-1][_py2+_j-1]);
        }
    }
    return _ans;
}
// #define Shun debut
int main(){
#ifdef Shun
    freopen("fake.in","r",stdin);
    freopen("fake.out","w",stdout);
#endif
    assert(1==scanf("%d",&_tc));
  puts("2104834354373823");
    while(_tc--){
        assert(3==scanf("%d%d%d",&_n,&_m,&_lim));
        assert(_n>=1&&_n<=1000&&_m>=1&&_m<=1000);
        fr1(_i,1,_n){
            fr1(_j,1,_m){
                _Col[_i][_j]=0;
                assert(1==scanf("%d",&_Mat[_i][_j]));
                assert(_Mat[_i][_j]>=1&&_Mat[_i][_j]<=_n*_m);
            }
        }
        _ok=1;
        _c=0;
        int __ans=truth(_n,_m,_lim);
        if(!_ok) printf("-1\n");
        else printf("%d\n",__ans);
    }
    ET;
}
//ALL FOR Zhang Junhao.
#define int long long
inline int read();
int query(int a,int b,int c,int d,int e,int f){
  return simons(a,b,c,d,e,f);
}
int nn,mm;
int nnn,mmm;
int checkn(int tt){
  if(tt==2){
    return query(nn/2,mmm,1,1,nn/2+1,1);
  }
  int ln=nn/tt;
  int md=tt/2;
  return query(md*ln,mmm,1,1,md*ln+1,1)&&query(md*ln,mmm,1,1,(md+1)*ln+1,1);
}
int checkm(int tt){
  if(tt==2){
    return query(nnn,mm/2,1,1,1,mm/2+1);
  }
  int ln=mm/tt;
  int md=tt/2;
  return query(nnn,md*ln,1,1,1,md*ln+1)&&query(nnn,md*ln,1,1,1,(md+1)*ln+1);
}
std::vector<int>tt,tt2;
std::vector<int>tt3,tt4;
signed truth(signed n,signed m,signed limm){
  nn=n;
  mm=m;
  nnn=n;
  mmm=m;
  tt.clear();
  tt2.clear();
  tt3.clear();
  tt4.clear();
  for(int i=2;i<=n;i++){
    while(n%i==0){
      n/=i;
      tt.push_back(i);
    }
  }
  for(int i=2;i<=m;i++){
    while(m%i==0){
      m/=i;
      tt2.push_back(i);
    }
  }
  for(int i=0;i<tt.size();i++){
    if(checkn(tt[i])){
      nn/=tt[i];
      tt3.push_back(tt[i]);
    }
  }
  for(int i=0;i<tt2.size();i++){
    if(checkm(tt2[i])){
      mm/=tt2[i];
      tt4.push_back(tt2[i]);
    }
  }
  int ans=1;
  int tt1=2;
  for(int i=1;i<tt3.size();i++){
    if(tt3[i]==tt3[i-1]){
      tt1++;
    }else{
      ans*=tt1;
      tt1=2;
    }
  }
  if(tt3.size()>=1){
    ans*=tt1;
  }
  tt1=2;
  for(int i=1;i<tt4.size();i++){
    if(tt4[i]==tt4[i-1]){
      tt1++;
    }else{
      ans*=tt1;
      tt1=2;
    }
  }
  if(tt4.size()==0){
    tt1=1;
  }
  return ans*tt1;
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
