#include <iostream>
#include <cstdio>
#define int __int128
inline int read();
inline void write(int a){
  static char tt[128];
  int cnt=0;
  while(a){
    tt[++cnt]=a%10+'0';
    a/=10;
  }
  for(int i=cnt;i>=1;i--){
    putchar(tt[i]);
  }
  return ;
}
int a[125];
bool cho[125];
int tot[125];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),k;
  int m=read();
  k=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
  }
  if(k==1){
    int mans=0;
    int cnt=0;
    for(int i=m-1;i>=0;i--){
      cnt=0;
      for(int j=1;j<=n;j++){
        if(a[j]&(((__int128)1)<<(i))){
          cho[j]=0;
        }else{
          cnt++;
          cho[j]=1;
        }
      }
      int ans=0;
      int used=(1<<(i));
      for(int j=1;j<=n;j++){
        if(!cho[j]){
          continue;
        }
        for(int kk=i-1;kk>=0;kk--){
          if((((__int128)1)<<kk)&a[j]){
            tot[kk]++;
          }
        }
      }
      for(int j=i-1;j>=0;j--){
        if(tot[j]<cnt-tot[j]){
          used|=(1<<j);
        }
      }
      for(int j=1;j<=n;j++){
        if(!cho[j]){
          ans+=a[j];
          continue;
        }
        ans+=a[j]^used;
      }
      mans=std::max(mans,ans);
    }
    write(mans);
    putchar('\n');
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

