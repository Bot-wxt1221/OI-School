#include <iostream>
#include <cstdio>
#include <stack>
inline int read();
std::stack<int>st;
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  #endif
  int q=read();
  while(q--){
    int n=read(),k=read();
    if(k==1){
      for(int i=1;i<=n;i++){
        printf("a");
      }
      printf("\n");
      continue;
    }
    st=std::stack<int>();
    st.push('a');
    for(int i=0;i<=k-1;i++){
      for(int j=1;j<=i;j++){
        st.push(j+'a');
      }
      st.push('a');
    }
    for(int i=k-2;i>=1;i--){
      for(int j=1;j<=i;j++){
        st.push(j+'a');
      }
      st.push('a');
      for(int j=1;j<=i;j++){
        st.push(j+'a');
      }
      st.push('a');
    }
    st.push('a');
    if(n<st.size()){
      printf("-1\n");
    }else{
      for(int i=st.size()+1;i<=n;i++){
        printf("%c",'a');
      }
      while(st.size()>0){
        printf("%c",st.top());
        st.pop();
      }
      printf("\n");
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


