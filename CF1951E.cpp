#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char temp[1000005];
bool yes(int l,int r){
  for(int i=l;i<=r;i++){
    if(temp[i]!=temp[r+l-i]){
      return 0;
    }
  }
  return 1;
}
std::string tt;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    scanf("%s",temp+1);
    tt=std::string(temp+1);
    int siz=strlen(temp+1);
    if(yes(1,siz)==0){
      printf("YES\n1\n%s\n",temp+1);
      continue;
    }
    int fir=0;
    for(int i=1;i<=siz;i++){
      if(temp[i]!=temp[1]){
        fir=i;
        break;
      }
    }
    if((yes(1,fir)||yes(fir+1,siz))==0){
      printf("YES\n2\n");
      std::cout<<std::string(tt,0,fir)<<' '<<std::string(tt,fir,siz)<<std::endl;
      continue;
    }
    if(fir==(siz+1)/2||fir==2||fir==0){
      printf("NO\n");
    }else{
      printf("YES\n2\n");
      std::cout<<std::string(tt,0,fir+1)<<' '<<std::string(tt,fir+1,siz)<<std::endl;
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

