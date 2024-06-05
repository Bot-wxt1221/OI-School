#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <sys/time.h>
#define int long long
inline int read();
int pow(int x,int y){
  if(y==0){
    return 1;
  }
  if(y%2==0){
    int tt=pow(x,y/2);
    return (tt*tt);
  }
  return (pow(x,y-1)*x);
}
char temp[15];
int query(int l,int r,int a){
  printf("? %lld %lld %lld\n",l,r,a);
  fflush(stdout);
  scanf("%s",temp+1);
  return temp[1]=='Y';
}
int n;
bool exist[1505];
int map[1505][1505];
int getdis(int u,int v,int tt=1){
  if(map[u][v]){
    return map[u][v];
  }
  if(tt){
    for(int i=1;i<=n;i++){
      exist[i]=0;
    }
  }
  if(tt){
    exist[u]=exist[v]=1;
  }
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(i==u||i==v||query(u,i,v)){
      if(tt){
        exist[i]=1;
      }
      cnt++;
    }
  }
  return map[u][v]=map[v][u]=cnt-1;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  n=read();
  int k=read();
  int d;
  srand(time(NULL));
  for(int dep=1;;dep++){
    if((pow(k,dep)-1)/(k-1)==n){
      d=dep;
      break;
    }
  }
  int tt=0;
  for(int i=0;i<60;i++){
    int tt1,tt2;
    do{
      tt1=rand()%n+1;
      tt2=rand()%n+1;
    }while(tt1==tt2);
    if(getdis(tt1,tt2)==2*(d-1)){
      tt=tt1;
      break;
    }
  }
  for(int i=1;i<=n;i++){
    if(exist[i]){
      if(i!=tt&&getdis(i,tt,0)==d-1){
        printf("! %lld\n",i);
        fflush(stdout);
        return 0;
      }
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

