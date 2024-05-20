#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
inline int read();
char temp[1000005];
int rk[2][2000005];
int sa[2000005];
int height[2000005];
int beg[2000005];
int nn;
bool used[2000005];
std::vector<int>vec[2000005],vec2[2000005];
std::pair<int,int> pa[1000005];
int fa[1000005];
int siz[1000005];
int getfa(int x){
  return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  scanf("%s",temp+1);
  int n=strlen(temp+1);
  int tn=n;
  int tt=1;
  while(tt<=n){
    tt*=2;
  }
  n=tt;
  int op=0;
  for(int i=1;i<=n;i++){
    rk[op][i]=temp[i];
  }
  for(int i=2;i<=n;(i=(i<<1))){
    op^=1;
    int mx=0;
    for(int j=1;j<=n;j++){
      vec[rk[op^1][j+i/2]].push_back(j);
      mx=std::max(mx,rk[op^1][j+i/2]);
    }
    int mx2=0;
    for(int j=0;j<=mx;j++){
      for(int k=0;k<vec[j].size();k++){
        vec2[rk[op^1][vec[j][k]]].push_back(vec[j][k]);
        mx2=std::max(mx2,rk[op^1][vec[j][k]]);
      }
    }
    int cnt=0;
    for(int j=0;j<=mx2;j++){
      vec[j].clear();
      for(int k=0;k<vec2[j].size();k++){
        cnt++;
        rk[op][vec2[j][k]]=cnt;
        if(k!=0&&rk[op^1][vec2[j][k]+i/2]==rk[op^1][vec2[j][k-1]+i/2]){
          rk[op][vec2[j][k]]=rk[op][vec2[j][k-1]];
        }
      }
      vec2[j].clear();
    }
  }
  for(int i=1;i<=n;i++){
    rk[op][i]-=n-tn;
  }
  for(int i=1;i<=n;i++){
    if(rk[op][i]>=0){
      sa[rk[op][i]]=i;
    }
  }
  for(int i=1,k=0;i<=tn;i++){
    if(rk[op][i]==0){
      continue;
    }
    if(k){
      k--;
    }
    while(temp[i+k]==temp[sa[rk[op][i]-1]+k]){
      k++;
    }
    height[rk[op][i]]=k;
    pa[i]=std::make_pair(k,rk[op][i]);
  }
  std::sort(pa+1,pa+tn+1);
  for(int i=1;i<=tn;i++){
    fa[i]=i;
    siz[i]=1;
  }
  int ans=0;
  for(int i=tn;i>=1;i--){
    if(pa[i].second==1){
      continue;
    }
    int fa1=getfa(pa[i].second-1);
    int fa2=getfa(pa[i].second);
    siz[fa1]+=siz[fa2];
    fa[fa2]=fa1;
    ans=std::max(ans,pa[i].first*siz[fa1]);
  }
  printf("%d",ans);
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

