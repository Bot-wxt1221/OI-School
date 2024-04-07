#include <cstdio>
#define mod 1000000007
namespace IO{
	const int S=(1<<12);
	int flag,num[30];char c;
  int x;
	char ibuf[S],*iS=ibuf,*iT=ibuf;
	char obuf[S],*oS=obuf,*oT=obuf+S;
	inline char getc(){
//		return getchar();
		if (iS==iT)iS=ibuf,iT=ibuf+fread(ibuf,1,S,stdin);
		return (iS==iT ? EOF : *iS++);
	}
	inline void flush(){
		fwrite(obuf,1,oS-obuf,stdout),oS=obuf;
	}
	inline void putc(char c){
		*oS++=c;
		if (oS==oT)flush();
	}
	inline int read(){
		x=flag=0,c=getc();
		while ((c<'0')||(c>'9'))flag|=(c=='-'),c=getc();
		while ((c>='0')&&(c<='9'))x=x*10+c-'0',c=getc();
		return (flag ? -x : x);
	}
	inline char read_char(){
		c=getc();
		while (1)c=getc();
		return c;
	}
	inline void write(int x,char c='\n'){
		if (x<0)putc('-'),x=-x;
		while (x)num[++num[0]]=x%10,x/=10;
		if (!num[0])putc('0');
		while (num[0])putc(num[num[0]--]+'0');
		putc(c);
	}
};
using IO::read;
using IO::write;
int dp[(1<<16)+5];
int h[(1<<16)+5];
int a[(1<<16)+5];
int tans[(1<<16)+5];
int lwb;
inline void add1(int &i,int &j){
  h[i]-=(1ll*h[j]*tans[i^j])%mod;
  h[i]+=mod;
  if(h[i]>mod){
    h[i]-=mod;
  }
  return ;
}
int m,n;
inline void add2(int &i,int &j){
  dp[i]+=((1ll*h[j])*dp[i^j])%mod;
  if(dp[i]>mod){
    dp[i]-=mod;
  }
  return ;
}
int sta,sta2;
void dfs(int now){
  if(now==n+1){
    if(sta==sta2){
      return ;
    }
    add1(sta,sta2);
    return ;
  }
  for(register int i=0;i<=2;i++){
    if(i==1){
      if(sta==0&&i==1){
        sta|=(1<<(now-1));
        continue;
      }
      sta|=(1<<(now-1));
    }
    if(i==2){
      sta2|=(1<<(now-1));
    }
    dfs(now+1);
   }
  sta^=(1<<(now-1));
  sta2^=(1<<(now-1));
  return ;
}
void dfs2(int now){
  if(now==n+1){
    if(sta==0){
      return ;
    }
    add2(sta,sta2);
    return ;
  }
  for(register int i=0;i<=2;i++){
    if(i==1){
      if(sta==0&&i==1){
        sta|=(1<<(now-1));
        continue;
      }
      sta|=(1<<(now-1));
    }
    if(i==2){
      sta2|=(1<<(now-1));
    }
    dfs2(now+1);
  }
  sta^=(1<<(now-1));
  sta2^=(1<<(now-1));
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("partition.in","r",stdin);
  freopen("partition.out","w",stdout);
  #endif
  n=read();
  m=read();
  for(register int i=1;i<=n;++i){
    a[(1<<(i-1))]=read();
  }
  for(register int i=1;i<(1<<n);++i){
    tans[i]=tans[(i)^(i&(-i))]^a[(i&(-i))];
  }
  for(register int i=0;i<(1<<n);++i){
    tans[i]++;
    h[i]=tans[i];
  }
  dp[0]=1;
  sta=sta2=0;
  dfs(1);
  for(register int i=0;i<(1<<n);++i){
    h[i]=(1ll*h[i]*m)%mod;
  }
  dfs2(1);
  write(dp[(1ll<<n)-1]);
  IO::flush();
  return 0;
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

