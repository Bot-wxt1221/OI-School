#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
inline int read();
int fir[1000005];
std::vector<int>ans;
std::vector<std::pair<std::pair<int,int>,int> >vec;
int nxt[2000005];
int v[2000005];
bool del[2000005];
bool yes[1000005];
int now=1;
void add(int x,int y){
  vec.push_back({{x,y},now+1});
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
bool vised[1000005];
int dep[1000005];
int to[1000005][30];
int lca;
int getdis(int x,int y){
  int tot=0;
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  for(int i=29;i>=0;i--){
    if(dep[to[x][i]]>dep[y]){
      x=to[x][i];
      tot+=(1<<i);
    }
  }
  if(dep[x]>dep[y]){
    x=to[x][0];
    tot++;
  }
  for(int i=29;i>=0;i--){
    if(to[x][i]!=to[y][i]){
      x=to[x][i];
      y=to[y][i];
      tot+=(1<<(i));
      tot+=(1<<i);
    }
  }
  if(x!=y){
    x=to[x][0];
    y=to[y][0];
    tot+=2;
  }
  lca=x;
  return tot;
}
int sum[1000005];
int fom[1000005];
int cnt;
void dfs2(int now,int fa){
  dep[now]=dep[fa]+1;
  vised[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    if(vised[v[i]]){
      if(getdis(now,v[i])%2==0){
        yes[i/2]=1;
        cnt++;
        sum[now]++;
        sum[v[i]]++;
        sum[lca]-=2;
      }else{
        sum[now]--;
        sum[v[i]]--;
        sum[lca]+=2;
      }
    }else{
      dfs2(v[i],now);
    }
  }
}
void dfs(int now,int fa){
  vised[now]=1;
  to[now][0]=fa;
  for(int i=1;i<29;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(vised[v[i]]){
      continue;
    }else{
      fom[v[i]]=i;
      dfs(v[i],now);
    }
  }
  return ;
}
void dfs3(int now,int fa){
  vised[now]=1;
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(vised[v[i]]){
      continue;
    }else{
      dfs3(v[i],now);
      sum[now]+=sum[v[i]];
    }
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
  int m=read();
  for(int i=1;i<=n;i++){
    fir[i]=-1;
  }
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    add(x,y);
    add(y,x);
  }
  std::sort(vec.begin(),vec.end());
  for(int i=0;i<vec.size();i++){
    bool &ok=del[vec[i].second/2];
    if(i!=0){
      if(vec[i-1]==vec[i]){
        ok=1;
      }
    }
    if(i!=vec.size()-1){
      if(vec[i]==vec[i+1]){
        ok=1;
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(!vised[i]){
      dfs(1,1);
    }
  }
  memset(vised,0,sizeof(vised));
  for(int i=1;i<=n;i++){
    if(!vised[i]){
      dfs2(1,1);
    }
  }
  memset(vised,0,sizeof(vised));
  if(cnt==0){
    printf("%d\n",m);
    for(int i=1;i<=n;i++){
      printf("%d ",i);
    }
    return 0;
  }
  for(int i=1;i<=m;i++){
    if(yes[i]){
      if(cnt==2&&del[i]==0){
        ans.push_back(i);
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(!vised[i]){
      dfs3(1,1);
    }
  }
  for(int i=2;i<=n;i++){
    if(sum[i]==cnt&&del[fom[i]/2]==0){
      ans.push_back(fom[i]/2);
    }
  }
  std::sort(ans.begin(),ans.end());
  printf("%d\n",int(ans.size()));
  for(int i=0;i<ans.size();i++){
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

Example:
	1:
		In:

		Out:
More:

*/
