#include <cstring>
#include <iostream>
#include <cstdio>
#include <cassert>
#define int __int128
inline int read();
char temp[200005][75];
long long pw[55];
int num[105];
int vised[105];
int a[105];
void insert(int x){
  for(int i=100;i>=0;i--){
    if(x&((int)1<<i)){
      if(a[i]==0){
        a[i]=x;
        return ;
      }
      x^=a[i];
    }
  }
  return ;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  read();
  int T=read();
  pw[0]=1;
  for(int i=1;i<=50;i++){
    pw[i]=pw[i-1]*3;
  }
  while(T--){
    memset(a,0,sizeof(a));
    memset(vised,0,sizeof(vised));
    int n=read();
    int m=read();
    for(int i=1;i<=n;i++){
      scanf("%s",temp[i]+1);
    }
    int ans2=0;
    int sta=0;
    for(int i=1;i<=m;i++){
      int a=read();
      int b=read();
      if(a==-1){
        ans2-=pw[b];
        vised[b]=-1;
      }
      num[i]=b*2+(a==-1?0:1)-1;
      if(a==-1){
        sta|=((int)1<<(num[i]-1));
      }
    }
    for(int i=1;i<=n;i++){
      int ans=0;
      for(int j=1;j<=m;j++){
        ans|=((int)(temp[i][j]=='1')<<(num[j]-1));
      }
      insert(ans);
    }
    for(int i=35;i>=1;i--){
      int cur1=(i-1)*2;
      int cur2=(i-1)*2+1;
      int mx=-1;
      int nwsta=sta;
      int cnt=((sta&((int)1<<cur1))>0)+((sta&((int)1<<cur2))>0);
      if(a[cur2]&((int)1<<cur1)){
        if(a[cur1]==0){
          if(cnt==1){
            insert(a[cur2]^((int)1<<cur1)^((int)1<<cur2));
            a[cur2]=0;
          }
        }
      }
      {
        int cursta=sta;
        int cnt=((cursta&((int)1<<cur1))>0)+((cursta&((int)1<<cur2))>0);
        if(cnt>mx){
          mx=cnt;
          nwsta=cursta;
        }
      }
      {
        int cursta=sta^a[cur1];
        int cnt=((cursta&((int)1<<cur1))>0)+((cursta&((int)1<<cur2))>0);
        if(cnt>mx){
          mx=cnt;
          nwsta=cursta;
        }
      }
      {
        int cursta=sta^a[cur2];
        int cnt=((cursta&((int)1<<cur1))>0)+((cursta&((int)1<<cur2))>0);
        if(cnt>mx){
          mx=cnt;
          nwsta=cursta;
        }
      }
      {
        int cursta=sta^a[cur1]^a[cur2];
        int cnt=((cursta&((int)1<<cur1))>0)+((cursta&((int)1<<cur2))>0);
        if(cnt>mx){
          mx=cnt;
          nwsta=cursta;
        }
      }
      sta=nwsta;
      ans2+=mx*pw[i];
      vised[i]+=mx;
    }
    printf("%lld\n",(long long)ans2);
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
