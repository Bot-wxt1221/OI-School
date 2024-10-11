#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
inline int read();
bool vised[1000005];
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
std::vector<int>vec[1000005];
std::vector<int>vec2[1000005];
std::vector<std::pair<int,std::pair<int,int> >> tt;
int fa[1000005];
int sum[1000005];
bool yes[1000005];
int getfa(int x){
  if(fa[x]==x){
    return x;
  }
  int tfa=fa[x];
  int tf=getfa(fa[x]);
  yes[x]&=yes[tfa];
  fa[x]=tf;
  return tf;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    vec[i].resize(m+5);
    vec2[i].resize(m+5);
    for(int j=1;j<=m;j++){
      vec[i][j]=read();
      vec2[i][j]=++cnt;
      fa[cnt]=cnt;
      yes[cnt]=1;
      tt.push_back({vec[i][j],{i,j}});
      sum[cnt]=vec[i][j];
    }
  }
  std::sort(tt.begin(),tt.end());
  for(int i=0;i<n*m;i++){
    vised[vec2[tt[i].second.first][tt[i].second.second]]=1;
    for(int k=0;k<4;k++){
      int fx=tt[i].second.first+to[k][0];
      int fy=tt[i].second.second+to[k][1];
      if(fx<=0||fx>n||fy<=0||fy>m||!vised[vec2[fx][fy]]){
        continue;
      }
      int tfa=getfa(vec2[fx][fy]);
      if(tfa==vec2[tt[i].second.first][tt[i].second.second]){
        continue;
      }
      fa[tfa]=vec2[tt[i].second.first][tt[i].second.second];
      if(sum[tfa]>=tt[i].first){
        yes[tfa]=1;
      }else{
        yes[tfa]=0;
      }
      sum[vec2[tt[i].second.first][tt[i].second.second]]+=sum[tfa];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      getfa(vec2[i][j]);
      printf("%d ",yes[vec2[i][j]]);
    }
    printf("\n");
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
