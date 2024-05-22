#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int siz[1000005];
namespace Union{
  int fa[1000005];
  int siz[1000005];
  int getfa(int x){
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
  }
};
int fa[1000005];
int fir[1000005];
int nxt[1000005];
int v[1000005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  ::fa[now]=fa;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),q;
  q=read();
  for(int i=1;i<=n;i++){
    siz[i]=1;
    fa[i]=0;
    fir[i]=-1;
    Union::fa[i]=i;
    Union::siz[i]=1;
  }
  int pre=0;
  for(int i=1;i<=q;i++){
    int a=read();
    int b=read();
    int c=read();
    a*=(1+pre);
    a%=998244353;
    a%=2;
    a++;
    b*=(1+pre);
    b%=998244353;
    b%=n;
    b++;
    c*=(1+pre);
    c%=998244353;
    c%=n;
    c++;
    if(a==2){
      if(fa[fa[b]]==c){
        printf("%lld\n",fa[b]);
        pre=fa[b];
      }else if(fa[fa[c]]==b){
        printf("%lld\n",fa[c]);
        pre=fa[c];
      }else if(fa[c]==fa[b]){
        printf("%lld\n",fa[c]);
        pre=fa[c];
      }else{
        printf("0\n");
        pre=0;
      }
    }else{
      int fu=Union::getfa(c);
      int fv=Union::getfa(b);
      if(Union::siz[fv]<Union::siz[fu]){
        std::swap(c,b);
        std::swap(fu,fv);
      }
      fa[fu]=fv;
      Union::fa[fu]=Union::fa[fv];
      Union::siz[fv]+=Union::siz[fu];
      dfs(c,b);
      add(c,b);
      add(b,c);
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

