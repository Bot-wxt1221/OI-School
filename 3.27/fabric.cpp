#include <iostream>
#include <cstdio>
#include <stack>
inline int read();
int map[2005][2005];
int up[2005][2005];
long long ans[2005][2005];
long long ans2[2005][2005];
int lft[2005],rit[2005];
std::stack<int>st;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("fabric.in","r",stdin);
  freopen("fabric.out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  int k=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      map[i][j]=!(read());
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(map[i][j]){
        up[i][j]=up[i-1][j]+1;
      }else{
        up[i][j]=0;
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(i>=k){
      ans2[i][1]=(i-k+1);
    }else{
      ans2[i][1]=0;
    }
    for(int j=2;j<=m+1;j++){
      int tt=((k/j)+((k%j)>0));
      ans2[i][j]=ans2[i][j-1];
      if(i>=tt){
        ans2[i][j]+=(i-tt+1);
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      ans[i][j]=ans2[i][j]+ans[i][j-1];
    }
  }
  long long tans=0;
  for(int i=1;i<=n;i++){
    st=std::stack<int>();
    for(int j=1;j<=m;j++){
      while(st.size()>0&&up[i][st.top()]>up[i][j]){
        int tt=st.top();
        lft[tt]=j-1;
        st.pop();
      }
      st.push(j);
    }
    while(st.size()>0){
      int tt=st.top();
      lft[tt]=m;
      st.pop();
    }
    for(int j=m;j>=1;j--){
      while(st.size()>0&&up[i][st.top()]>=up[i][j]){
        int tt=st.top();
        rit[tt]=std::min(j+1,m);
        st.pop();
      }
      st.push(j);
    }
    while(st.size()>0){
      int tt=st.top();
      rit[tt]=1;
      st.pop();
    }
    for(int j=1;j<=m;j++){
      if(up[i][j]==up[i][j-1]||up[i][j]==0){
        continue;
      }
      int hi=up[i][j];
      int has=0;
      if(lft[j]+1<=m){
        has=std::max(has,up[i][lft[j]+1]);
      }
      if(rit[j]-1>0){
        has=std::max(has,up[i][rit[j]-1]);
      }
      tans+=ans[hi][lft[j]-rit[j]+1]-ans[has][lft[j]-rit[j]+1];
    }
  }
  printf("%lld",tans);
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

