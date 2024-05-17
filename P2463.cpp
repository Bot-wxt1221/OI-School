#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int temp[2000005];
int rk[2][2000005];
int sa[2000005];
int height[2000005];
int beg[2000005];
int nn;
bool used[2000005];
std::vector<int>vec[2000005],vec2[2000005];
int num;
bool check(int md){
  int pre=1,cnt=0;
  for(int i=1;i<=num;i++){
    if(height[i]<md){
      if(cnt==nn){
        for(int j=1;j<=nn;j++){
          used[beg[sa[j]]]=0;
        }
        return 1;
      }
      cnt=0;
      for(int j=pre;j<i;j++){
        used[beg[sa[j]]]=0;
      }
      pre=i;
    }
    if(used[beg[sa[i]]]==0&&beg[sa[i]]!=0){
      used[beg[sa[i]]]=1;
      cnt++;
    }
  }
  for(int j=1;j<=nn;j++){
    used[beg[sa[j]]]=0;
  }
  if(cnt==nn){
    return 1;
  }
  return 0;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  nn=read();
  int cnt=0;
  int mmm=0x3f3f3f3f;
  for(int i=1;i<=nn;i++){
    int m=read();
    mmm=std::min(mmm,m);
    int mn=0x3f3f3f3f;
    int pre=cnt+1;
    for(int j=1;j<=m;j++){
      int tt=read();
      mn=std::min(mn,tt);
      temp[++cnt]=tt;
      beg[cnt]=i;
    }
    for(int j=pre;j<=cnt;j++){
      temp[j]-=mn-1;
    }
    temp[++cnt]=1e5+i;
    beg[cnt]=0;
  }
  int n=cnt;
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
  }
  num=n;
  int l=0,r=1e9;
  while(r-l>3){
    int mid=(l+r)/2;
    if(check(mid)){
      l=mid-1;
    }else{
      r=mid+1;
    }
  }
  for(int i=r;i>=l;i--){
    if(check(i)){
      printf("%d",i);
      return 0;
    }
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

