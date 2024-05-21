#include <iostream>
#include <cstdio>
#include <stack>
#define int long long
inline int read();
int fir[45];
int nxt[10005];
int v[10005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
std::stack<int>st;
int nw[55];
bool yes[45];
int a[200005];
bool instack[55];
int dfn[55];
int low[55];
int cnt=0;
namespace ng{
  int fir[45];
  int num[45];
  int nxt[10005];
  int u[10005];
  int v[10005];
  int in[10005];
  int now;
  void add(int x,int y){
    v[++now]=y;
    u[now]=x;
    nxt[now]=fir[x];
    in[y]++;
    fir[x]=now;
    return ;
  }
  int calc();
};
int cntt=0;
bool used[55];
int dp[(1<<21)],dp2[(1<<21)];
int ng::calc(){
  for(int i=1;i<=cntt;i++){
    for(int j=1;j<=cntt;j++){
      if(in[j]==0&&num[j]==0){
        num[j]=i;
        for(int k=fir[j];k!=-1;k=nxt[k]){
          in[v[k]]--;
        }
        break;
      }
    }
  }
  int ans=0;
  int used=std::min(cntt/2,17ll);
  for(int i=0;i<(1ll<<(used));i++){
    dp2[i]++;
    for(int j=1;j<=now;j++){
      if(num[u[j]]>used||num[v[j]]>used){
        continue;
      }
      if((1ll<<(num[v[j]]-1))&i){
        if((1ll<<(num[u[j]]-1))&i){

        }else{
          dp2[i]--;
          goto end;
        }
      }
    }
    end:{};
  }
  for(int i=(1ll<<used)-1;i>=0;i--){
    dp[0]+=dp2[i];
    for(int j=i;j;j=(j-1)&i){
      dp[j]+=dp2[i];
    }
  }
  int nxt=used+1;
  int sheng=cntt-used;
  for(int i=0;i<(1ll<<sheng);i++){
    int ad=0;
    for(int j=1;j<=now;j++){
      if(num[v[j]]<=used){
        continue;
      }
      if((i&(1ll<<(num[v[j]]-used-1)))==0){
        continue;
      }
      if(num[u[j]]>used&&(((1ll<<(num[u[j]]-used-1))&i)==0)){
        goto end2;
      }else if(num[u[j]]<=used){
        ad|=(1ll<<(num[u[j]]-1));
      }
    }
    ans+=dp[ad];
    end2:{};
  }
  return ans;
}
void tarjan(int now){
  dfn[now]=low[now]=++cnt;
  instack[now]=1;
  st.push(now);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(dfn[v[i]]==0){
      tarjan(v[i]);
      low[now]=std::min(low[now],low[v[i]]);
    }else if(instack[v[i]]){
      low[now]=std::min(low[now],dfn[v[i]]);
    }
  }
  if(low[now]!=dfn[now]){
    return ;
  }
  cntt++;
  while(st.size()>0&&st.top()!=now){
    nw[st.top()]=cntt;
    instack[st.top()]=0;
    st.pop();
  }
  used[now]=1;
  nw[now]=cntt;
  instack[st.top()]=0;
  st.pop();
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("closure.in","r",stdin);
  freopen("closure.out","w",stdout);
  #endif
  int n=read();
  int tt=(1ll<<41)-1;
  for(int i=1;i<=n;i++){
    a[i]=read();
    tt&=a[i];
  }
  for(int i=1;i<=41;i++){
    fir[i]=-1;
    ng::fir[i]=-1;
  }
  for(int i=0;i<41;i++){
    int tt=(1ll<<41)-1;
    for(int j=1;j<=n;j++){
      if(a[j]&(1ll<<i)){
        tt&=a[j];
      }
    }
    if(tt!=((1ll<<41)-1)){
      yes[i+1]=1;
      for(int j=0;j<41;j++){
        if(tt&(1ll<<j)&&j!=i){
          add(j+1,i+1);
        }
      }
    }
  }
  for(int i=1;i<=41;i++){
    if(dfn[i]||yes[i]==0){
      continue;
    }
    tarjan(i);
  }
  for(int i=1;i<=41;i++){
    for(int j=fir[i];j!=-1;j=nxt[j]){
      if(nw[i]!=nw[v[j]]){
        ng::add(nw[i],nw[v[j]]);
      }
    }
  }
  printf("%lld",ng::calc()-(tt!=0));
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

