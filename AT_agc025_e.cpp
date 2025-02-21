#include <iostream>
#include <cstdio>
#include <bitset>
inline int read();
int fir[20005];
int nxt[40005];
int v[40005];
int now;
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
namespace ng{
int fir[20005];
int nxt[40005];
int v[40005];
int in[40005];
int ans[80005];
bool vised[80005];
bool use[5005][5005];
std::bitset<5005>bi[5005];
int now=1;
void add(int x,int y,int z){
  in[x]++;
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  bi[x][y]=1;
  return ;
}
void dfs(int now){
  for(int i=bi[now]._Find_first();i<=4000;i=bi[now]._Find_first()){
    if(bi[now][i]==0){
      continue;
    }
    use[now][i]=1;
    bi[now][i]=bi[i][now]=0;
    dfs(i);
  }
  return ;
}
};
int www[2005];
void dfs(int now,int fa){
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
    www[now]+=www[v[i]];
    if(ng::in[v[i]]%2==1){
      ng::add(now,v[i],0);
      ng::add(v[i],now,0);
    }
  }
  return ;
}
int to[2005][25];
int depth[2005];
void dfs2(int now,int fa){
  to[now][0]=fa;
  depth[now]=depth[fa]+1;
  for(int i=1;i<=20;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs2(v[i],now);
  }
  return ;
}
int getlca(int x,int y){
  if(depth[x]<depth[y]){
    std::swap(x,y);
  }
  if(depth[x]>depth[y]){
    for(int i=20;i>=0;i--){
      if(depth[to[x][i]]>depth[y]){
        x=to[x][i];
      }
    }
    x=to[x][0];
  }
  if(x!=y){
    for(int i=20;i>=0;i--){
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
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
    ng::fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int a=read();
    int b=read();
    add(a,b);
    add(b,a);
  }
  dfs2(1,1);
  for(int i=1;i<=m;i++){
    int a=read();
    int b=read();
    int fa=getlca(a,b);
    www[a]++;
    www[b]++;
    www[fa]-=2;
    ng::add(a,b,i*2+1);
    ng::add(b,a,i*2);
  }
  dfs(1,1);
  int ans=0;
  for(int i=1;i<=n;i++){
    ans+=std::min(2,www[i]);
  }
  printf("%d\n",ans);
  for(int i=1;i<=n;i++){
    ng::dfs(i);
  }
  for(int i=1;i<=m;i++){
    if(ng::use[ng::v[i*2]][ng::v[i*2+1]]){
      printf("%d %d\n",ng::v[i*2],ng::v[i*2+1]);
    }else{
      printf("%d %d\n",ng::v[i*2+1],ng::v[i*2]);
    }
  }
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
