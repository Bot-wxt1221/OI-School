#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
std::vector<int>vec;
int fir[100005];
int a[100005];
int b[100005];
char temp[100005];
char temp1[100005];
int now;
bool ans=0;
int v[200005];
int nxt[200005];
bool vised[100005];
int er[100005];
bool iser=1;
void dfs(int now,int fa,int color){
  vised[now]=1;
  er[now]=color;
  vec.push_back(now);
  for(int i=fir[now];i!=-1;i=nxt[i]){
    if(v[i]==fa){
      continue;
    }
    if(vised[v[i]]){
      if(er[v[i]]!=(color^1)){
        iser=0;
      }
      continue;
    }
    dfs(v[i],now,color^1);
  }
  return ;
}
std::vector<std::pair<int,int> >vec1,vec2;
std::vector<int> vec3,vec4;
void solve(){
  vec1.clear();
  vec2.clear();
  if(iser){
    for(int i=0;i<vec.size();i++){
      vec1.push_back({a[vec[i]],(temp[vec[i]]=='R')^er[vec[i]]});
      vec2.push_back({b[vec[i]],(temp1[vec[i]]=='R')^er[vec[i]]});
    }
    std::sort(vec1.begin(),vec1.end());
    std::sort(vec2.begin(),vec2.end());
    for(int i=0;i<vec.size();i++){
      if(vec1[i]!=vec2[i]){
        ans=0;
        break;
      }
    }
    return ;
  }else{
    vec3.clear();
    vec4.clear();
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<vec.size();i++){
      vec3.push_back(a[vec[i]]);
      cnt1+=(temp[vec[i]]=='R');
      cnt2+=(temp1[vec[i]]=='R');
      vec4.push_back(b[vec[i]]);
    }
    if(cnt1%2!=cnt2%2){
      ans=0;
      return ;
    }
    std::sort(vec3.begin(),vec3.end());
    std::sort(vec4.begin(),vec4.end());
    for(int i=0;i<vec.size();i++){
      if(vec3[i]!=vec4[i]){
        ans=0;
        break;
      }
    }
    return ;
  }
}
void add(int x,int y){
  v[++now]=y;
  nxt[now]=fir[x];
  fir[x]=now;
  return ;
}
int cnt[100005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("graph.in","r",stdin);
  freopen("graph.out","w",stdout);
  #endif
  int T=read();
  while(T--){
    int n=read();
    int m=read();
    for(int i=1;i<=n;i++){
      fir[i]=-1;
      vised[i]=0;
    }
    ans=1;
    now=0;
    for(int i=1;i<=m;i++){
      int x=read();
      int y=read();
      add(x,y);
      add(y,x);
    }
    for(int i=1;i<=n;i++){
      a[i]=read();
    }
    scanf("%s",temp+1);
    for(int i=1;i<=n;i++){
      b[i]=read();
    }
    scanf("%s",temp1+1);
    for(int i=1;i<=n;i++){
      if(vised[i]==0){
        iser=1;
        vec.clear();
        dfs(i,i,0);
        solve();
        if(ans==0){
          break;
        }
      }
    }
    if(ans){
      printf("YES\n");
    }else{
      printf("NO\n");
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
