#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char temp[30000005];
char temp2[30000005];
int p[30000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  scanf("%s",temp+1);
  int siz=strlen(temp+1);
  int cnt=0;
  temp2[++cnt]='~';
  temp2[++cnt]='#';
  for(int i=1;i<=siz;i++){
    temp2[++cnt]=temp[i];
    temp2[++cnt]='#';
  }
  int r=0;
  int mid=0;
  int ans=0;
  for(int i=1;i<=cnt;i++){
    if(i<=r){
      p[i]=std::min(p[2*mid-i],r-i+1);
    }
    while(temp2[i-p[i]]==temp2[i+p[i]]){
      p[i]++;
    }
    if(p[i]+i>r){
      r=p[i]+i-1;
      mid=i;
    }
    ans=std::max(ans,p[i]);
  }
  printf("%d",ans-1);
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

