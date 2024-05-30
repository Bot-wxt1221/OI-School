#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
inline int read();
std::queue<char>ans;
bool found[1005];
char s[1005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read(),k,m;
    k=read();
    m=read();
    scanf("%s",s+1);
    ans=std::queue<char>();
    memset(found,0,sizeof(found));
    int count=0;
    for(int i=1;i<=m;i++){
      if(ans.size()==n){
        break;
      }
      count+=(found[s[i]-'a'+1]==0);
      found[s[i]-'a'+1]=1;
      if(count==k){
        memset(found,0,sizeof(found));
        count=0;
        ans.push(s[i]);
      }
    }
    if(ans.size()==n){
      printf("Yes\n");
    }else{
      printf("No\n");
      for(int i=1;i<=k;i++){
        if(found[i]==0){
          while(ans.size()<n){
            ans.push(i+'a'-1);
          }
        }
      }
      while(ans.size()>0){
        printf("%c",ans.front());
        ans.pop();
      }
      printf("\n");
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


