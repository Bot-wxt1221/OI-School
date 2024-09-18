#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#define int long long
class matrix{
public:
  int map[5][5];
  matrix(){
    memset(map,0,sizeof(map));
  }
};
matrix operator * (matrix &a,matrix &b){
  matrix ans;
  for(int i=1;i<=4;i++){
    for(int j=1;j<=4;j++){
      for(int k=1;k<=4;k++){
        ans.map[i][j]=std::max(ans.map[i][j],a.map[i][k]*b.map[k][j]);
      }
    }
  }
  return ans;
}
int lowbit(int x){
  return x&(-x);
}
int p[100005];
int a[100005];
int b[100005];
int c[100005];
int x[100005];
std::set<int>se;
inline int read();
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  for(int i=1;i<=n;i++){
    p[i]=read();
    a[i]=read();
    b[i]=read();
    c[i]=read();
    x[i]=read();
  }
  for(int i=n;i>=1;i--){
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
