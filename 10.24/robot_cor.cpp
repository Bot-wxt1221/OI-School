#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <cassert>
#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
std::vector<int> map[55],map2[55];
int seq[55];
int dp[(1<<25)];
long long dp2[105][105];
int fir[55];
int cnt[55];
int getfa(int x){
  return seq[x]==x?x:seq[x]=getfa(seq[x]);
}
int get(int x,int i){
  return (x>>(i-1))&1;
}
int tt[55];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read()*2;
  int cntt=0;
  int ttt=1;
  for(int i=1;i<=n;i++){
    seq[i]=i;
  }
  for(int i=1;i<=n;i++){
    int tt=read();
    seq[i]=seq[tt];
    if(tt!=i){
      ttt=0;
    }
  }
  if(ttt){
		dp2[0][0]=1;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=i;j++){
				if(i){
					dp2[i][j]+=dp2[i-1][j];
				}
				if(j){
					dp2[i][j]+=dp2[i][j-1];
				}
			}
		}
    printf("%lld",dp2[n/2][n/2]);
    return 0;
//    assert(dp2[n][n]);
  }
  for(int i=1;i<=n;i++){
    getfa(seq[i]);
  }
  for(int i=1;i<=n/2;i++){
    cnt[seq[i]]|=1;
  }
  for(int i=n/2+1;i<=n;i++){
    fir[seq[i]]=i;
    cnt[seq[i]]|=2;
  }
  for(int i=1;i<=n;i++){
    if(cnt[i]==3){
      tt[i]=++cntt;
    }
  }
  for(int i=0;i<(1<<(n/2));i++){
    int curx=0,cury=0;
    bool yes=1;
    int sta=0;
    for(int j=1;j<=n/2;j++){
      curx+=((i>>(j-1))&1);
      cury+=!((i>>(j-1))&1);
      if(curx>cury){
        yes=0;
        break;
      }
      if(cnt[seq[j]]==1&&seq[j]!=j){
        if(get(i,j)!=get(i,seq[j])){
          yes=0;
          break;
        }
      }else if(cnt[seq[j]]==3){
        if(get(i,j)!=get(i,seq[j])){
          yes=0;
          break;
        }
        sta|=(get(i,j)<<(tt[seq[j]]-1));
      }
    }
    if(yes){
      map[curx].push_back(sta);
    }
  }
  for(int i=0;i<(1<<(n/2));i++){
    int curx=n/2,cury=n/2;
    bool yes=1;
    int sta=0;
    for(int j=n/2;j>=1;j--){
      curx-=((i>>(j-1))&1);
      cury-=!((i>>(j-1))&1);
      if(curx>cury){
        yes=0;
        break;
      }
      if(::cnt[seq[j+n/2]]==2&&seq[j+n/2]!=seq[j]){
        if(get(i,j)!=get(i,fir[seq[j+n/2]]-n/2)){
          yes=0;
          break;
        }
      }else if(::cnt[seq[j+n/2]]==3){
        if(get(i,j)!=get(i,fir[seq[j+n/2]]-n/2)){
          yes=0;
          break;
        }
        sta|=(get(i,j)<<(tt[seq[j+n/2]]-1));
      }
    }
    if(yes){
      map2[curx].push_back(sta);
    }
  }
  long long ans=0;
  for(int i=0;i<=n/2;i++){
      for(int k=0;k<map[i].size();k++){
        dp[map[i][k]]++;
      }
      for(int k=0;k<map2[i].size();k++){
        ans+=dp[map2[i][k]];
      }
      for(int k=0;k<map[i].size();k++){
        dp[map[i][k]]--;
    }
  }
  printf("%lld",ans);
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
