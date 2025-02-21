#include <iostream>
#include <cstdio>
#define int long long
inline int read();
inline void write(long long ans);
int fir[100005];
int nxt[200005];
int v[200005];
int to[100005][25];
int depth[100005];
int now;
int d[100005];
int x[100005][85];
int dis[100005];
int xx[100005];
int yy[100005];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
void dfs(int now,int fa){
  to[now][0]=fa;
  for(int i=1;i<=20;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  depth[now]=depth[fa]+1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    dfs(v[i],now);
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
    y=to[x][0];
  }
  return x;
}
int ans1[100005];
int ans2[100005];
signed main(){
  #ifndef ONLINE_JUDGE
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
    xx[i]=x;
    yy[i]=y;
  }
  dfs(1,1);
  for(int i=1;i<n;i++){
    d[i]=read();
    ans1[i]=getlca(i,i+1);
    ans2[i]=getlca(xx[i],yy[i]);
  }
  for(int i=2;i<=n;i++){
    x[i][0]=(((d[i-1]-x[i-1][0])%2)+2)%2;
  }
  for(int k=1;k<=60;k++){
    for(int i=2;i<=n;i++){
      x[i][k]=(((x[ans1[i-1]][k-1]*2-x[i-1][k]+d[i-1])%(1ll<<(k+1)))+(1ll<<(k+1)))%(1ll<<(k+1));
    }
  }
  for(int i=1;i<=n;i++){
    for(int k=60;k<=60;k++){
      dis[i]+=x[i][k];
    }
  }
  for(int i=1;i<n;i++){
    int ret=dis[i]+dis[i+1]-2*dis[ans1[i]];
    if(ret!=d[i]){
      printf("-1");
      return 0;
    }
  }
  for(int i=1;i<n;i++){
    int ret=dis[xx[i]]+dis[yy[i]]-2*dis[ans2[i]];
    if(ret<=0){
      printf("-1");
      return 0;
    }
  }
  for(int i=1;i<n;i++){
    int ret=dis[xx[i]]+dis[yy[i]]-2*dis[ans2[i]];
    write(ret);
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
inline void write(long long ans){
	if(ans==0){
		putchar('0');
		putchar('\n');
		return ;
	}
	static char out[65];
	long long n=0;
	while(ans){
		out[++n]=ans%10+'0';
		ans/=10;
	}
	for(int i=n;i>=1;i--){
		putchar(out[i]);
	}
	putchar('\n');
	return ;
}
