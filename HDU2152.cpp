#include <iostream>
#include <cstdio>
#include <map>
inline int read();
class Poly{
  public:
    std::map<int,int>vec;
};
Poly operator * (Poly a,Poly b){
  Poly ans;
  for(auto i=a.vec.begin();i!=a.vec.end();i++){
    for(auto j=b.vec.begin();j!=b.vec.end();j++){
      ans.vec[i->first+j->first]+=(i->second*j->second);
    }
  }
  return ans;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n,m;
  while(scanf("%d%d",&n,&m)!=EOF){
    Poly aa,b;
    aa.vec[0]=1;
    for(int i=1;i<=n;i++){
      b.vec.clear();
      int a=read();
      int bb=read();
      for(int j=a;j<=bb;j++){
        b.vec[j]=1;
      }
      aa=aa*b;
    }
    printf("%d\n",aa.vec[m]);
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
