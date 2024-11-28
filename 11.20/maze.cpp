#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define int long long
inline int read();
char map[2005][2005];
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
long long dis[2005][2005];
bool vised[2005][2005];
std::pair<int,int>qu[2005*2005],qu2[2005*2005];
int l1,r1,l2,r2;
inline static bool judge(char &a){
  if(a=='#'){
    return 0;
  }
  if(a=='.'){
    return 0;
  }
  if(a=='S'){
    return 0;
  }
  if(a=='T'){
    return 0;
  }
  return 1;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	#endif
  int n=read();
  int m=read();
  int k=read();
  int t=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      while(judge(map[i][j]=getchar()));
      if(map[i][j]=='S'){
        qu[r1++]=std::make_pair(i,j);
        dis[i][j]=0;
      }else{
        dis[i][j]=0x3f3f3f3f3f3f3f3f;
      }
    }
  }
  while(r1!=l1||r2!=l2){
    int i=qu[l1].first;
    int j=qu[l1].second;
    if(r1==l1||(r2!=l2&&dis[qu2[l2].first][qu2[l2].second]<dis[i][j])){
      i=qu2[l2].first;
      j=qu2[l2].second;
      l2++;
    }else{
      l1++;
    }
    if(vised[i][j]){
      continue;
    }
    if(map[i][j]=='T'){
      printf("%lld\n",dis[i][j]);
      return 0;
    }
    vised[i][j]=1;
    for(int k=0;k<4;k++){
      int tx=i+to[k][0];
      int ty=j+to[k][1];
      if(tx<=0||ty<=0||tx>n||ty>m){
        continue;
      }
      if(map[tx][ty]=='#'){
        continue;
      }
      if(dis[tx][ty]>dis[i][j]+1){
        dis[tx][ty]=std::min(dis[tx][ty],dis[i][j]+1);
        qu[r1++]={tx,ty};
      }
    }
    for(int tx=-k;tx<=k;tx++){
      int tyx=i+tx;
      if(tyx<=0||tyx>n){
        continue;
      }
      for(int ty=std::abs(tx)-k;ty<=k-std::abs(tx);ty++){
        int tyy=j+ty;
        if(tyy<=0||tyy>m){
          continue;
        }
        if(map[tyx][tyy]=='#'){
          continue;
        }
        if(dis[tyx][tyy]>dis[i][j]+t){
          dis[tyx][tyy]=dis[i][j]+t;
          qu2[r2++]={tyx,tyy};
        }
      }
    }
  }
  printf("-1");
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
