#include <iostream>
#include <cstdio>
#include <queue>
#include <bitset>
#define int unsigned int
inline int read();
std::priority_queue<int>a,b;
//int siz=0;
//inline int size(){
//  return siz;
//}
inline void erase(int x){
//  siz--;
  b.push(-x);
}
inline void push(int x){
//  siz++;
  a.push(-x);
}
inline void upd(){
  while(b.size()>0&&a.size()>0&&a.top()==b.top()){
    a.pop();
    b.pop();
  }
  return ;
}
inline int top(){
  upd();
  return -a.top();
}
inline void pop(){
//  siz--;
  upd();
  a.pop();
  return ;
}
std::bitset<10000005> seq;
int ss[10000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("min.in","r",stdin);
  freopen("min.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  register int x0=read();
  register int x1=read();
  int a=read();
  int b=read();
  int c=read();
  register int rans=0;
  register int ii=10099;
  for(int i=1;i<=m;i++){
    int nx1=(a*x0+b*x1+c);
    int nx2=(a*x1+b*nx1+c);
    int ta1=(x1/4)%n;
    int ta2=(nx1/4);
    if(seq[ta1]==0||ta2<seq[ta1]){ 
      seq[ta1]=1;
      ss[ta1]=ta2;
      push(ta2);
    }else{
      erase(ss[ta1]);
      ss[ta1]=ta2;
      push(ta2);
    }
    rans+=(ii)*top();
    ii*=10099;
    x0=nx1;
    x1=nx2;
  }
  printf("%u",rans);
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


