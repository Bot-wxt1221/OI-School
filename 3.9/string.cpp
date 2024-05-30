#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <queue>
inline int read();
int a,b,c,d;
std::map<std::string,int>mp;
class node{
public:
  std::string a;
  int ans;
  node(std::string b,int aa){
    a=b;
    ans=aa;
    return ;
  }
};
bool operator < (node a,node b){
  return a.ans>b.ans;
}
std::priority_queue<node>qu;
bool apee[305];
std::string sa,sb;
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  #endif
  a=read();
  b=read();
  c=read();
  d=read();
  std::cin>>sa>>sb;
  for(int i=0;i<sa.size();i++){
    apee[sa[i]]=1;
  }
  for(int j=0;j<sb.size();j++){
    apee[sb[j]]=1;
  }
  qu.push(node(sa,1));
  mp[sa]=1;
  mp[""]=sa.size();
  qu.push(node("",sa.size()));
  while(qu.size()>0&&mp[sb]==0){
    node tt=qu.top(); 
    qu.pop();
    if(mp[tt.a]!=tt.ans){
      continue;
    }
    for(int i=0;i<tt.a.size();i++){
      std::string ts="";
      if(i>0){
        ts+=std::string(tt.a,0,i);
      }
      if(i<int(tt.a.size())-1){
        ts+=std::string(tt.a,i+1,tt.a.size());
      }
      if(mp[ts]==0||mp[ts]>tt.ans+b){
        mp[ts]=tt.ans+b;
        qu.push(node(ts,tt.ans+b));
      }
    }
    for(int i=0;i<int(tt.a.size())-1;i++){
      std::string ts="";
      if(i>0){
        ts+=std::string(tt.a,0,i);
      }
      ts+=tt.a[i+1];
      ts+=tt.a[i];
      if(i<int(tt.a.size())-2){
        ts+=std::string(tt.a,i+2,int(tt.a.size()));
      }
      if(mp[ts]==0||mp[ts]>tt.ans+d){
        mp[ts]=tt.ans+d;
        qu.push(node(ts,tt.ans+d));
      }
    }
    for(int i=-1;i<int(tt.a.size());i++){
      for(char aa='a';aa<='z';aa++){
        if(!apee[aa]){
          continue;
        }
        std::string ts="";
        if(i>=0){
          ts+=std::string(tt.a,0,i+1);
        }
        ts+=aa;
        if(i<int(tt.a.size()-1)){
          ts+=std::string(tt.a,i+1,int(tt.a.size()));
        }
        if(mp[ts]==0||mp[ts]>tt.ans+a){
          mp[ts]=tt.ans+a;
          qu.push(node(ts,tt.ans+a));
        }
      }
    }
    for(int i=0;i<tt.a.size();i++){
      for(char aa='a';aa<='z';aa++){
        if(!apee[aa]){
          continue;
        }
        std::string ts="";
        if(i>0){
          ts+=std::string(tt.a,0,i);
        }
        ts+=aa;
        if(i<int(tt.a.size())-1){
          ts+=std::string(tt.a,i+1,int(tt.a.size()));
        }
        if(mp[ts]==0||mp[ts]>tt.ans+c){
          mp[ts]=tt.ans+c;
          qu.push(node(ts,tt.ans+c));
        }
      }
    }

  }

  printf("%d\n",mp[sb]-1);
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


