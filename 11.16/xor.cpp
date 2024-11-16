#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
inline int read();
int x[205],y[205];
int seq[205];
std::vector<int>tt;
std::map<std::vector<int>,int>mp;
int n;
int ans=0;
int m;
void dfs(int now,int pre){
  if(now==n+1){
    tt.clear();
    for(int i=0;i<(1<<n);i++){
      int ans=0;
      for(int j=1;j<=n;j++){
        if(i&(1<<(j-1))){
          ans^=seq[j];
        }
      }
      tt.push_back(ans);
    }
    std::sort(tt.begin(),tt.end());
    auto ttt=std::unique(tt.begin(),tt.end());
    tt.resize(ttt-tt.begin());
    if(mp[tt]){
      return ;
    }
    mp[tt]=1;
    int siz=ttt-tt.begin();
    for(int i=1;i<=m;i++){
      if(siz<x[i]){
        return ;
      }
      if(tt[x[i]-1]!=y[i]){
        return ;
      }
    }
    ans++;
    return ;
  }
  for(int i=pre;i<(1<<n);i++){
    seq[now]=i;
    dfs(now+1,i);
  }
  return ;
}
signed main(){
  #ifndef ONLINE_JUDGE
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  #endif
  n=read();
  m=read();
  for(int i=1;i<=m;i++){
    x[i]=read();
    y[i]=read();
  }
  dfs(1,0);
  printf("%d",ans);
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

