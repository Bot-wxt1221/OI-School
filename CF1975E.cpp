#include <iostream>
#include <cstdio>
inline int read();
int fir[200005];
int c[200005];
int nxt[400005];
int v[400005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int fa[200005];
int cnt[200005];
int cc[200005];
int zero=0,one=0,two=0,three=0;
int faw,fa2;
void dfs(int now,int fa){
  ::fa[now]=fa;
  if(cc[now]==1&&cc[fa]==0){
    fa2++;
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
  }
  return ;
}
int xor_two=0;
void upd(int cr,int tt){
  int cur=cnt[cr];
  if(cur==0){
    zero+=tt;
    return ;
  }
  if(cur==1){
    one+=tt;
    return ;
  }
  if(cur==2){
    xor_two^=cr;
    two+=tt;
    return ;
  }
  three+=tt;
  return ;
}
int cntt=0;
void black(int now){
  cntt++;
  c[now]^=1;
  if(now!=1){
    if(c[fa[now]]==1){
      upd(fa[now],-1);
      cnt[fa[now]]++;
      upd(fa[now],1);
    }else{
      cnt[fa[now]]++;
    }
  }
  if(c[fa[now]]==0){
    faw++;
  }
  upd(now,1);
  faw-=cnt[now];
  return  ;
}
void white(int now){
  cntt--;
  c[now]^=1;
  if(now!=1){
    if(c[fa[now]]==1){
      upd(fa[now],-1);
      cnt[fa[now]]--;
      upd(fa[now],1);
    }else{
      cnt[fa[now]]--;
    }
  }
  if(c[fa[now]]==0){
    faw--;
  }
  upd(now,-1);
  faw+=cnt[now];
  return  ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read(),q;
    q=read();
    fa2=0;
    for(int i=1;i<=n;i++){
      fir[i]=-1;
      cc[i]=read();
      cnt[i]=0;
      c[i]=0;
    }
    xor_two=0;
    now=0;
    one=zero=two=three=0;
    faw=0;
    cntt=0;
    for(int i=1;i<n;i++){
      int x=read();
      int y=read();
      add(x,y);
      add(y,x);
    }
    dfs(1,0);
    zero=n;
    for(int i=1;i<=n;i++){
      if(cc[i]){
        black(i);
      }
    }
    faw=fa2;
    for(int i=1;i<=q;i++){
      int tt=read();
      if(c[tt]){
        white(tt);
      }else{
        black(tt);
      }
      if(cntt==0){
        printf("No\n");
        goto end;
      }
      if(three){
        printf("No\n");
        goto end;
      }
      if(faw>=2){
        printf("No\n");
        goto end;
      }
      if(two>=2||(xor_two!=1&&c[fa[xor_two]]==1)){
        printf("No\n");
        goto end;
      }
      printf("Yes\n");
      end:{};
    }
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

