#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cassert>
inline int read();
int map[305][305];
int dis[305];
int from[305];
int dep[305];
bool vised[305];
int to[305][25];
int pre[305];
bool vised2[305][305];
std::vector<std::pair<int,int> >vec[305];
int n;
void dij(int now){
  memset(vised2,0,sizeof(vised2));
  memset(dis,0x3f,sizeof(dis));
  memset(vised,0,sizeof(vised));
  dis[now]=0;
  for(int i=1;i<=n;i++){
    vec[i].clear();
    int mn=-1;
    for(int j=1;j<=n;j++){
      if(vised[j]){
        continue;
      }
      if(mn==-1){
        mn=j;
      }
      if(dis[j]<dis[mn]&&!vised[j]){
        mn=j;
      }
    }
    if(mn==-1){
      break;
    }
    vised[mn]=1;
    for(int j=1;j<=n;j++){
      if(map[mn][j]==-1){
        continue;
      }
      if(j==mn){
        continue;
      }
      dis[j]=std::min(dis[j],dis[mn]+map[mn][j]);
      if(dis[j]==dis[mn]+map[mn][j]){
        pre[j]=mn;
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(i!=now){
      vec[i].push_back({pre[i],dis[i]-dis[pre[i]]});
      vec[pre[i]].push_back({i,dis[i]-dis[pre[i]]});
      vised2[i][pre[i]]=vised2[pre[i]][i]=1;
    }
  }
  return ;
}
int diss[305];
int tpp[305];
void dfs(int now,int fa,int tpp){
  ::tpp[now]=tpp;
  to[now][0]=fa;
  dep[now]=dep[fa]+1;
  for(int i=1;i<=20;i++){
    to[now][i]=to[to[now][i-1]][i-1];
  }
  for(int i=0;i<vec[now].size();i++){
    if(vec[now][i].first==fa){
      continue;
    }
    diss[vec[now][i].first]=diss[now]+vec[now][i].second;
    dfs(vec[now][i].first,now,now==fa?vec[now][i].first:tpp);
  }
  return ;
}
int getlca(int x,int y){
  if(dep[x]<dep[y]){
    std::swap(x,y);
  }
  if(dep[x]>dep[y]){
    for(int i=20;i>=0;i--){
      if(dep[to[x][i]]>dep[y]){
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
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
  read();
  n=read();
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      map[i][j]=read();
      map[j][i]=map[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    dij(i);
    diss[i]=0;
    memset(tpp,0,sizeof(tpp));
    dfs(i,i,0);
    int ans=0x3f3f3f3f;
    for(int j=1;j<=n;j++){
      for(int k=1;k<=n;k++){
        if(map[j][k]==-1){
          continue;
        }
        if(vised2[j][k]){
          continue;
        }
        if(j==k){
          continue;
        }
        if(j==i||k==i){
          ans=std::min(ans,diss[j]+diss[k]+map[j][k]);
        }else{
          if(tpp[j]==tpp[k]){ 
          }else{
            ans=std::min(ans,diss[j]+diss[k]+map[j][k]);
          }
        }
      }
    }
    if(ans==0x3f3f3f3f){
      ans=-1;
    }
    printf("%d ",ans);
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
