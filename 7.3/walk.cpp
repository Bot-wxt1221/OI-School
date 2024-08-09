#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
inline int read();
std::vector<std::pair<int,std::pair<int,int> > >black;
std::vector<std::pair<int,std::pair<int,int> > >red;
int ql[15],qr[15];
int ans[15][3];
std::vector<std::pair<int,std::pair<int,int> > >tot;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("walk.in","r",stdin);
  freopen("walk.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int q=read();
  int L=read();
  int T=read();
  for(int i=1;i<=n;i++){
    int pos=read();
    int tott=read();
    black.push_back(std::make_pair(pos*2,std::make_pair(tott,1)));
    tot.push_back(std::make_pair(pos*2,std::make_pair(tott,1)));
  }
  std::sort(black.begin(),black.end());
  for(int i=1;i<=m;i++){
    int pos=read();
    int tott=read();
    red.push_back(std::make_pair(pos*2,std::make_pair(tott,2)));
    tot.push_back(std::make_pair(pos*2,std::make_pair(tott,2)));
  }
  std::sort(red.begin(),red.end());
  for(int i=1;i<=q;i++){
    ql[i]=read()*2;
    qr[i]=read()*2;
  }
  L*=2;
  T*=2;
  if(m!=0){
    for(int TT=1;TT<=T;TT++){
      for(int i=0;i<(n+m);i++){
        tot[i].first+=tot[i].second.first;
        if(tot[i].first==-1){
          tot[i].first=1;
          tot[i].second.first*=-1;
        }
        if(tot[i].first==L+1){
          tot[i].first=L-1;
          tot[i].second.first*=-1;
        }
      }
      for(int i=0;i<(n+m);i++){
        for(int j=i+1;j<(n+m);j++){
          if(tot[i].first==tot[j].first){
            if(tot[i].second.second==tot[j].second.second){
              for(int qq=1;qq<=q;qq++){
                if(ql[qq]<=tot[i].first&&tot[i].first<=qr[qq]){
                  ans[qq][tot[i].second.second-1]++;
                }
              }
            }else{
              for(int qq=1;qq<=q;qq++){
                if(ql[qq]<=tot[i].first&&tot[i].first<=qr[qq]){
                  ans[qq][2]++;
                }
              }
            }
          }
        }
      }
    }
    for(int i=1;i<=q;i++){
      printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
  }else{
    for(int i=0;i<n;i++){
      std::cerr<<i;
      for(int j=i+1;j<n;j++){
        int ti=black[i].first,tj=black[j].first;
        int pos1=black[i].second.first,pos2=black[j].second.first;
        int time=0;
        for(int cntt=1;cntt<=L*2;cntt++){
          ti+=pos1;
          while(ti>L){
            pos1*=-1;
            ti=L-(ti-L);
          }
          while(ti<0){
            pos1*=-1;
            ti=-ti;
          }
          tj+=pos2;
          while(tj>L){
            pos2*=-1;
            tj=L-(tj-L);
          }
          while(tj<0){
            pos2*=-1;
            tj=-tj;
          }
          if(ti==tj){
            time=cntt;
            break;
          }
        }
        for(int qq=1;qq<=q;qq++){
          if(ql[qq]<=ti&&ti<=qr[qq]){
            ans[qq][0]+=(T-time)/(2*L)+1;
          }
        }
      }
    }
    for(int i=1;i<=q;i++){
      printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
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
