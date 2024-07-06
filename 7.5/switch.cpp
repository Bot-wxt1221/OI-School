#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int n,m;
int tn,tm;
int mod[1055][1055];
int mp[1055][1055];
int op[2][1055][1055];
int map[1055][1055];
void modd(int px,int py,int tn,int tm){
  px%=tn;
  if(px<0){
    px+=tn;
  }
  py%=tm;
  if(py<0){
    py+=tm;
  }
  for(int ti=-1;ti<=1;ti++){
    for(int tj=-1;tj<=1;tj++){
      int tii=ti+px;
      int tjj=tj+py;
      tii%=tn;
      if(tii<0){
        tii+=tn;
      }
      tjj%=tm;
      if(tjj<0){
        tjj+=tm;
      }
      map[tii][tjj]^=1;
    }
  }
  return ;
}
void calc(int num,int opp){
  if(num==1){
    op[opp][0][0]=1;
    return ;
  }
  calc(num-1,opp^1);
  memset(map,0,sizeof(map));
  for(int i=0;i<2*(num-1)-1;i++){
    for(int j=0;j<2*(num-1)-1;j++){
      if(op[opp^1][i][j]){
        modd(i+1,j+1,2*(num)-1,2*(num)-1);
      }
    }
  }
  for(int i=0;i<2*num-1;i++){
    for(int j=0;j<2*num-1;j++){
      op[opp][i][j]=0;
    }
  }
  for(int i=0;i<2*num-1;i++){
    for(int j=0;j<2*num-1;j++){
      if(map[i][j]){
        for(int ti=-(num-2);ti<=num-2;ti++){
          for(int tj=-(num-2);tj<=num-2;tj++){
            op[opp][(i+ti+2*num-1)%(2*num-1)][(j+tj+2*num-1)%(2*num-1)]^=op[opp^1][ti+num-2][tj+num-2];
          }
        }
      }
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
  n=read();
  m=read();
  tn=(1<<n);
  tm=(1<<m);
  for(int i=1;i<=(1<<n);i++){
    for(int j=1;j<=(1<<m);j++){
      mp[i-1][j-1]=0;
    }
  }
  int mx=std::max(n,m);
  calc((1<<mx),0);
  int ans=0;
  for(int i=0;i<2*(1<<mx)-1;i++){
    for(int j=0;j<2*(1<<mx)-1;j++){
      ans+=op[0][i][j];
    }
  }
  memset(map,0,sizeof(map));
  printf("%d\n",ans);
  for(int i=0;i<2*(1<<mx)-1;i++){
    for(int j=0;j<2*(1<<mx)-1;j++){
      if(op[0][i][j]){
        modd(i,j,tn,tn);
        printf("%d %d\n",i,j);
      }
    }
  }
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<(1<<m);j++){
      std::cerr<<map[i][j]<<' ';
    }
    std::cerr<<std::endl;
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
