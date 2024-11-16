#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define int long long
inline int read();
int fir[80005];
int nxt[50005];
int v[50005];
int now=1;
int can[50005];
int used[50005];
int cost[50005];
void add(int x,int y,int z,int a){
  v[++now]=y;
  can[now]=z;
  used[now]=0;
  cost[now]=a;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int s,t;
bool vis[50005];
long long h[50005];
long long dis[50005];
int pre[50005];
int usedge[50005];
std::queue<int>qu;
void spfa(){
  qu=std::queue<int>();
  for(int i=1;i<=t;i++){
    vis[i]=0;
    h[i]=0x3f3f3f3f3f3f3f3f;
  }
  h[s]=0;
  vis[s]=1;
  qu.push(s);
  while(qu.size()>0){
    int tp=qu.front();
    qu.pop();
    vis[tp]=0;
    for(int i=fir[tp];i!=-1;i=nxt[i]){
      if(can[i]!=used[i]&&h[v[i]]>h[tp]+cost[i]){
        h[v[i]]=h[tp]+cost[i];
        if(vis[v[i]]==0){
          vis[v[i]]=1;
          qu.push(v[i]);
        }
      }
    }
  }
  return ;
}
std::priority_queue<std::pair<int,int> >qu2;
bool dij(){
  qu2=std::priority_queue<std::pair<int,int> >();
  for(int i=1;i<=t;i++){
    dis[i]=0x3f3f3f3f3f3f3f3f;
    vis[i]=0;
    pre[i]=0;
  }
  dis[s]=0;
  qu2.push({0,s});
  while(qu2.size()>0){
    auto temp=qu2.top();
    qu2.pop();
    if(vis[temp.second]){
      continue;
    }
    vis[temp.second]=1;
    for(int i=fir[temp.second];i!=-1;i=nxt[i]){
      long long edge=std::min(cost[i]+h[temp.second]+0ll-h[v[i]],0x3f3f3f3f3f3f3f3fll);
      if(can[i]!=used[i]&&0ll+dis[v[i]]>0ll+dis[temp.second]+edge){
        dis[v[i]]=dis[temp.second]+edge;
        usedge[v[i]]=i;
        pre[v[i]]=temp.second;
        if(vis[v[i]]==0){
          qu2.push({-dis[v[i]],v[i]});
        }
      }
    }
  }
  return dis[t]!=0x3f3f3f3f3f3f3f3f;
}
long long ans(){
  spfa();
  long long ans=0;
  while(dij()){
    for(int i=1;i<=t;i++){
      h[i]=std::min(dis[i]+0ll+h[i],0x3f3f3f3f3f3f3f3fll);
    }
    long long minf=0x3f3f3f3f3f3f3f3f;
    for(int i=t;i!=s;i=pre[i]){
      minf=std::min(minf,(long long)(can[usedge[i]]-used[usedge[i]]));
    }
    for(int i=t;i!=s;i=pre[i]){
      used[usedge[i]]+=minf;
      used[usedge[i]^1]-=minf;
    }
    ans+=minf*h[t];
  }
  return ans;
}
std::vector<int>tt[85];
int c[85];
int a[85];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  memset(fir,-1,sizeof(fir));
  s=n*4+1;
  t=n*4+2;
  for(int i=1;i<=n;i++){
    int sa=read();
    a[i]=sa;
    tt[sa].push_back(i);
    if(i!=n){
      add(i,i+1,m-1,0);
      add(i+1,i,0,0);
    }
  }
  for(int i=1;i<=n;i++){
    c[i]=read();
  }
  long long ans=0;
  for(int i=1;i<=n;i++){
    ans+=c[a[i]];
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<tt[i].size();j++){
      if(tt[i][j-1]+1<tt[i][j]){
        add(s,tt[i][j]+n,1,-0x3f3f3f3f);
        add(tt[i][j]+n,s,0,0x3f3f3f3f);

        add(tt[i][j]+n,tt[i][j-1]+1,1,-c[i]);
        add(tt[i][j-1]+1,tt[i][j]+n,0,c[i]);

        add(tt[i][j],tt[i][j]+n+n,1,0);
        add(tt[i][j]+n+n,tt[i][j],0,0);

        add(tt[i][j]+n,tt[i][j]+n+n,1,0);
        add(tt[i][j]+n+n,tt[i][j]+n,0,0);

        add(tt[i][j]+n+n,t,1,-0x3f3f3f3f);
        add(t,tt[i][j]+n+n,0,0x3f3f3f3f);
        ans+=0x3f3f3f3f*2;
      }else{
        ans-=c[i];
      }
    }
  }
  printf("%lld",ans+::ans());
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
};
