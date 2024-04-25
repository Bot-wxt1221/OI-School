#include <cstring>
#include <iostream>
#include <cstdio>
#include <complex>
#include <stack>
#define int __int128
inline int read();
char tt[100005];
std::stack<int>st;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("convert.in","r",stdin);
  freopen("convert.out","w",stdout);
  #endif
  scanf("%s",tt+1);
  int siz=strlen(tt+1);
  int imag=0,real=0;
  if(tt[siz]=='i'){
    siz--;
    int cur=1;
    int now=0;
    while(siz>=0&&tt[siz]>='0'&&tt[siz]<='9'){
      now+=cur*(tt[siz]-'0');
      cur*=10;
      siz--;
    }
    if(cur==1){
      now=1;
    }
    imag=now;
    if(tt[siz]=='-'){
      imag=-imag;
    }
    siz--;
  }
  int cur=1;
  int now=0;
  while(siz>=0&&tt[siz]>='0'&&tt[siz]<='9'){
    now+=cur*(tt[siz]-'0');
    cur*=10;
    siz--;
  }
  if(siz>=0&&tt[siz]=='-'){
    now=-now;
  }
  real=now;
  while(1){
    int tt=((-real)+(imag))/2;
    int tt2=(-real)-tt;
    std::complex<int>com(tt,tt2),com2(-1,1),com3(real,imag);
    if(com*com2!=com3){
      real--;
      st.push(1);
      tt=((-real)+(imag))/2;
      tt2=(-real)-tt;
    }else{
      st.push(0);
    }
    real=tt;
    imag=tt2;
    if(real==imag&&imag==0){
      break;
    }
  }
  while(st.size()>0){
    printf("%lld",(long long)st.top());
    st.pop();
  }
  return 0;
}
inline int read(){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){
    c=='-'?f=-1:1;
    c=getchar();
  }
  while(c>='0'&&c<='9'){
    x=(x<<3)+(x<<1)+(c^48);
    c=getchar();
  }
  return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/

