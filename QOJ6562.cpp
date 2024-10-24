#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
inline int read();
char temp[1005][25];
int siz[1005];
int map[5][5];
int map2[5][5];
char tt[405];
std::vector<int>tmp;
std::map<std::vector<int>,int>mp[15];
int dfs(std::vector<int> tt,int cur){
  if(mp[cur][tt]){
    return mp[cur][tt]-1;
  }
  bool flag=1;
  for(int i=0;i<9;i++){
    flag&=(tt[i]==0);
  }
  if(flag){
    mp[cur][tt]=1;
    return 0;
  }
  for(int j=1;j<=3;j++){
    if(tt[(cur-1)*3+j-1]>0){
      tt[(cur-1)*3+j-1]--;
      flag|=!dfs(tt,j);
      tt[(cur-1)*3+j-1]++;
    }
  }
  mp[cur][tt]=flag+1;
  return flag;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int ans=0;
  int cnt=0;
  for(int i=1;i<=n;i++){
    scanf("%s",temp[i]+1);
    siz[i]=strlen(temp[i]+1);
    if(tt[temp[i][1]]==0){
      tt[temp[i][1]]=++cnt;
    }
    if(tt[temp[i][siz[i]]]==0){
      tt[temp[i][siz[i]]]=++cnt;
    }
    map[tt[temp[i][1]]][tt[temp[i][siz[i]]]]++;
  }
  for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
      for(int a=1;a<=3;a++){
        for(int b=1;b<=3;b++){
          map2[a][b]=map[a][b];
        }
      }
      if(map2[i][j]==0){
        continue;
      }
      map2[i][j]--;
      for(int a=1;a<=3;a++){
        map2[a][a]%=2;
      }
      for(int a=1;a<=3;a++){
        for(int b=a+1;b<=3;b++){
          int mn=std::min(map2[a][b],map2[b][a]);
          map2[a][b]-=mn;
          map2[b][a]-=mn;
        }
      }
      tmp.clear();
      for(int a=1;a<=3;a++){
        for(int b=1;b<=3;b++){
          tmp.push_back(map2[a][b]);
        }
      }
      bool flag=dfs(tmp,j);
      if(flag==0){
        ans+=map[i][j];
      }
    }
  }
  printf("%d",ans);
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
