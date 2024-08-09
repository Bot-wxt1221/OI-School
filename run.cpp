#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
inline int read();
char temp[5005][5005];
int ans[5005][5005];
int h[5005];
int out[5005];
std::stack<std::pair<int,int> >st;
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("run.in","r",stdin);
  freopen("run.out","w",stdout);
  #endif
  int n=read();
  int m=read();
  for(int i=1;i<=n;i++){
    scanf("%s",temp[i]+1);
  }
  for(int i=1;i<=n;i++){
    st=std::stack<std::pair<int,int> >();
    for(int j=1;j<=m;j++){
      if(temp[i][j]=='#'){
        ans[i][j]=0;
        h[j]=ans[i][j];
      }else{
        ans[i][j]=ans[i-1][j]+1;
        h[j]=ans[i][j];
      }
      int lst=j;
      while(st.size()>0&&st.top().second>=h[j]){
        lst=st.top().first;
        st.pop();
      }
      if(h[j]==0){
        continue;
      }
      if(st.size()==0){
        st.push(std::make_pair(lst,h[j]));
      }else{
        if(st.top().second-st.top().first<h[j]-lst){
          st.push(std::make_pair(lst,h[j]));
        }
      }
      if(temp[i][j]!='#'){
        int ret=std::min(st.top().second,h[j])-st.top().first+j+1;
        out[ret]++;
      }
    }
  }
  for(int i=1;i<=n+m;i++){
    printf("%d ",out[i]);
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
