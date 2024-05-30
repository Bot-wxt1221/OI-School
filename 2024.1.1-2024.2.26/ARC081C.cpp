#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char temp[200005];
int dp[200005];
int next[200005][30];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  scanf("%s",temp+1);
  int siz=strlen(temp+1);
  for(int i=siz;i>=1;i--){
    dp[i]=0x3f3f3f3f;
    for(int j='a';j<='z';j++){
      if(j==temp[i]){
        next[i][j-'a']=i;
      }else{
        next[i][j-'a']=next[i+1][j-'a'];
      }
    }
  }
  dp[siz+1]=0x3f3f3f3f;
  for(int i=siz;i>=1;i--){
    for(int j='a';j<='z';j++){
      if(next[i][j-'a']==0){
        dp[i]=1;
        break;
      }else{
        dp[i]=std::min(dp[i],dp[next[i][j-'a']+1]+1);
      }
    }
  }
  int len=dp[1];
  int to=1;
  while(len>0){
    len--;
    for(int i='a';i<='z';i++){
      if(dp[to]==dp[next[to][i-'a']+1]+1){
        printf("%c",i);
        to=next[to][i-'a']+1;
        break;
      }
    }
    for(int i='a';i<='z';i++){
      if(next[to][i-'a']==0){
        printf("%c",i);
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


