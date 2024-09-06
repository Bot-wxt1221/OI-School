#include <iostream>
#include <cstdio>
#include <set>
#include <map>
inline int read();
int a[200005];
std::map<int,int>mp;
std::set<int>se[200005];
int xr[200005];
void add(int pos,int val){
  int tt=0;
  if(mp[val]==0){
    mp[val]=pos;
    tt=pos;
  }else{
    tt=mp[val];
  }
  std::set<int> &cur=se[tt];
  if(se.)
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int q=read();
  for(int i=1;i<=2*n;i++){
    a[i]=read();
    xr[i]=xr[i-1]^a[i];
  }
  for(int i=1;i<=q;i++){
    int p=read();
    //p p+1
    std::swap(a[p],a[p+1]);
    int mto=xr[p-1]^a[p+1];
    del(p,xr[p]);
    add(p,mto);
    xr[p]=mto;
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
