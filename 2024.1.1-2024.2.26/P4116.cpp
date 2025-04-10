#include <iostream>
#include <cstdio>
inline int read();
int stk[100005];
int tp;
int tree[100005];
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
int siz[100005];
int bigson[100005];
void dfs1(int now,int fa){
  siz[now]=1;
  bigson[now]=0;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs1(v[i],now);
    siz[now]+=siz[v[i]];
    if(bigson[now]==0||siz[v[i]]>siz[bigson[now]]){
      bigson[now]=v[i];
    }
  }
  return ;
}
int dfn[100005];
int cnt;
int top[100005];
int tot[100005];
int faa[100005];
void dfs2(int now,int fa,int tp){
  faa[now]=fa;
  top[now]=tp;
  dfn[now]=++cnt;
  tot[cnt]=now;
  if(!bigson[now]){
    return ;
  }
  dfs2(bigson[now],now,tp);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==bigson[now]||v[i]==fa){
      continue;
    }
    dfs2(v[i],now,v[i]);
  }
  return ;
}
namespace BIT{
int tree[100005];
int lowbit(int x){
  return x&(-x);
}
int query(int now){
  int ans=0;
  while(now>0){
    ans+=tree[now];
    now-=lowbit(now);
  }
  return ans;
}
void mod(int x,int y){
  while(x<=100000){
    tree[x]+=y;
    x+=lowbit(x);
  }
  return ;
}
}
int r[100005];
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int q=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  BIT::mod(1,1);
  r[1]=1;
  dfs1(1,1);
  dfs2(1,1,1);
  for(int ii=1;ii<=q;ii++){
    char tt;
    std::cin>>tt;
    int i=read();
    if(tt=='C'){
      BIT::mod(dfn[i],r[dfn[i]]==0?1:0);
      r[dfn[i]]==0?r[dfn[i]]=1:r[dfn[i]]=1;
    }else{
      tp=0;
      while(!(i==1)){
        stk[++tp]=dfn[i];
        i=top[i];
        stk[++tp]=dfn[i];
        i=faa[i];
      }
      stk[++tp]=1;
      stk[++tp]=1;
      int now=1;
      while(now-1!=tp){
        int tl=stk[now];
        int l=stk[now+1];
        int r=stk[now];
        while(r-l>3){
          int mid=(l+r)/2;
          if(BIT::query(tl)-BIT::query(mid-1)!=0){
            l=mid-1;
          }else{
            r=mid+1;
          }
        }
        for(int iii=r;iii>=l;iii--){
          if(BIT::query(tl)-BIT::query(iii-1)!=0){
            printf("%d\n",tot[iii]);
            goto end;
          }
        }
        now+=2;
      }
      printf("-1\n");
      end:{}
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


