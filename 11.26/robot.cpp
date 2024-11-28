#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#define int __int128
inline int read();
std::vector<std::pair<int,int> >vec,vec2;
std::vector<int>vec3;
std::vector<std::pair<int,std::pair<int,int> > >vec4;
signed main(){
	#ifndef ONLINE_JUDGE
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	#endif
  int T=read();
  while(T--){
    int n=read();
    int pre=0;
    vec.clear();
    vec2.clear();
    vec3.clear();
    vec4.clear();
    for(int i=1;i<=n;i++){
      int v=read();
      int a=read();
      vec.push_back({(pre),v});
      pre+=a;
      vec3.push_back(pre);
    }
    pre=0;
    int m=read();
    for(int i=1;i<=m;i++){
      int v=read();
      int a=read();
      vec2.push_back({(pre),v});
      pre+=a;
      vec3.push_back(pre);
    }
    vec3.push_back(0);
    std::sort(vec3.begin(),vec3.end());
    vec3.resize(std::unique(vec3.begin(),vec3.end())-vec3.begin());
    vec4.push_back({0ll,{1ll,1ll}});
    vec4.push_back({1ll,{-1ll,-1ll}});
    int dis=0;
    for(int i=1;i<vec3.size();i++){
      int v1=(--std::lower_bound(vec.begin(),vec.end(),std::make_pair(vec3[i-1],(int)0x3f3f3f3f3f3f3f3fll)))->second;
      int v2=(--std::lower_bound(vec2.begin(),vec2.end(),std::make_pair(vec3[i-1],(int)0x3f3f3f3f3f3f3f3fll)))->second;
      if(v1-v2==0){
        vec4.push_back({dis  ,{vec3[i]-vec3[i-1],vec3[i]-vec3[i-1]}});
        vec4.push_back({dis+1,{vec3[i-1]-vec3[i],vec3[i-1]-vec3[i]}});
      }else{
        int st=dis;
        dis+=(v1-v2)*(vec3[i]-vec3[i-1]);
        int ed=dis;
        bool sp=0;
        if(st>ed){
          sp=1;
          std::swap(st,ed);
          ed--;
        }else{
          st++;
        }
        if((v1-v2)%2!=0){
          vec4.push_back({st,{1ll,1ll}});
          vec4.push_back({ed+1,{-1ll,-1ll}});

          vec4.push_back({st+1,{0ll,0ll}});
          vec4.push_back({st-1,{0ll,0ll}});

          vec4.push_back({ed+2,{0ll,0ll}});
          vec4.push_back({ed+0,{0ll,0ll}});
        }else{
          if(sp){
            ed--;
          }else{
            st++;
          }
          if(st%2==0){
            vec4.push_back({st,{0ll,1ll}});
            vec4.push_back({ed+2,{0ll,-1ll}});
          }else{
            vec4.push_back({st,{1ll,0ll}});
            vec4.push_back({ed+2,{-1ll,0ll}});
          }
        }
      }
    }
    std::sort(vec4.begin(),vec4.end());
    int ans=0;
    int ans1=0,ans2=0;
    for(int i=0;i<vec4.size();i++){
      ans1+=vec4[i].second.first;
      ans2+=vec4[i].second.second;
      if(i==vec4.size()-1||vec4[i].first!=vec4[i+1].first){
        if((vec4[i].first%2+2)%2==1){
          ans=std::max(ans,ans1);
        }else{
          ans=std::max(ans,ans2);
        }
      }
    }
    printf("%lld\n",(long long)ans);
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
