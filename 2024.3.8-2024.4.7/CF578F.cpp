#include <iostream>
#include <cstdio>
#define int long long
inline int read();
char a[505][505];
int ma[505][505];
int mod;
void swap(int x,int y){
  for(int i=1;i<=504;i++){
    std::swap(ma[x][i],ma[y][i]);
  }
}
int matrix(int ma[505][505],int n){
  int ans=1,v=1;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      while(ma[i][i]){
        int x=ma[j][i]/ma[i][i];
        for(int k=i;k<=n;k++){
          ma[j][k]+=mod-((x*ma[i][k])%mod);
          ma[j][k]%=mod;
        }
        swap(i,j);
        v=-v;
      }
      swap(i,j);
      v=-v;
    }
  }
  for(int i=1;i<=n;i++){
    ans*=ma[i][i];
    ans%=mod;
  }
  return (ans*v+mod)%mod;
}
int fa[100005];
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int getto(int x,int y){
  return (x)*101+y;
}
int too[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  mod=read();
  for(int i=1;i<=n;i++){
    scanf("%s",a[i]+1);
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      fa[getto(i,j)]=getto(i,j);
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]=='\\'){
        int fax=getfa(getto(i-1,j-1));
        fa[getfa(getto(i,j))]=fax;
      }else if(a[i][j]=='/'){
        int fax=getfa(getto(i-1,j));
        fa[getfa(getto(i,j-1))]=fax;
      }
    }
  }
  int cnt=0;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(getfa(getto(i,j))==getto(i,j)&&(i+j)%2==0){
        too[getto(i,j)]=++cnt;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=cnt;i++){
    for(int j=1;j<=cnt;j++){
      ma[i][j]=0;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]=='*'){
        int u,v;
        if((i+j)%2==0){
          u=too[getfa(getto(i-1,j-1))];
          v=too[getfa(getto(i,j))];
        }else{
          u=too[getfa(getto(i,j-1))];
          v=too[getfa(getto(i-1,j))];
        }
        ma[u][v]+=mod-1;
        ma[u][v]%=mod;
        ma[v][u]+=mod-1;
        ma[v][u]%=mod;
        ma[v][v]++;
        ma[v][v]%=mod;
        ma[u][u]++;
        ma[u][u]%=mod;
      }
    }
  }
  cnt--;
  ans+=matrix(ma,cnt);
  cnt=0;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(getfa(getto(i,j))==getto(i,j)&&(i+j)%2==1){
        too[getto(i,j)]=++cnt;
      }
    }
  }
  for(int i=1;i<=cnt;i++){
    for(int j=1;j<=cnt;j++){
      ma[i][j]=0;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]=='*'){
        int u,v;
        if((i+j)%2==1){
          u=too[getfa(getto(i-1,j-1))];
          v=too[getfa(getto(i,j))];
        }else{
          u=too[getfa(getto(i,j-1))];
          v=too[getfa(getto(i-1,j))];
        }
        ma[u][v]+=mod-1;
        ma[u][v]%=mod;
        ma[v][u]+=mod-1;
        ma[v][u]%=mod;
        ma[v][v]++;
        ma[v][v]%=mod;
        ma[u][u]++;
        ma[u][u]%=mod;
      }
    }
  }
  cnt--;
  ans+=matrix(ma,cnt);
  ans%=mod;
  printf("%lld",ans);
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


