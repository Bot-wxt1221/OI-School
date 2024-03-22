#include <iostream>
#include <cstdio>
inline int read();
int x1[250005];
int y1[250005];
int x2[250005];
int y2[250005];
int lowbit(int x){
  return x&(-x);
}
int tree[250005];
int query(int x){
  int ans=0;
  while(x>0){
    ans+=tree[x];
    x-=lowbit(x);
  }
  return ans;
}
void add(int x,int y){
  while(x<=250000){
    tree[x]+=y;
    x+=lowbit(x);
  }
  return ;
}
class node{
  public:
    int to,d,x,y;
}no[1000005];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m,q;
  m=read();
  q=read();
  for(int i=1;i<=n;i++){
    x1[i]=read();
    y1[i]=read();
    x2[i]=read();
    y2[i]=read();
  }
  int now=0;
  for(int i=1;i<=m;i++){
    int vi=read();
    no[++now].x=x1[vi];
    no[++now].y=x1[vi];
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


