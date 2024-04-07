#include <iostream>
#include <cstdio>
static inline int read();
static inline bool is_red(char x){
  return 'a'<=x&&x<='z';
}
static inline bool is_black(char x){
  return 'A'<=x&&x<='Z';
}
static inline bool same(char x,char y){
  return (is_black(x)&&is_black(y))||(is_red(x)&&is_red(y));
}
static inline char low(char x){
  if(x>='A'&&x<='Z'){
    x-='A';
    x+='a';
  }
  return x;
}
char temp[25][25];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("chess.in","r",stdin);
  freopen("chess.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    for(int i=1;i<=10;i++){
      scanf("%s",temp[i]+1);
    }
    int ans=0;
    for(int i=1;i<=10;i++){
      for(int j=1;j<=9;j++){
        if(temp[i][j]=='*'){
          continue;
        }
        switch(low(temp[i][j])){
          case 'j':{
            for(int k1=-1;k1<=1;k1++){
              for(int k2=-1;k2<=1;k2++){
                if(k1==0&&k2==0){
                  continue;
                }
                if(k1!=0&&k2!=0){
                  continue;
                }
                if(same(temp[i][j],temp[i+k1][j+k2])){
                  continue;
                }
                if(is_red(temp[i][j])){
                  if(i+k1<1||i+k1>3||j+k2<4||j+k2>6){
                    continue;
                  }
                }
                if(is_black(temp[i][j])){
                  if(i+k1<8||i+k1>10||j+k2<4||j+k2>6){
                    continue;
                  }
                }
                ans++;
              }
            }
            if(is_red(temp[i][j])){
              for(int x1=i+1;x1<=10;x1++){
                if(temp[x1][j]!='*'){
                  if(temp[x1][j]=='J'){
                    ans++;
                  }
                  break;
                }
              }
            }
            if(is_black(temp[i][j])){
              for(int x1=i-1;x1>=1;x1--){
                if(temp[x1][j]!='*'){
                  if(temp[x1][j]=='j'){
                    ans++;
                  }
                  break;
                }
              }
            }
            break;
          }
          case 's':{
            for(int k1=-1;k1<=1;k1++){
              for(int k2=-1;k2<=1;k2++){
                if(k1==0||k2==0){
                  continue;
                }
                int tx=i+k1;
                int ty=j+k2;
                if(is_red(temp[i][j])){
                  if(i+k1<1||i+k1>3||j+k2<4||j+k2>6){
                    continue;
                  }
                }
                if(is_black(temp[i][j])){
                  if(i+k1<8||i+k1>10||j+k2<4||j+k2>6){
                    continue;
                  }
                }
                if(same(temp[tx][ty],temp[i][j])){
                  continue;
                }
                ans++;
              }
            }
            break;
          }
          case 'x':{
            for(int k1=-1;k1<=1;k1++){
              for(int k2=-1;k2<=1;k2++){
                if(k1==0||k2==0){
                  continue;
                }
                int tx=i+k1*2;
                int ty=j+k2*2;
                if(is_red(temp[i][j])){
                  if(i+k1*2<1||i+k1*2>5||j+k2*2<1||j+k2*2>9){
                    continue;
                  }
                }
                if(is_black(temp[i][j])){
                  if(i+k1*2<6||i+k1*2>10||j+k2*2<1||j+k2*2>9){
                    continue;
                  }
                }
                if(same(temp[tx][ty],temp[i][j])){
                  continue;
                }
                if(temp[(i+k1)][j+k2]!='*'){
                  continue;
                }
                ans++;
              }
            }
            break;
          }
          case 'c':{
            for(int k=1;k<=10;k++){
              if(j+k>9){
                break;
              }
              int tx=i;
              int ty=j+k;
              if(same(temp[tx][ty],temp[i][j])){
                break;
              }
              ans++;
              if(temp[tx][ty]!='*'){
                break;
              }
            }
            for(int k=1;k<=10;k++){
              if(j-k<=0){
                break;
              }
              int tx=i;
              int ty=j-k;
              if(same(temp[tx][ty],temp[i][j])){
                break;
              }
              ans++;
              if(temp[tx][ty]!='*'){
                break;
              }
            }
            for(int k=1;k<=10;k++){
              if(i+k>10){
                break;
              }
              int tx=i+k;
              int ty=j;
              if(same(temp[tx][ty],temp[i][j])){
                break;
              }
              ans++;
              if(temp[tx][ty]!='*'){
                break;
              }
            }
            for(int k=1;k<=10;k++){
              if(i-k<=0){
                break;
              }
              int tx=i-k;
              int ty=j;
              if(same(temp[tx][ty],temp[i][j])){
                break;
              }
              ans++;
              if(temp[tx][ty]!='*'){
                break;
              }
            }
            break;
          }
          case 'm':{
            for(int k1=-1;k1<=1;k1++){
              for(int k2=-1;k2<=1;k2++){
                if(k1==0||k2==0){
                  continue;
                }
                int tx=i+k1*2;
                int ty=j+k2;
                if(tx<=0||tx>10||ty<=0||ty>9){
                  continue;
                }
                if(temp[i+k1][j]!='*'){
                  continue;
                }
                if(same(temp[tx][ty],temp[i][j])){
                  continue;
                }
                ans++;
              }
            }
            for(int k1=-1;k1<=1;k1++){
              for(int k2=-1;k2<=1;k2++){
                if(k1==0||k2==0){
                  continue;
                }
                int tx=i+k1;
                int ty=j+k2*2;
                if(tx<=0||tx>10||ty<=0||ty>9){
                  continue;
                }
                if(temp[i][j+k2]!='*'){
                  continue;
                }
                if(same(temp[tx][ty],temp[i][j])){
                  continue;
                }
                ans++;
              }
            }
            break;
          }
          case 'p':{
            bool yes=0; 
            for(int k=1;k<=10;k++){
              if(j+k>9){
                break;
              }
              int tx=i;
              int ty=j+k;
              if(yes){
                if(temp[tx][ty]!='*'&&same(temp[tx][ty],temp[i][j])==0){
                  ans++;
                }
              }else{
                if(temp[tx][ty]=='*'){
                  ans++;
                }
              }
              if(temp[tx][ty]!='*'){
                if(yes){
                  break;
                }
                yes=1;
                continue;
              }
            }
            yes=0;
            for(int k=1;k<=10;k++){
              if(j-k<=0){
                break;
              }
              int tx=i;
              int ty=j-k;
              if(yes){
                if(temp[tx][ty]!='*'&&same(temp[tx][ty],temp[i][j])==0){
                  ans++;
                }
              }else{
                if(temp[tx][ty]=='*'){
                  ans++;
                }
              }
              if(temp[tx][ty]!='*'){
                if(yes){
                  break;
                }
                yes=1;
                continue;
              }
            }
            yes=0;
            for(int k=1;k<=10;k++){
              if(i+k>10){
                break;
              }
              int tx=i+k;
              int ty=j;
              if(yes){
                if(temp[tx][ty]!='*'&&same(temp[tx][ty],temp[i][j])==0){
                  ans++;
                }
              }else{
                if(temp[tx][ty]=='*'){
                  ans++;
                }
              }
              if(temp[tx][ty]!='*'){
                if(yes){
                  break;
                }
                yes=1;
                continue;
              }
            }
            yes=0;
            for(int k=1;k<=10;k++){
              if(i-k<=0){
                break;
              }
              int tx=i-k;
              int ty=j;
              if(yes){
                if(temp[tx][ty]!='*'&&same(temp[tx][ty],temp[i][j])==0){
                  ans++;
                }
              }else{
                if(temp[tx][ty]=='*'){
                  ans++;
                }
              }
              if(temp[tx][ty]!='*'){
                if(yes){
                  break;
                }
                yes=1;
                continue;
              }
            }
            break;
          }
          case 'b':{
            if(is_red(temp[i][j])){
              if(i>=6){
                if(same(temp[i][j-1],temp[i][j])==0&&j-1>0){
                  ans++;
                }
                if(same(temp[i][j+1],temp[i][j])==0&&j+1<=9){
                  ans++;
                }
              }
              if(i+1<=10&&same(temp[i+1][j],temp[i][j])==0){
                ans++;
              }
            }else{
              if(i<=5){
                if(same(temp[i][j-1],temp[i][j])==0&&j-1>0){
                  ans++;
                }
                if(same(temp[i][j+1],temp[i][j])==0&&j+1<=9){
                  ans++;
                }
              }
              if(i-1>=1&&same(temp[i-1][j],temp[i][j])==0){
                ans++;
              }
            }
            break;
          }
        }
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
static inline int read(){
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

