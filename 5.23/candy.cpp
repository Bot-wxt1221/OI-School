#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[100005];
int fir[100005];
int nxt[200005];
int v[200005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int mx1[100005];
int num[100005];
int mx2[100005];
int num2[100005];
int to[100005][25];
int dis[100005][25];
int h[100005];
void dfs(int now,int fa){
  to[now][0]=fa;
  dis[now][0]=a[fa];
  h[now]=h[fa]+1;
  for(int i=1;i<25;i++){
    to[now][i]=to[to[now][i-1]][i-1];
    dis[now][i]=dis[now][i-1]+dis[to[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    if(mx1[v[i]]+a[v[i]]>=mx1[now]&&num[now]!=v[i]){
      num2[now]=num[now];
      mx2[now]=mx1[now];
      mx1[now]=mx1[v[i]]+a[v[i]];
      num[now]=v[i];
    }else if(mx1[v[i]]+a[v[i]]>=mx2[now]&&num[now]!=v[i]){
      mx2[now]=mx1[v[i]]+a[v[i]];
      num2[now]=v[i];
    }
    if(mx2[v[i]]+a[v[i]]>=mx1[now]&&num[now]!=v[i]){
      num2[now]=num[now];
      mx2[now]=mx1[now];
      mx1[now]=mx2[v[i]]+a[v[i]];
      num[now]=v[i];
    }else if(mx2[v[i]]+a[v[i]]>=mx2[now]&&num[now]!=v[i]){
      mx2[now]=mx2[v[i]]+a[v[i]];
      num2[now]=v[i];
    }
  }
  return ;
}
void dfs2(int now,int fa){
  if(now!=1){
    if(mx1[fa]+a[fa]>=mx1[now]&&num[now]!=fa&&num[fa]!=now){
      num2[now]=num[now];
      mx2[now]=mx1[now];
      mx1[now]=mx1[fa]+a[fa];
      num[now]=fa;
    }else if(mx1[fa]+a[fa]>=mx2[now]&&num[now]!=fa&&num[fa]!=now){
      mx2[now]=mx1[fa]+a[fa];
      num2[now]=fa;
    }
    if(mx2[fa]+a[fa]>=mx1[now]&&num[now]!=fa&&num2[fa]!=now){
      num2[now]=num[now];
      mx2[now]=mx1[now];
      mx1[now]=mx2[fa]+a[fa];
      num[now]=fa;
    }else if(mx2[fa]+a[fa]>=mx2[now]&&num[now]!=fa&&num2[fa]!=now){
      mx2[now]=mx2[fa]+a[fa];
      num2[now]=fa;
    }
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now);
  }
  return ;
}
int go=0;
int di=0;
int getfa(int p,int q){
  int tp=p;
  bool swap=0;
  di=a[p]+a[q];
  if(h[p]<h[q]){
    swap=1;
    std::swap(p,q);
  }
  int lst=0;
  while(h[p]>h[q]){
    int i;
    for(i=24;i>0;i--){
      if(h[to[p][i]]>h[q]){
        break;
      }
    }
    if(swap){
      lst=p;
    }
    di+=dis[p][i];
    p=to[p][i];
  }
  while(p!=q){
    int i;
    for(i=24;i>0;i--){
      if(to[p][i]!=to[q][i]){
        break;
      }
    }
    if(swap){
      lst=q;
    }else{
      lst=p;
    }
    di+=dis[p][i];
    di+=dis[q][i];
    p=to[p][i];
    q=to[q][i];
  }
  di-=a[p];
  go=lst;
  if(swap){
    if(tp!=q){
      go=to[tp][0];
    }
  }else if(tp!=p){
    go=to[tp][0];
  }
  return p;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("candy.in","r",stdin);
  freopen("candy.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  dfs2(1,1);
  for(int i=1;i<=m;i++){
    int q=read();
    int p=read();
    if(p==q){
      printf("%lld\n",mx1[p]+a[p]);
      continue;
    }
    getfa(p,q);
    if(num[p]==go){
      di+=mx2[p];
    }else{
      di+=mx1[p];
    }
    printf("%lld\n",di);
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

