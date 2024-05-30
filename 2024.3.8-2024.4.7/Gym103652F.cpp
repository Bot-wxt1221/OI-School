#include <iostream>
#include <cstdio>
#include <cstring>

inline int read();
char str[5005];
char ans[5005];
class bitset{
public:
  unsigned long long a[105];
  int l;
  void set(int i){
    a[i>>6]|=(1ull<<(i&63));
    return ;
  }
  void init(int n){
    l=(n>>6)+1;
    memset(a,0,sizeof(a));
  }
  int count(){
    int ret=0;
    for(int i=0;i<l;i++){
      ret+=__builtin_popcountll(a[i]);
    }
    return ret;
  }
}anss,g[30],tmp;
bitset move(bitset &a){
  unsigned long long flg=0,tmp;
  for(int i=0;i<a.l;i++){
    tmp=flg;
    flg=(a.a[i]>>63)&1;
    a.a[i]=(a.a[i]^(flg<<63))<<1|tmp;
  }
  return a;
}
const bitset operator  | (bitset &a,bitset &b){
  bitset ret=a;
  for(int i=0;i<a.l;i++){
    ret.a[i]|=b.a[i];
  }
  return ret;
}
const bitset operator  ^ (bitset a,bitset &b){
  bitset ret=a;
  for(int i=0;i<a.l;i++){
    ret.a[i]^=b.a[i];
  }
  return ret;
}
const bitset operator  & (bitset a,bitset &b){
  bitset ret=a;
  for(int i=0;i<a.l;i++){
    ret.a[i]&=b.a[i];
  }
  return ret;
}
const bitset operator -  (bitset &a,bitset &b){
  bitset ret=a;
  unsigned long long las=0;
  for(int i=0;i<a.l;i++){
    ret.a[i]-=b.a[i]+las;
    las=(a.a[i]<(b.a[i]+las));
  }
  return ret;
}
int solve(int l1,int r1,int l2,int r2){
  anss.init(r1-l1+1);
  for(int i=0;i<26;i++){
    g[i].init(r2-l2+1);
  }
  for(int i=l1;i<=r1;i++){
    g[str[i]-'a'].set(i);
  }
  for(int i=l2;i<=r2;i++){
    tmp=anss|g[str[i]-'a'];
    move(anss);
    anss.set(0);
    anss=((tmp-anss)^tmp)&tmp;
  }
  return anss.count();
}
int dp[5005][5005];
int to[5005][5005];
int solveans(int l1,int r1,int l2,int r2){
  int n=r1-l1+1;
  int m=r2-l2+1;
  char *a=&str[l1-1];
  char *b=&str[l2-1];
  for(int i=1;i<=std::max(n,m);i++){
    dp[i][0]=dp[0][i]=0;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i]!=b[j]){
        if(dp[i][j-1]<dp[i-1][j]){
          dp[i][j]=dp[i-1][j];
          to[i][j]=1;
        }else{
          dp[i][j]=dp[i][j-1];
          to[i][j]=2;
        }
      }else{
        to[i][j]=3;
        dp[i][j]=dp[i-1][j-1]+1;
      }
    }
  }
  int nown=n,nowm=m,cnt=dp[n][m];
  while(nown&&nowm&&cnt){
    if(to[nown][nowm]==3){
      ans[cnt--]=a[nown];
      nown--;
      nowm--;
    }else if(to[nown][nowm]==2){
      nowm--;
    }else{
      nown--;
    }
  }
  return 0;
}
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int T=read();
  int TT=0;
  while(T--){
    scanf("%s",str+1);
    int n=strlen(str+1);
    int ans=0;
    int ansi=0;
    for(int i=1;i<n;i++){
      int ret;
      ans=std::max(ans,(ret=solve(1,i,i+1,n)));
      if(ret==ans){
        ansi=i;
      }
    }
    solveans(1,ansi,ansi+1,n);
    TT++;
    printf("Case #%d: %d\n",TT,ans*2);
    if(ans){
      for(int i=1;i<=ans;i++){
        printf("%c",::ans[i]);
      }
      for(int i=1;i<=ans;i++){
        printf("%c",::ans[i]);
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


