#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
inline int read();
int temp[500005];
std::set<int>se;
int bb[500005];
long long height[500005];
int rk[2][500005];
int sa[500005];
long long st[20][500005];
int tn;
std::vector<int>vec[500005],vec2[500005];
long long min(int l,int r){
  if(l==0){
    l=1;
  }
  if(r>tn){
    r=tn;
  }
  if(l>r){
    return 0;
  }
  int siz=std::log2(r-l+1);
  return std::min(st[siz][l],st[siz][r-(1<<siz)+1]);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    temp[n-i+1]=read();
    bb[n-i+1]=temp[n-i+1];
  }
  std::sort(bb+1,bb+n+1);
  int cnt=std::unique(bb+1,bb+n+1)-bb-1;
  for(int i=1;i<=n;i++){
    temp[i]=std::lower_bound(bb+1,bb+cnt+1,temp[i])-bb;
  }
  tn=n;
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
  for(long long i=1,k=0;i<=tn;i++){
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
    st[0][rk[op][i]]=k;
  }
  for(int i=1;i<20;i++){
    for(int j=1;j+(1<<i)-1<=tn;j++){
      st[i][j]=std::min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
  }
  long long sum=0;
  for(int i=tn;i>=1;i--){
    se.insert(rk[op][i]);
    auto tt=se.lower_bound(rk[op][i]);
    int pre=1;
    if(tt!=se.begin()){
      tt--;
      pre=*(tt)+1;
      tt++;
    }
    tt++;
    int lst=tn+1;
    if((tt)!=se.end()){
      lst=*(tt);
    }
    tt--;
    if(pre!=1&&lst!=tn+1){
      sum-=::min(pre,lst);
    }
    if(pre!=1){
      sum+=::min(pre,rk[op][i]);
    }
    if(lst!=tn+1){
      sum+=::min(rk[op][i]+1,lst);
    }
    printf("%lld\n",1ll*(tn-i+1)*(tn-i+2)/2-sum);
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

