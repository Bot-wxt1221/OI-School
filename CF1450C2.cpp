#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char temp[305][305];
int cnt[5],cnt2[5];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    memset(cnt,0,sizeof(cnt));
    memset(cnt2,0,sizeof(cnt2));
    for(int i=1;i<=n;i++){
      scanf("%s",temp[i]+1);
    }
    int tot=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cnt[(i+j)%3]+=(temp[i][j]=='O');
        cnt2[(i+j)%3]+=(temp[i][j]=='X');
        if(temp[i][j]!='.'){
          tot++;
        }
      }
    }
    tot/=3;
    for(int ti=0;ti<3;ti++){
      for(int tj=0;tj<3;tj++){
        if(ti==tj){
          continue;
        }
        if(cnt[ti]+cnt2[tj]<=tot){
          for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
              if(temp[i][j]!='.'){
                if((i+j)%3==ti&&temp[i][j]=='O'){
                  temp[i][j]='X';
                }
                if((i+j)%3==tj&&temp[i][j]=='X'){
                  temp[i][j]='O';
                }
              }
              printf("%c",temp[i][j]);
            }
            printf("\n");
          }
          goto end;
        }
      }
    }
    end:{}
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

