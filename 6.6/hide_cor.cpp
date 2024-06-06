#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
inline int read();
std::vector<int>ques[500005];
int l[500005];
int r[500005];
std::stack<int>st;
int mxl[500005],mxr[500005];
std::vector<int>l2[500005];
std::vector<int>r2[500005];
std::vector<int>vq[4000005];
int ans[500005];
void cdq(int now,int l,int r){
  if(l==r){
    bool yes=0;
    for(int i=0;i<l2[l].size();i++){
      if(l2[l][i]==l){
        yes=1;
      }
    }
    for(int i=0;i<vq[now].size();i++){
      ans[vq[now][i]]=yes;
    }
    return ;
  }
  int mid=(l+r)/2;
  for(int i=0;i<vq[now].size();i++){
    if(l<=::l[vq[now][i]]&&::r[vq[now][i]]<=mid){
      vq[now*2].push_back(vq[now][i]);
    }else if(mid+1<=::l[vq[now][i]]&&::r[vq[now][i]]<=r){
      vq[now*2+1].push_back(vq[now][i]);
    }
  }
  cdq(now*2,l,mid);
  cdq(now*2+1,mid+1,r);
  while(st.size()>0){
    st.pop();
  }
  for(int i=mid;i>=l;i--){
    mxl[i]=r+1;
    int ml=-0x3f3f3f3f;
    for(int j=0;j<l2[i].size();j++){
      int tt=l2[i][j];
      if(tt>r){
        continue;
      }
      if(tt<mid){
        ml=std::max(ml,tt);
      }else{
        mxl[i]=std::min(mxl[i],tt);
      }
    }
    while(st.size()>0&&(st.top()<=ml+1)){
      mxl[i]=std::min(mxl[i],mxl[st.top()]);
      st.pop();
    }
    while(st.size()>0&&mxl[st.top()]>=mxl[i]){
      st.pop();
    }
    st.push(i);
  }
  while(st.size()>0){
    st.pop();
  }
  for(int i=mid+1;i<=r;i++){
    mxr[i]=0;
    int ml=0x3f3f3f3f;
    for(int j=0;j<r2[i].size();j++){
      int tt=r2[i][j];
      if(tt<l){
        continue;
      }
      if(tt>mid+1){
        ml=std::min(ml,tt);
      }else{
        mxr[i]=std::max(mxr[i],tt);
      }
    }
    while(st.size()>0&&(st.top()>=ml-1)){
      mxr[i]=std::max(mxr[i],mxr[st.top()]);
      st.pop();
    }
    while(st.size()>0&&mxr[st.top()]<=mxr[i]){
      st.pop();
    }
    st.push(i);
  }
  for(int i=0;i<vq[now].size();i++){
    if(l<=::l[vq[now][i]]&&::r[vq[now][i]]<=mid){
    }else if(mid+1<=::l[vq[now][i]]&&::r[vq[now][i]]<=r){
    }else{
      int tl=::l[vq[now][i]];
      int tr=::r[vq[now][i]];
      if(mxl[tl]<=tr&&mxr[tr]>=tl){
        ans[vq[now][i]]=1;
      }else{
        ans[vq[now][i]]=0;
      }
    }
  }
  return ;
}
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read();
  int m=read();
  int q=read();
  for(int i=1;i<=m;i++){
    int l=read();
    int r=read();
    l2[l].push_back(r);
    r2[r].push_back(l);
  }
  for(int i=1;i<=q;i++){
    int u=read();
    int v=read();
    ::l[i]=u;
    ::r[i]=v;
    ques[u].push_back(v);
    vq[1].push_back(i);
  }
  cdq(1,1,n);
  for(int i=1;i<=q;i++){
    if(ans[i]){
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

