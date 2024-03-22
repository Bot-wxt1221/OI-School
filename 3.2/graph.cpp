#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
int read();
int fir[100005];
int nxt[200005];
int v[200005];
int now=1;
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    long long tt=pow(x,y/2);
    return (tt*tt)%1000000007;
  }
  return (((1ll)*(x))*pow(x,y-1))%1000000007;
}
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int n;
int ans=0;
int k;
int cho[200005];
void dfs(int now,int sum){
  if(now==n+1){
    ans+=pow(sum,k);
    // printf("%d",sum);
    ans%=mod;
    return ;
  }
  dfs(now+1,sum);//no
  for(int i=fir[now];i!=-1;i=nxt[i]){
    cho[i|1]++;
    if(cho[i|1]==2){
      sum++;
    }
  }
  dfs(now+1,sum);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    cho[i|1]--;
  }
  return ;
}
int dp[100005];
signed main(){
  #ifndef ONLINE_JUDGE
  freopen("graph.in","r",stdin);
  freopen("graph.out","w",stdout);
  #endif
  n=read();
  int m=read();
  k=read();
  if(k==1){
    printf("%d",((1ll*pow(2,n-2))*m)%mod);
    return 0;
  }
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  int cnt=0;
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
    if(x==1||y==1){
      cnt++;
    }
  }
  if(n<=20){
    dfs(1,0);
    printf("%lld",::ans);
    return 0;
  }
  if(cnt==1){//lian
    dfs(1,0);
    printf("%lld",::ans);
    return 0;
  }else{//ju
    int ans=0;
    int jie=1;
    for(int i=1;i<n;i++){
      jie*=(n-i);
      jie%=mod;
      jie*=pow(i,mod-2);
      jie%=mod;
      ans+=(jie*pow(i,k))%mod;
      ans%=mod;
    }
    printf("%lld\n",ans);
  }
  return 0;
}

int read(){
  int x=0,f=1;
  char tt=getchar();
  while(tt>'9'||tt<'0'){
    (tt=='-')?f=-1:0;
    tt=getchar();
  }
  while('0'<=tt&&tt<='9'){
    x=(x*10)+(tt-'0');
    tt=getchar();
  }
  return f*x;
}
