#include <clocale>
#include <iostream>
#include <cstdio>
#define int long long
#define mod 998244353
inline int read();
int seq[20000005];
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

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("dmn.in","r",stdin);
	freopen("dmn.out","w",stdout);
	#endif
  n=read();
  m=read();
  if(n%2==1&&m%2==1){
    printf("0");
    return 0;
  }
  if(n>m){
    std::swap(n,m);
  }
  if(n<=5&&m<=5){
    dfs(1,1,1);
    printf("%lld",ans);
    return 0;
  }
  if(n==m){
    printf("2");
    return 0;
  }
  if(m==n+1){
    printf("3");
    return 0;
  }
  if(n==1){
    printf("1");
    return 0;
  }
  for(int i=0;i<=n;i++){
    seq[i]=(n+1)/2;
  }
  seq[n]=2;
  for(int i=n+1;i<2*n;i++){
    seq[i]=3;
  }
  for(int i=2*n;i<=n+m;i++){
    seq[i]=seq[i-n+1]+seq[i-2*n+1];
    seq[i]%=mod;
  }
  if(n%2){
    printf("%lld",seq[m]);
  }else{
    printf("%lld",seq[m]);
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


