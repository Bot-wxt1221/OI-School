#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define int long long
#define mod 998244353
inline int read();
std::stack<int>st;
int ans[200005];
int gai[200005];
int a[200005];
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    long long tt=pow(x,y/2);
    return (tt*tt)%mod;
  }
  return (1ll*pow(x,y-1)*x)%mod;
}
std::pair<int,int>pa[200005];
std::vector<int>vec[200005];
int minn[200005];
int maxx[200005];
int sum[200005];
bool cmp(int x,int y){
  return pa[x].second<pa[y].second;
}
int tree[200005];
int bef[200005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int h=read();
  int inians=1;
  for(int i=1;i<=n;i++){
    inians=(1ll*inians*2)%mod;
    a[i]=read();
    pa[i].first=a[i];
    pa[i].second=i;
  }
  std::sort(pa+1,pa+n+1);
  int pre=1;
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(pa[i+1].first-pa[i].first>h){
      cnt++;
      minn[cnt]=pre;
      maxx[cnt]=i;
      for(int j=pre;j<=i;j++){
        vec[cnt].push_back(j);
        bef[pa[j].second]=cnt;
      }
      pre=i+1;
    }
  }
  if(pre!=n+1){
    int i=n;
    cnt++;
    minn[cnt]=pre;
    maxx[cnt]=i;
    for(int j=pre;j<=i;j++){
      vec[cnt].push_back(j);
      bef[pa[j].second]=cnt;
    }
    pre=i+1;
  }
  for(int i=1;i<=cnt;i++){
    //std::sort(vec[i].begin(),vec[i].end(),cmp);
    int rans=1;
    st=std::stack<int>();
    for(int j=vec[i].size()-1;j>=0;j--){
      while(st.size()>0&&st.top()>=pa[vec[i][j]].second){
        st.pop();
        rans*=2;
        rans%=mod;
      }
      rans*=(mod+1)/2;
      rans%=mod;
      tree[j]=rans;
      st.push(pa[vec[i][j]].second);
    }
    rans=1;
    st=std::stack<int>();
    for(int j=0;j<vec[i].size();j++){
      while(st.size()>0&&st.top()>=pa[vec[i][j]].second){
        st.pop();
        rans*=2;
        rans%=mod;
      }
      st.push(pa[vec[i][j]].second);
      ans[pa[vec[i][j]].second]=0;
      if(vec[i][j]==maxx[i]||pa[vec[i][j]+1].second<pa[vec[i][j]].second){
        ans[pa[vec[i][j]].second]+=rans*tree[j]%mod;
        ans[pa[vec[i][j]].second]%=mod;
      }
      if(vec[i][j]==minn[i]||pa[vec[i][j]-1].second<pa[vec[i][j]].second){
        ans[pa[vec[i][j]].second]+=rans*tree[j]%mod;
        ans[pa[vec[i][j]].second]%=mod;
      }
      rans*=(mod+1)/2;
      rans%=mod;
    }
  }
  int tans=1;
  int zero=cnt;
  int ttans=0;
  for(int i=1;i<=n;i++){
    int curans=inians;
    curans*=ans[i];
    curans%=mod;
    if(zero>1){
      curans=0;
    }
    if(zero==1&&sum[bef[i]]){
      curans=0;
    }
    if(sum[bef[i]]){
      tans*=pow(sum[bef[i]],mod-2);
      tans%=mod;
    }
    curans*=(tans)%mod;
    curans%=mod;
    printf("%lld ",curans);
    ttans+=curans;
    ttans%=mod;
    if(sum[bef[i]]==0&&ans[i]!=0){
      zero--;
    }
    if(sum[bef[i]]!=0&&(sum[bef[i]]+ans[i])%mod==0){
      zero++;
    }
    sum[bef[i]]+=ans[i];
    sum[bef[i]]%=mod;
    if(sum[bef[i]]!=0){
      tans*=(sum[bef[i]]);
    }
    tans%=mod;
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

