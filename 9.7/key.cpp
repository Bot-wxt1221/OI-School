#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
inline int read();
bool drop=0;
class gra{
public:
  int fir[55];
  int nxt[10005];
  int v[10005];
  int siz[55];
  int in[55];
  int now=1;
  bool del[10005];
  void add(int x,int y){
    siz[x]++;
    siz[y]++;
    in[y]++;
    v[++now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
  }
  int faa[55];
  void dfs(int now,int fa){
    faa[now]=fa;
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa||del[i]){
        continue;
      }
      dfs(v[i],now);
    }
    return ;
  }
  void check(int now,int fa,int *bfa){
    bool yes=0;
    if(fa!=bfa[now]){
      yes=1;
    }
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(v[i]==fa||del[i]){
        continue;
      }
      check(v[i],now,bfa);
      if(bfa[v[i]]==now&&yes){
        drop=1;
      }
    }
  }
}a,b,c;
bool checkDAG(int n){
  std::queue<int>qu;
  for(int i=1;i<=n;i++){
    if(c.in[i]==0){
      qu.push(i);
    }
  }
  int cnt=0;
  while(qu.size()>0){
    cnt++;
    int tp=qu.front();
    qu.pop();
    for(int i=c.fir[tp];i!=-1;i=c.nxt[i]){
      c.in[c.v[i]]--;
      if(c.in[c.v[i]]==0){
        qu.push(c.v[i]);
      }
    }
  }
  return cnt==n;
}
int check(int n,int i){
  for(int j=1;j<=n;j++){
    c.fir[j]=-1;
    c.in[j]=0;
  }
  c.now=1;
  a.dfs(i,i);
  b.dfs(i,i);
  int cnt=0;
  for(int j=1;j<=n;j++){
    if(b.faa[j]==a.faa[j]){
      continue;
    }
    cnt++;
    c.add(b.faa[j],j);
    for(int k=a.fir[j];k!=-1;k=a.nxt[k]){
      if(a.v[k]==a.faa[j]||a.del[k]){
        continue;
      }
      c.add(a.v[k],j);
    }
  }
  drop=0;
  a.check(i,i,b.faa);
  if(drop){
    return 0x3f3f3f3f;
  }
  if(checkDAG(n)==0){
    return 0x3f3f3f3f;
  }else{
    return cnt;
  }
}
int preafir[10005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("key.in","r",stdin);
  freopen("key.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    memset(a.del,0,sizeof(a.del));
    for(int i=1;i<=n;i++){
      a.fir[i]=-1;
      b.fir[i]=-1;
      c.fir[i]=-1;
      a.siz[i]=0;
      b.siz[i]=0;
      c.siz[i]=0;
    }
    a.now=b.now=c.now=1;
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      a.add(x,y);
      a.add(y,x);
    }
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      b.add(x,y);
      b.add(y,x);
    }
    a.dfs(1,1);
    b.dfs(1,1);
    bool yes=1;
    for(int i=1;i<=n;i++){
      if(a.faa[i]!=b.faa[i]){
        yes=0;
      }
    }
    if(yes){
      printf("0\n");
      continue ;
    }
    int mn=0x3f3f3f3f;
    for(int u=1;u<=n;u++){
      for(int v=1;v<=n;v++){
        int del=0;
        if(a.siz[u]==2&&u!=v){
          if(v==a.v[a.fir[u]]){
            continue;
          }
          a.del[a.fir[u]]=1;
          del=a.fir[u];
          a.del[a.fir[u]^1]=1;
        }else{
          continue;
        }
        a.add(u,v);
        a.add(v,u);
        int cur=a.now;
        mn=std::min(mn,check(n,u)+1);
        a.fir[u]=a.nxt[a.fir[u]];
        a.fir[v]=a.nxt[a.fir[v]];
        a.del[cur]=1;
        a.del[cur^1]=1;
        a.siz[u]-=2;
        a.siz[v]-=2;
        a.del[del]=0;
        a.del[del^1]=0;
      }
    }
    if(mn==0x3f3f3f3f){
      mn=-1;
    }
    printf("%d\n",mn);
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
