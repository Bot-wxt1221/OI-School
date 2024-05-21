#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
char temp[100005];
int pre[300];
int ans[100005];
int ans2[100005];
int sum[100005][30];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
  #endif
  int n=read();
  int q=read();
  scanf("%s",temp+1);
  for(int i=1;i<=n;i++){
    for(char a='A';a<='Z';a++){
      sum[i][a-'A']=sum[i-1][a-'A'];
      if(temp[i]==a){
        sum[i][a-'A']++;
      }
    }
  }
  for(int i=1;i<=n;i++){
    if(pre[temp[i]]==0){
      ans[i]=ans[i-1]+1;
      pre[temp[i]]=i;
      continue;
    }
    int add=0;
    for(char a='A';a<temp[i];a++){
      if(sum[i-1][a-'A']-sum[pre[temp[i]]][a-'A']>=1){
        add=1;
        break;
      }
    }
    ans[i]=ans[i-1]+add;
    pre[temp[i]]=i;
  }
  std::reverse(temp+1,temp+n+1);
  for(int i=1;i<=n;i++){
    for(char a='A';a<='Z';a++){
      sum[i][a-'A']=sum[i-1][a-'A'];
      if(temp[i]==a){
        sum[i][a-'A']++;
      }
      pre[a]=0;
    }
  }
  for(int i=1;i<=n;i++){
    if(pre[temp[i]]==0){
      ans2[i]=ans2[i-1]+1;
      pre[temp[i]]=i;
      continue;
    }
    int add=0;
    for(char a='A';a<temp[i];a++){
      if(sum[i-1][a-'A']-sum[pre[temp[i]]][a-'A']>=1){
        add=1;
        break;
      }
    }
    ans2[i]=ans2[i-1]+add;
    pre[temp[i]]=i;
  }
  for(int i=1;i<=q;i++){
    int l=read();
    int r=read();
    printf("%d\n",ans[l-1]+ans2[n-r]);
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

