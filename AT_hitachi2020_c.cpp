#include <iostream>
#include <cstdio>
#include <queue>
inline int read();
int fir[200005];
int ans[200005];
int nxt[400005];
int v[400005];
int now;
int a[2];
std::queue<int>qu[2];
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int color[400005];
void dfs(int now,int fa){
  color[now]=!color[fa];
  a[color[now]]++;
  qu[color[now]].push(now);
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
  int n=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<n;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  dfs(1,1);
  if(a[0]>n/3&&a[1]>n/3){
    for(int i=1;i<=n;i+=3){
      ans[qu[0].front()]=i;
      qu[0].pop();
    }
    for(int i=2;i<=n;i+=3){
      ans[qu[1].front()]=i;
      qu[1].pop();
    }
    for(int i=3;i<=n;i+=3){
      if(qu[0].size()>0){
        ans[qu[0].front()]=i;
        qu[0].pop();
      }else{
        ans[qu[1].front()]=i;
        qu[1].pop();
      }
    }
  }else if(a[0]>n/3){
    int mx=0;
    for(int i=3;i<=n&&qu[1].size()>0;i+=3){
      ans[qu[1].front()]=i;
      qu[1].pop();
      mx=i;
    }
    for(int i=1;i<=n;i++){
      if(i<=mx&&i%3==0){
        continue;
      }
      if(qu[0].size()>0){
        ans[qu[0].front()]=i;
        qu[0].pop();
      }else{
        ans[qu[1].front()]=i;
        qu[1].pop();
      }
    }
  }else{
    int mx=0;
    for(int i=3;i<=n&&qu[0].size()>0;i+=3){
      ans[qu[0].front()]=i;
      qu[0].pop();
      mx=i;
    }
    for(int i=1;i<=n;i++){
      if(i<=mx&&i%3==0){
        continue;
      }
      if(qu[0].size()>0){
        ans[qu[0].front()]=i;
        qu[0].pop();
      }else{
        ans[qu[1].front()]=i;
        qu[1].pop();
      }
    }
  }
  for(int i=1;i<=n;i++){
    printf("%d ",ans[i]);
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
  注意转换染色为黑白染色考虑
Example:
	1:
		In:

		Out:
More:

*/

