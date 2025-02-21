#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
inline int read();
char temp[505];
int f[505][505][2];
int ans[505];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int m=read();
  scanf("%s",temp+1);
  for(int s=1;s<=m;s++){
    memset(f,0,sizeof(f));
    f[0][s][(s==1)]=1;
    for(int i=0;i<n;i++){
      for(int j=1;j<=m;j++){
        for(int c=0;c<=1;c++){
          if(temp[i+1]!='R'){
            int nj=j-1;
            nj=std::max(nj,1);
            int nc=c|(nj==1);
            f[i+1][nj][nc]+=f[i][j][c];
            f[i+1][nj][nc]%=mod;
          }
          if(temp[i+1]!='L'){
            int nj=j+1;
            if(nj>m){
              continue;
            }
            int nc=c|(nj==1);
            f[i+1][nj][nc]+=f[i][j][c];
            f[i+1][nj][nc]%=mod;
          }
        }
      }
    }
    for(int t=1;t<s;t++){
      ans[s]+=f[n][t][0];
      ans[s]%=mod;
      ans[s]+=f[n][t][1];
      ans[s]%=mod;
    }
    ans[s]+=f[n][s][0];
    ans[s]%=mod;
    for(int t=1;t<=s;t++){
      ans[t]+=f[n][s][1];
      ans[t]%=mod;
    }
  }
  for(int i=1;i<=m;i++){
    printf("%d ",ans[i]);
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
