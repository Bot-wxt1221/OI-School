#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int seq[405];
int anss[405];
int s[205];
int t[205];
int cnt2[405][405];
int f[2][405][205];
int ans[405][405];
int get(int L,int R,int x,int y){
  return std::min(cnt2[L][R]+x+y,f[0][L][x]+f[1][R][y]);
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int cnt=0;
  for(int i=1;i<=n;i++){
    s[i]=read();
    t[i]=read()+s[i];
    seq[++cnt]=s[i];
    seq[++cnt]=t[i];
  }
  std::sort(seq+1,seq+cnt+1);
  cnt=std::unique(seq+1,seq+cnt+1)-seq-1;
  for(int i=1;i<=n;i++){
    s[i]=std::lower_bound(seq+1,seq+cnt+1,s[i])-seq;
    t[i]=std::lower_bound(seq+1,seq+cnt+1,t[i])-seq;
  }
  for(int i=1;i<=cnt;i++){
    for(int j=i;j<=cnt;j++){
      for(int k=1;k<=n;k++){
        if(i<=s[k]&&t[k]<=j){
          cnt2[i][j]++;
        }
      }
    }
  }
  for(int i=1;i<=cnt;i++){
    for(int j=0;j<=n;j++){
      f[0][i][j]=-0x3f3f3f3f;
      if(j==0){
        f[0][i][j]=cnt2[1][i];
      }
      for(int k=1;k<i;k++){
        f[0][i][j]=std::max(f[0][i][j],f[0][k][j]+cnt2[k][i]);
        f[0][i][j]=std::max(f[0][i][j],f[0][k][std::max(0,j-cnt2[k][i])]);
      }
    }
  }
  for(int i=cnt;i>=1;i--){
    for(int j=0;j<=n;j++){
      f[1][i][j]=-0x3f3f3f3f;
      if(j==0){
        f[1][i][j]=cnt2[i][cnt];
      }
      for(int k=i+1;k<=cnt;k++){
        f[1][i][j]=std::max(f[1][i][j],f[1][k][j]+cnt2[i][k]);
        f[1][i][j]=std::max(f[1][i][j],f[1][k][std::max(0,j-cnt2[i][k])]);
      }
    }
  }
  for(int L=1;L<=cnt;L++){
    for(int R=L;R<=cnt;R++){
      int cury=n;
      for(int x=0;x<=n;x++){
        while(cury>=1&&get(L,R,x,cury)<=get(L,R,x,cury-1)){
          cury--;
        }
        ans[L][R]=std::max(ans[L][R],get(L,R,x,cury));
      }
    }
  }
  int mx=0;
  for(int i=1;i<=n;i++){
    int ans=0;
    for(int L=1;L<=cnt;L++){
      for(int R=1;R<=cnt;R++){
        if(L<=s[i]&&t[i]<=R){
          ans=std::max(ans,::ans[L][R]);
        }
      }
    }
    mx=std::max(mx,ans);
    ::anss[i]=ans;
  }
  printf("%d\n",mx);
  for(int i=1;i<=n;i++){
    printf("%d\n",::anss[i]);
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
