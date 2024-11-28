#include <iostream>
#include <cstdio>
#include <vector>
inline int read();
int aa[200005];
std::vector<int>tt;
int cnt[200005];
int solve(std::vector<int> &a){
  int l=0;
  int ans=0;
  for(int i=0;i<a.size();i++){
    cnt[a[i]]++;
    while(cnt[a[i]]>1){
      cnt[a[l]]--;
      l++;
    }
    ans=std::max(ans,i-l+1);
  }
  for(int i=0;i<a.size();i++){
    cnt[a[i]]=0;
  }
  return ans*2;
}
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int n=read();
  for(int i=1;i<=n;i++){
    aa[i]=read();
  }
  int ans=0;
  for(int i=1;i+1<=n;i+=2){
    if(aa[i]==aa[i+1]){
      tt.push_back(aa[i]);
    }else{
      ans=std::max(ans,solve(tt));
      tt.clear();
    }
  }
  ans=std::max(ans,solve(tt));
  tt.clear();
  for(int i=2;i+1<=n;i+=2){
    if(aa[i]==aa[i+1]){
      tt.push_back(aa[i]);
    }else{
      ans=std::max(ans,solve(tt));
      tt.clear();
    }
  }
  ans=std::max(ans,solve(tt));
  tt.clear();  
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
