#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
inline int read();
int dp[1400005];
int a[200005];
int cnt[200005];
int lst[200005];
std::vector<int>vec[25];
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    vec[a[i]].push_back(i);
  }
  for(int i=n;i>=1;i--){
    cnt[a[i]]++;
    if(cnt[a[i]]==2){
      lst[a[i]]=i;
    }
  }
  int ans=0;
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=20;i++){
    dp[(1<<(i-1))]=lst[i];
    if(lst[i]){
      ans=std::max(ans,2);
    }
    vec[i].push_back(n+1);
  }
  for(int i=1;i<(1<<20);i++){
    if(dp[i]){
      continue;
    }
    int cnt=0;
    for(int j=1;j<=20;j++){
      if((i&(1<<(j-1)))==0){
        continue;
      }
      cnt++;
      int lstt=dp[i^(1<<(j-1))];
      auto tt=std::lower_bound(vec[j].begin(),vec[j].end(),lstt);
      if(tt==vec[j].begin()){
        continue;
      }
      tt--;
      if(tt==vec[j].begin()){
        continue;
      }
      tt--;
      dp[i]=std::max(dp[i],*tt);
    }
    if(dp[i]!=0){
      ans=std::max(ans,cnt*2);
    }
  }
  printf("%d",ans);
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
