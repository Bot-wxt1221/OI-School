#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
std::map<std::string,int>mp;
inline int read();
std::string a;
char temp[10005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  scanf("%s",temp+1);
  int siz=strlen(temp+1);
  a=std::string(temp+1);
  int ans=0;
  for(int i=0;i<siz;i++){
    for(int j=i;j<siz;j++){
      std::string temp=std::string(a,i,j-i+1);
      if(mp[temp]==0){
        mp[temp]=1;
        ans++;
      }
    }
  }
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

