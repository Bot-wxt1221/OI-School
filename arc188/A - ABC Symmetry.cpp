#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#define mod 998244353
inline int read();
class node{
public:
  int seq[8];
};
bool operator < (const node &a,const node &b){
  for(int i=0;i<8;i++){
    if(a.seq[i]!=b.seq[i]){
      return a.seq[i]<b.seq[i];
    }
  }
  return 0;
}
char temp[55];
int ans[55];
int pw[55];
std::map<node,int>mp;
std::queue<node>qu;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  int k=read();
  pw[0]=1;
  scanf("%s",temp+1);
  for(int i=1;i<=n;i++){
    pw[i]=1ll*pw[i-1]*3%mod;
  }
  for(int i=n;i>=1;i--){
    ans[i]=ans[i+1];
    if(temp[i]=='?'){
      ans[i]++;
    }
  }
  node a;
  for(int i=0;i<8;i++){
    a.seq[i]=0;
  }
  a.seq[0]++;
  qu.push(a);
  mp[a]=1;
  int tans=0;
  while(qu.size()>0){
    auto tp=qu.front();
    qu.pop();
    int ans=0;
    int cntt=0;
    for(int i=0;i<4;i++){
      ans+=(tp.seq[i]*(tp.seq[i]-1))/2;
      cntt+=tp.seq[i];
    }
    cntt--;
    if(ans>=k){
      tans+=1ll*pw[::ans[cntt+1]]*mp[tp]%mod;
      tans%=mod;
      continue;
    }
    if(cntt==n){
      continue;
    }
    if(temp[cntt+1]=='?'||temp[cntt+1]=='A'){
      auto tp2=tp;
      tp2.seq[4]^=1;
      tp2.seq[(tp2.seq[4]^tp2.seq[5])*2+(tp2.seq[4]^tp2.seq[6])]++;
      if(mp[tp2]==0){
        qu.push(tp2);
      }
      mp[tp2]+=mp[tp];
      mp[tp2]%=mod;
    }
    if(temp[cntt+1]=='?'||temp[cntt+1]=='B'){
      auto tp2=tp;
      tp2.seq[5]^=1;
      tp2.seq[(tp2.seq[4]^tp2.seq[5])*2+(tp2.seq[4]^tp2.seq[6])]++;
      if(mp[tp2]==0){
        qu.push(tp2);
      }
      mp[tp2]+=mp[tp];
      mp[tp2]%=mod;
    }
    if(temp[cntt+1]=='?'||temp[cntt+1]=='C'){
      auto tp2=tp;
      tp2.seq[6]^=1;
      tp2.seq[(tp2.seq[4]^tp2.seq[5])*2+(tp2.seq[4]^tp2.seq[6])]++;
      if(mp[tp2]==0){
        qu.push(tp2);
      }
      mp[tp2]+=mp[tp];
      mp[tp2]%=mod;
    }
  }
  printf("%d",tans);
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
