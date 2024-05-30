#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define int long long
inline int read();
int query(int l,int r){
  printf("? %lld %lld\n",l,r);
  fflush(stdout);
  int tt;
  scanf("%lld",&tt);
  return tt;
}
void ans(int l){
  printf("! %lld\n",l);
  fflush(stdout);
  return ;
}
int fir[2000005];
int nxt[4000005];
int u[4000005];
int v[4000005];
int w1[4000005];
int w2[4000005];
int w3[4000005];
int now;
void add(int x,int y,int z1,int z2,int z3){
  v[++now]=y;
  u[now]=x;
  nxt[now]=fir[x];
  fir[x]=now;
  w1[now]=z1;
  w2[now]=z2;
  w3[now]=z3;
  return ;
}
std::priority_queue<std::pair<int,int> > qu;
bool vised[2000005];
int lowbit(int x){
  return x&(-x);
}
int cnt[2000005];
int mn[2000005];
int fo[2000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),l,r;
  l=read();
  r=read();
  for(int i=0;i<20;i++){
    cnt[(1<<i)]=i;
  }
  for(int i=0;i<(1<<n)+1;i++){
    fir[i]=-1;
  }
  for(int i=0;i<(1<<n);i++){
    int ti=lowbit(i);
    if(i==0){
      ti=(1<<18);
    }
    while(ti>=1){
      if((i/ti+1)*ti<=(1<<n)){
        add(i,(i/ti+1)*ti,1,cnt[ti],i/ti);
        add((i/ti+1)*ti,i,-1,cnt[ti],i/ti);
      }
      ti/=2;
    }
  }
  memset(mn,0x3f,sizeof(mn));
  mn[l]=0;
  qu.push(std::make_pair(0,l));
  while(qu.size()>0){
    auto tp=qu.top().second;
    qu.pop();
    if(vised[tp]){
      continue;
    }
    vised[tp]=1;
    for(int i=fir[tp];i!=-1;i=nxt[i]){
      if(mn[v[i]]>mn[tp]+1){
        mn[v[i]]=mn[tp]+1;
        fo[v[i]]=i;
        qu.push(std::make_pair(-mn[v[i]],v[i]));
      }
    }
  }
  r++;
  int cur=0;
  int ans=0;
  while(r!=l){
    int pre=fo[r];
    ans+=w1[pre]*query(w2[pre],w3[pre])%100;
    ans%=100;
    r=u[pre];
  }
  ::ans((ans+100)%100);
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

