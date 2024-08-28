#include <iostream>
#include <cstdio>
#include <map>
#define int long long
inline int read();
std::map<int,int>mp;
long long ans,m;
int pw[100005];
int invpw[100005];
int fir[100005];
int nxt[200005];
int v[200005];
int w[200005];
int now;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int exgcd(int a,int b,int &x,int &y) {
  if(b==0){
    x=1;
    y=0;
    return a;
  }
  int ret=exgcd(b,a%b,y,x);
  y-=(a/b)*x;
  return ret;
}

int inv(int a,int p){
  int x1,x2;
  int ret=exgcd(a,p,x1,x2);
  if(ret!=1){
    return -1;
  }
  return (x1+p)%p;
}
int tot;
int mx[100005];
int bson;
bool vised[100005];
int siz[100005];
void calcsiz(int now,int fa){
  siz[now]=1;
  mx[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    calcsiz(v[i],now);
    siz[now]+=siz[v[i]];
    mx[now]=std::max(mx[now],siz[v[i]]);
  }
  mx[now]=std::max(mx[now],tot-siz[now]);
  if(bson==0||mx[now]<mx[bson]){
    bson=now;
  }
  return ;
}
void calcdis(int now,int fa,int dep,int cur1,int cur2){
  mp[cur1]++;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    calcdis(v[i],now,dep+1,(cur1+1ll*pw[dep]*w[i]%m)%m,(cur2*10+w[i])%m);
  }
  return ;
}
void del(int now,int fa,int dep,int cur1,int cur2){
  mp[cur1]--;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    del(v[i],now,dep+1,(cur1+1ll*pw[dep]*w[i]%m)%m,(cur2*10+w[i])%m);
  }
}
void calcdis2(int now,int fa,int dep,int cur1,int cur2){
  ans+=mp[(m-1ll*cur2*invpw[dep]%m)%m];
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    if(dep==0){
      del(v[i],now,dep+1,(cur1+1ll*pw[dep]*w[i]%m)%m,(cur2*10+w[i])%m);
    }
    calcdis2(v[i],now,dep+1,(cur1+1ll*pw[dep]*w[i]%m)%m,(cur2*10+w[i])%m);
    if(dep==0){
      calcdis(v[i],now,dep+1,(cur1+1ll*pw[dep]*w[i]%m)%m,(cur2*10+w[i])%m);
    }
  }
  return ;
}
void dfs(int now,int fa){
  vised[now]=1;
  mp.clear();
  calcdis(now,fa,0,0,0);
  calcdis2(now,fa,0,0,0);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||vised[v[i]]){
      continue;
    }
    tot=siz[v[i]];
    bson=0;
    calcsiz(v[i],now);
    calcsiz(bson,now);
    dfs(bson,now);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  m=read();
  pw[0]=1;
  pw[1]=10;
  invpw[0]=1;
  invpw[1]=inv(10,m);
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    pw[i]=1ll*pw[1]*pw[i-1]%m;
    invpw[i]=1ll*invpw[1]*invpw[i-1]%m;
  }
  for(int i=1;i<n;i++){
    int x=read()+1;
    int y=read()+1;
    int w=read();
    add(x,y,w);
    add(y,x,w);
  }
  tot=n;
  calcsiz(1,1);
  calcsiz(bson,bson);
  dfs(bson,bson);
  printf("%lld",ans-n);
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
