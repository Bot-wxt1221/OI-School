#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
inline int read();
std::pair<int,int> a[505];
long double dp[505][505];
std::vector<std::pair<int,int> >vec1,vec2;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int C=read();
    int n=read();
    for(int i=1;i<=n;i++){
      a[i].first=read();
    }
    for(int i=1;i<=n;i++){
      a[i].second=read();
    }
    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++){
        dp[i][j]=0x3f3f3f3f3f3f3f;
      }
    }
    vec1.clear();
    vec2.clear();
    vec2.push_back({0,0});
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
      if(a[i].first<0){
        vec1.push_back(a[i]);
      }else{
        vec2.push_back(a[i]);
      }
    }
    vec1.push_back({0,0});
    std::reverse(vec1.begin(),vec1.end());
    dp[0][0]=0;
    for(int i=0;i<vec1.size();i++){
      for(int j=0;j<vec2.size();j++){
        long double mx1=0;
        for(int k=i+1;k<vec1.size();k++){
          mx1=std::max(mx1,((long double)(-vec1[k].first+1ll*dp[i][j]*vec1[k].second))/(C-vec1[k].second));
          long double val=mx1;
          if(k!=vec1.size()-1||j!=vec2.size()-1){
            val*=2;
          }
          dp[k][j]=std::min(dp[k][j],dp[i][j]+val);
        }
        mx1=0;
        for(int k=j+1;k<vec2.size();k++){
          mx1=std::max(mx1,((long double)(vec2[k].first+1ll*dp[i][j]*vec2[k].second))/(C-vec2[k].second));
          long double val=mx1;
          if(i!=vec1.size()-1||k!=vec2.size()-1){
            val*=2;
          }
          dp[i][k]=std::min(dp[i][k],dp[i][j]+val);
        }
      }
    }
    printf("%.8Lf\n",dp[vec1.size()-1][vec2.size()-1]);
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
