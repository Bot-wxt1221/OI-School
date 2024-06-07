#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
inline int read();
int x[200005],y[200005];
std::map<int,int>mp[800005];
class pos{
  public:
    int x,y;
    pos(int xx=0,int yy=0){
      x=xx;
      y=yy;
      return ;
    }
}a[200005];
bool operator < (pos a,pos b){
  return a.x==b.x?a.y<b.y:a.x<b.x;
}
int n;
int d;
int solve(){
  for(int i=1;i<=n;i++){
    a[i].x=x[i]+y[i];
    a[i].y=x[i]-y[i];
    mp[a[i].x][a[i].y]=i;
  }
  for(int i=1;i<=n;i++){
    if(mp[a[i].x].count(a[i].y)==0){
      continue;
    }
    int tt=mp[a[i].x][a[i].y+d];
    if(tt!=0&&tt!=i){
      auto tt2=mp[a[i].x+d].lower_bound(a[i].y);
      if(tt2!=mp[a[i].x+d].end()){
        while(tt2!=mp[a[i].x+d].end()&&tt2->second==0){
          tt2++;
          auto tt3=tt2;
          tt3--;
          mp[a[i].x+d].erase(tt3);
        }
        if(tt2==mp[a[i].x+d].end()){
          continue;
        }
        if(a[tt2->second].y<=a[i].y+d){
          printf("%d %d %d\n",i,tt,tt2->second);
          for(int i=1;i<=n;i++){
            mp[a[i].x].clear();
          }
          return 1;
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    mp[a[i].x].clear();
  }
  return 0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    n=read();
    d=read();
    for(int i=1;i<=n;i++){
      x[i]=read()+1e5+1;
      y[i]=read()+1e5+1;
    }
    if(solve()){
      goto end;
    }
    for(int i=1;i<=n;i++){
      x[i]=2e5+2-x[i];
    }
    if(solve()){
      goto end;
    }
    for(int i=1;i<=n;i++){
      y[i]=2e5+2-y[i];
    }
    if(solve()){
      goto end;
    }
    for(int i=1;i<=n;i++){
      x[i]=2e5+2-x[i];
    }
    if(solve()){
      goto end;
    }
    printf("0 0 0\n");
    end:{}
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

