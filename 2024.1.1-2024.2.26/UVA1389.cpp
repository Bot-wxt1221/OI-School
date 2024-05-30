#include <cstring>
#include <queue>
#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int s,t;
int fir[516005];
int nxt[5000005];
int v[5000005];
int now;
int in[505];
double can[5000005];
double used[5000005];
int bignum=0;
int ansc=0;
int m,n;
void add(int x,int y,int z){
  v[++now]=y;
  can[now]=z;
  used[now]=0;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
std::vector <std::pair<int,int> >vec;
namespace Dinic{
  std::queue<int>qu;
  int nfir[1000005];
  int dep[1000005];
  bool bfs(int now){
    for(int i=1;i<=t;i++){
      dep[i]=0;
    }
    dep[now]=1;
    qu.push(now);
    while(qu.size()>0){
      int tt=qu.front();
      qu.pop();
      for(int i=fir[tt];i!=-1;i=nxt[i]){
        if(dep[v[i]]||can[i]==used[i]){
          continue;
        }
        dep[v[i]]=dep[tt]+1;
        qu.push(v[i]);
      }
    }
    return dep[t];
  }
  int dfs(int now,double flow){
    if(flow==0||now==t){
      return flow;
    }
    double nflow=0;
    for(int &i=nfir[now];i!=-1;i=nxt[i]){
      if(dep[v[i]]!=dep[now]+1||can[i]==used[i]){
        continue;
      }
      double tt=dfs(v[i],std::min(flow-nflow,can[i]-used[i]));
      if(tt==0){
        continue;
      }
      nflow+=tt;
      used[i]+=tt;
      used[i^1]-=tt;
      if(nflow==flow){
        return nflow;
      }
    }
    return nflow;
  }
  double solve(){
  double ans=0;
  while(bfs(s)){
      for(int i=1;i<=t;i++){
        nfir[i]=fir[i];
      }
      ans+=dfs(s,0x3f3f3f3f);
    }
    return ans;
  }
  bool out[205];
  void ans(int now){
    out[now]=1;
    if(now!=s){
      ansc++;
    }
    for(int i=fir[now];i!=-1;i=nxt[i]){
      if(out[v[i]]||can[i]==used[i]||can[i]==0){
        continue;
      }
      ans(v[i]);
    }
    return ;
  }
};

double check(double tt){
  for(int i=1;i<=t;i++){
    fir[i]=-1;
  }
  now=1;
  for(int i=0;i<m;i++){
    add(vec[i].first,vec[i].second,1);
    add(vec[i].second,vec[i].first,1);
  }
  for(int i=1;i<=n;i++){
    add(s,i,bignum);
    add(i,s,0);
    add(i,t,bignum+2*tt-in[i]);
    add(t,i,0);
  }
  return Dinic::solve();
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  while(scanf("%d",&n)!=EOF){
    vec.clear();
    memset(in,0,sizeof(in));
    memset(Dinic::out,0,sizeof(Dinic::out));
    m=read();
    s=n+1;
    t=n+2;
    for(int i=1;i<=m;i++){
      int x=read();
      int y=read();
      in[x]++;
      in[y]++;
      vec.push_back(std::make_pair(x,y));
    }
    double l=0,r=m;
    bignum=m;
    while(r-l>1e-8){
      double mid=(l+r)/2;
      double ans=check(mid);
      if(bignum*n-ans>0){
        l=mid;
      }else{
        r=mid;
      }
    }
    check(l);
    ansc=0;
    Dinic::ans(s);
    if(ansc==0){
      printf("1\n1\n");
    }else{
      printf("%d\n",ansc);
      for(int i=1;i<=n;i++){
        if(Dinic::out[i]){
          printf("%d\n",i);
        }
      }
    }
    printf("\n");
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


