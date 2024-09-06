#include <cmath>
#include <iostream>
#include <cstdio>
inline int read();
int a[50005];
int seq[255][50005];
int b[50005];
int c[50005];
int fir[50005];
int nxt[100005];
int v[100005];
int siz[100005];
int bson[100005];
int dep[100005];
int to[50005][20];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  to[now][0]=fa;
  dep[now]=dep[fa]+1;
  for(int i=1;i<20;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  siz[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    siz[now]+=siz[v[i]];
    if(bson[now]==0||siz[bson[now]]<siz[v[i]]){
      bson[now]=v[i];
    }
  }
  return ;
}
int getlca(int x,int y){
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  if(dep[x]>dep[y]){
    for(int i=19;i>=0;i--){
      if(dep[to[x][i]]>dep[y]){
        x=to[x][i];
      }
    }
    x=to[x][0];
  }
  if(x!=y){
     for(int i=19;i>=0;i--){
      if(to[x][i]!=to[y][i]){
        x=to[x][i];
        y=to[y][i];
      }
    }
    x=to[x][0];
    y=to[y][0];
  }
  return x;
}
int cnt=0;
int dfn[100005];
int seq2tree[100005];
int top[100005];
void dfs2(int now,int fa,int tp){
  top[now]=tp;
  dfn[now]=++cnt;
  seq2tree[cnt]=now;
  if(bson[now]){
    dfs2(bson[now],now,tp);
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa||v[i]==bson[now]){
      continue;
    }
    dfs2(v[i],now,v[i]);
  }
  return ;
}
int jump(int x,int cur){
  for(int i=19;i>=0;i--){
    if(cur>=(1<<i)){
      cur-=(1<<i);
      x=to[x][i];
    }
  }
  return x;
}
int calcseq(int l,int r,int k){
  if(l>r){
    return 0;
  }
  l+=(r-l)%k;
  return seq[k][r]-(l-k>=0?seq[k][l-k]:0);
}
int calc(int a,int lca,int kl){
  int ans=0;
  int cur=0;
  while(a!=lca){
    if(dep[top[a]]<=dep[lca]){
      int ql=dfn[lca];
      int qr=dfn[a]-(kl-cur%kl)%kl;
      ans+=calcseq(ql,qr,kl);
      cur+=dfn[a]-dfn[lca]+1;
      return ans;
    }else{
      int ql=dfn[top[a]];
      int qr=dfn[a]-(kl-cur%kl)%kl;
      ans+=calcseq(ql,qr,kl);
      cur+=dfn[a]-dfn[top[a]]+1;
      a=to[top[a]][0];
    }
  }
  if(cur%kl==0){
    ans+=::a[lca];
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
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
  dfs2(1,1,1);
  for(int i=1;i<=n;i++){    
    b[i]=read();
  }
  int sq=std::sqrt(n);
  for(int i=1;i<=sq;i++){
    for(int j=1;j<=n;j++){
      seq[i][j]=a[seq2tree[j]];
      if(j-i>=1){
        seq[i][j]+=seq[i][j-i];
      }
    }
  }
  for(int i=2;i<=n;i++){
    int c=read();
    int lca=getlca(b[i-1],b[i]);
    int ans=0;
    if(c>sq){
      ans+=a[b[i-1]]+a[b[i]];
      int cur=b[i-1];
      int yes=0;
      if(cur==lca){
        yes++;
      }
      while(dep[cur]-dep[lca]>=c){
        if(dep[cur]-dep[lca]==c){
          yes++;
        }
        cur=jump(cur,c);
        ans+=a[cur];
      }
      cur=b[i];
      if(cur==lca){
        yes++;
      }
      while(dep[cur]-dep[lca]>=c){
        if(dep[cur]-dep[lca]==c){
          yes++;
        }
        cur=jump(cur,c);
        ans+=a[cur];
      }
      if(yes==2){
        ans-=a[lca];
      }
    }else{
      int yes=0;
      if((dep[b[i-1]]-dep[lca])%c==0){
        yes++;
      }
      if((dep[b[i]]-dep[lca])%c==0){
        yes++;
      }
      if(yes==2){
        ans-=a[lca];
      }
      ans+=calc(b[i-1],lca,c);
      ans+=calc(b[i],lca,c);
    }
    printf("%d\n",ans);
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
