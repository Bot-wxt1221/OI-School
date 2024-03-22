#include <iostream>
#include <cstdio>
#include <bitset>
inline int read();

std::bitset<2500>a[2500];
int n,m;
int ans[2505];
void gauss()
{
	for (int i=1;i<=n*m;i++)
	{
		for (int j=i;j<=n*m;j++)
			if (a[j][i]>0)
			{
				swap(a[i],a[j]);
				break;
			}
		if (!a[i][i]) {ans[i]=1;break;}
		for (int j=i+1;j<=n*m;j++){
			if (a[j][i]) a[j]^=a[i];
    }
	}
	for (int i=n*m;i>=1;i--){
		for (int j=i+1;j<=n*m;j++){
			ans[i]^=(ans[j]*a[i][j]);
    }
  }
  return ;
}
int to[5][2]={{0,1},{0,-1},{1,0},{-1,0},{0,0}};
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  m=read();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      for(int k=0;k<5;k++){
        int ni=to[k][0]+i;
        int nj=to[k][1]+j;
        if(ni>n||nj>m||ni<=0||nj<=0){
          continue;
        }
        a[(i-1)*m+j][(ni-1)*m+nj]=1;
      }
    }
  }
  gauss();
  for(int i=1;i<=n*m;i++){
    printf("%d ",ans[i]);
    if(i%m==0){
      printf("\n");
    }
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


