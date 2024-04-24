#include <iostream>
#include <cstdio>
#include <vector>
#define mod 998244353
#define int long long
inline int read();
std::vector<std::pair<int,int> >vec[200005];
int min[2000005];
bool fre[2000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m;
  m=read();
  for(int i=1;i<=n;i++){
    min[i]=0x3f3f3f3f3f3f3f;
  }
  int ff=n;
  for(int i=1;i<=m;i++){
    int x=read();
    int y=read();
    int c=read();
    if(!fre[x]){
      ff--;
    }
    if(!fre[y]){
      ff--;
    }
    min[x]=std::min(min[x],c);
    min[y]=std::min(min[y],c);
    fre[x]=1;
    fre[y]=1;
    vec[c].push_back(std::make_pair(x,y));
  }
  int ans=1;
  for(int i=n;i>=1;i--){
    if(vec[i].size()==0){
      ans*=ff;
      ans%=mod;
      ff--;
    }else{
      bool fir1=0;
      bool fir2=0;
      if(fre[vec[i][0].first]&&min[vec[i][0].first]==i){
        fre[vec[i][0].first]=0;
        ff++;
        fir1=1;
      }
      if(fre[vec[i][0].second]&&min[vec[i][0].second]==i){
        fre[vec[i][0].second]=0;
        ff++;
        fir2=1;
      }
      for(int j=1;j<vec[i].size();j++){
        if(vec[i][0].first!=vec[i][j].first&&vec[i][0].first!=vec[i][j].second){
          fir1=0;
        }
        if(vec[i][0].second!=vec[i][j].first&&vec[i][0].second!=vec[i][j].second){
          fir2=0;
        }
        if(fre[vec[i][j].first]&&min[vec[i][j].first]==i){
          fre[vec[i][j].first]=0;
          ff++;
        }
        if(fre[vec[i][j].second]&&min[vec[i][j].second]==i){
          fre[vec[i][j].second]=0;
          ff++;
        }
      }
      if(fir1||fir2){
        ans*=(fir1+fir2);
        ans%=mod;
        ff--;
      }else{
        ans=0;
      }
    }
  }
  printf("%lld",ans);
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

