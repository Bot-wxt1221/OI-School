#include <cinttypes>
#include <iostream>
#include <cstdio>
inline int read();
int n,m;
int mp[25][25];
int ans=0;
void dfs(int now,int lsti,int lstj){
 int i=lsti;
  int j=lstj;
  if(mp[i][j]!=mp[i+1][j]&&mp[i][j]!=mp[i][j+1]&&mp[i][j]!=mp[i+1][j+1]&&mp[i+1][j]!=mp[i][j+1]&&mp[i+1][j]!=mp[i+1][j+1]&&mp[i][j+1]!=mp[i+1][j+1]&&(mp[i+1][j]!=0&&mp[i][j+1]!=0&&mp[i+1][j+1]!=0)){
          return ;
        }else{
        }
  i++;
  if(mp[i][j]!=mp[i+1][j]&&mp[i][j]!=mp[i][j+1]&&mp[i][j]!=mp[i+1][j+1]&&mp[i+1][j]!=mp[i][j+1]&&mp[i+1][j]!=mp[i+1][j+1]&&mp[i][j+1]!=mp[i+1][j+1]&&(mp[i+1][j]!=0&&mp[i][j+1]!=0&&mp[i+1][j+1]!=0)){
          return ;
        }else{
       }
  i--;
  j++;

  if(mp[i][j]!=mp[i+1][j]&&mp[i][j]!=mp[i][j+1]&&mp[i][j]!=mp[i+1][j+1]&&mp[i+1][j]!=mp[i][j+1]&&mp[i+1][j]!=mp[i+1][j+1]&&mp[i][j+1]!=mp[i+1][j+1]&&(mp[i+1][j]!=0&&mp[i][j+1]!=0&&mp[i+1][j+1]!=0)){
          return ;
        }else{
        }
  if(now-1==(n*m)/2){
    for(int i=1;i<n;i++){
      for(int j=1;j<m;j++){
        if(mp[i][j]!=mp[i+1][j]&&mp[i][j]!=mp[i][j+1]&&mp[i][j]!=mp[i+1][j+1]&&mp[i+1][j]!=mp[i][j+1]&&mp[i+1][j]!=mp[i+1][j+1]&&mp[i][j+1]!=mp[i+1][j+1]){
          return ;
        }else{
        }
      }
    }
    ans++;
    return ;
  }
  for(int i=lsti;i<=n;i++){
    for(int j=((i==lsti)?lstj:1);j<=m;j++){
      if(mp[i][j]||mp[i][j+1]||j+1>m){
      }else{
        mp[i][j]=now;
        mp[i][j+1]=now;
        dfs(now+1,i,j);
        mp[i][j]=mp[i][j+1]=0;
      }
      if(mp[i][j]||mp[i+1][j]||i+1>n){
      }else{
        mp[i][j]=now;
        mp[i+1][j]=now;
        dfs(now+1,i,j);
        mp[i][j]=mp[i+1][j]=0;
      }
    }
  }
  return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("dwn.in","r",stdin);
	freopen("dwn.out","w",stdout);
	#endif
  n=read();
  m=read();
  if(n%2!=0&&m%2!=0){
    printf("0");
    return 0;
  }
  dfs(1,1,1);
  printf("%d",ans);
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


