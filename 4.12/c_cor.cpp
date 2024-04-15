#include <climits>
#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
inline int read();
int n,m;
class node{
  public:
    int cl,pos;
    node(int a=0,int b=0){
      cl=a;
      pos=b;
      return ;
    }
}a[2000005];
bool operator < (node a,node b){
  return a.pos<b.pos;
}
int dp[2000005];
int dp2[2000005];
int st[2000005];
int sum[2000005];
int mn[2000005];
int end[2000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  m=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    a[++cnt]=node(0,read());
  }
  for(int i=1;i<=m;i++){
    a[++cnt]=node(1,read());
  }
  int cntt=0;
  std::sort(a+1,a+cnt+1);
  for(int i=1;i<=cnt;i++){
    if(a[i].cl==a[i-1].cl&&i!=1){
    }else{
      st[++cntt]=i;
    }
  }
  int cnttt=cntt;
  for(int i=cnt;i>=1;i--){
    if(a[i].cl==a[i+1].cl&&i!=cnt){
    }else{
      end[cntt--]=i;
    }
  }
  for(int i=st[1];i<=end[1];i++){
    dp[i]=0x3f3f3f3f3f3f3f3f;
  }
  for(int i=2;i<=cnttt;i++){
    for(int j=end[i-1];j>=st[i-1]-1;j--){
      sum[j]=sum[j+1]+a[end[i-1]].pos-a[j].pos;
      dp2[j]=sum[j+1]+dp[j];
      mn[j]=dp2[j]+(a[st[i]].pos-a[end[i-1]].pos)*(end[i-1]-j);
    }
    for(int j=end[i-1]-1;j>=st[i-1]-1;j--){
      dp2[j]=std::min(dp2[j],dp2[j+1]);
    }
    for(int j=st[i-1];j<=end[i-1];j++){
      mn[j]=std::min(mn[j],mn[j-1]);
    }
    int x=a[st[i]].pos-a[end[i-1]].pos;
    int s=0;
    for(int j=st[i];j<=end[i];j++){
      s+=a[j].pos-a[st[i]].pos;
      int len=j-st[i]+1;
      dp[j]=s+(st[i-1]+len-1<=end[i-1]?std::min(x*len+dp2[end[i-1]-len+1],mn[end[i-1]-len]):dp2[st[i-1]-1]+x*len);
    }
  }
  printf("%lld\n",dp[cnt]);
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

