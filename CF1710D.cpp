#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
char temp[2005][2005];
int fa[2005];
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
signed main(){
  #ifndef ONLINE_JUDGE
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    for(int i=1;i<=n;i++){
      scanf("%s",temp[i]+i);
      fa[i]=i;
    }
    for(int i=1;i<=n;i++){
      for(int j=i-1;j>=1;j--){
        if(temp[j][i]=='1'&&getfa(i)>j){
          printf("%d %d\n",j,i);
          if(getfa(getfa(i)-1)>j){
            printf("%d %d\n",j,getfa(i)-1);
            for(int k=j+1;k<=getfa(getfa(i)-1)-1;k++){
              if(getfa(k)==k){
                printf("%d %d\n",k,i);
              }
            }
          }
          for(int k=j;k<=i;k++){
            fa[getfa(k)]=getfa(j);
          }
        }
      }
    }
  }
  return 0;
}
inline int read(){
  int f=1,x=0;
  char temp=getchar();
  while(temp>'9'||temp<'0'){
    (temp=='-')?(f=-1):0;
    temp=getchar();
  }
  while('0'<=temp&&temp<='9'){
    x=(x<<3)+(x<<1)+(temp^'0');
    temp=getchar();
  }
  return f*x;
}
