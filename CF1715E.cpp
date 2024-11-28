#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int w[200005];
bool vised[200005][25];
bool inque[200005][25];
int dp[200005][25];
int now;
class node{
public:
  int ans;
  int cur,k;
  node(int a,int b,int c){
    ans=a;
    cur=b;
    k=c;
    return ;
  }
  node(){
    ans=cur=k=0;
    return ;
  }
};
bool operator < (node a,node b){
  return a.ans>b.ans;
}
std::priority_queue<node>qu;
void add(int x,int y,int z){
  v[++now]=y;
  w[now]=z;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int n;
void spread(int k){
  qu=std::priority_queue<node>();
  for(int i=1;i<=n;i++){
    qu.push(node(dp[i][k],i,k));
  }
  while(qu.size()>0){
    auto tp=qu.top();
    qu.pop();
    if(vised[tp.cur][tp.k]){
      continue;
    }
    for(int i=fir[tp.cur];i!=-1;i=nxt[i]){
      if(dp[v[i]][k]>dp[tp.cur][tp.k]+w[i]){
        dp[v[i]][k]=dp[tp.cur][tp.k]+w[i];
        qu.push(node(dp[v[i]][k],v[i],k));
      }
    }
  }
  return ;
}
int K(int x){
  return -2*x;
}
int B(int x,int k){
  return x*x+dp[x][k];
}
bool comp(int l,int r,int l1,int r1,int k){
  return (B(r1,k)-B(l1,k))*(K(l)-K(r))>(B(r,k)-B(l,k))*(K(l1)-K(r1));
}
void spread(int x,int y){
  std::deque<int>qu;
  int pre=1;
  for(int i=1;i<=n;i++){
    while(qu.size()>=2&&comp(qu.back(),i,qu[qu.size()-2],qu.back(),x)){
      qu.pop_back();
    }
    if(qu.size()){
      dp[i][y]=K(qu.back())*i+B(qu.back(),x)+i*i;
    }
    dp[i][y]=std::min(dp[i][y],dp[i][x]);
    qu.push_back(i);
  }
  //left
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  n=read();
  int m=read();
  int k=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    int w=read();
    add(x,y,w);
    add(y,x,w);
  }
  memset(dp,0x3f,sizeof(dp));
  dp[1][0]=0;
  for(int i=0;i<k;i++){
    spread(i);
    spread(i,i+1);
  }
  spread(k);
  for(int i=1;i<=n;i++){
    printf("%d ",dp[i][k]);
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
