#include <deque>
#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
std::deque<int>de;
int t[100005];
bool vised[5000005];
int p[100005];
int d[100005];
int fir[5000005];
int nxt[5000005];
int v[5000005];
int w[5000005];
int dp[5000005];
int now;
int in[5000005];
void add(int x,int y,int z){
  in[y]++;
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int n;
int mx=0;
void build(int now,int l,int r){
  if(l==r){
    mx=std::max(mx,now+n);
    add(l,now+n,0);
    return ;
  }
  int mid=(l+r)/2;
  build(now*2,l,mid);
  build(now*2+1,mid+1,r);
  add(now*2+n,now+n,0);
  add(now*2+1+n,now+n,0);
  return ;
}
int ql,qr;
int tt;
void query(int now,int l,int r){
  if(qr<l||r<ql){
    return ;
  }
  if(ql<=l&&r<=qr){
    add(now+n,tt,0);
    return ;
  }
  int mid=(l+r)/2;
  query(now*2,l,mid);
  query(now*2+1,mid+1,r);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  int s=read();
  int m=read();
  for(int i=1;i<=5000000;i++){
    fir[i]=-1;
    dp[i]=1;
  }
  build(1,1,n);
  for(int i=1;i<=s;i++){
    p[i]=read();
    d[i]=read();
    dp[p[i]]=d[i];
  }
  int cnt=mx;
  for(int i=1;i<=m;i++){
    int l=read();
    int r=read();
    int k=read();
    mx++;
    ql=l;
    qr=r;
    tt=mx;
    for(int j=1;j<=k;j++){
      add(tt,(t[j]=read()),1);
    }
    t[0]=l-1;
    t[k+1]=r+1;
    for(int j=1;j<=k+1;j++){
      tt=mx;
      ql=t[j-1]+1;
      qr=t[j]-1;
      if(ql<=qr){
        query(1,1,n);
      }
    }
  }
  for(int i=1;i<=5000000;i++){
    if(in[i]==0){
      if(dp[i]==0x3f3f3f3f){
        dp[i]=0;
      }
      de.push_back(i);
    }
  }
  while(de.size()>0){
    int tp=de.front();
    de.pop_front();
    if(vised[tp]){
      continue;
    }
    vised[tp]=1;
    for(int i=fir[tp];i!=-1;i=nxt[i]){
      if(vised[v[i]]){
        printf("NIE");
        return 0;
      }
      dp[v[i]]=std::max(dp[v[i]],dp[tp]+w[i]);
      in[v[i]]--;
      if(in[v[i]]==0){
        if(w[i]==0){
          de.push_front(v[i]);
        }else{
          de.push_back(v[i]);
        }
      }
    }
  }
  for(int i=1;i<=s;i++){
    if(dp[p[i]]!=d[i]){
      printf("NIE");
      return 0;
    }
  }
  for(int i=1;i<=n;i++){
    if(dp[i]>1e9||vised[i]==0){
      printf("NIE");
      return 0;
    }
  }
  printf("TAK\n");
  for(int i=1;i<=n;i++){
    printf("%d ",dp[i]);
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
