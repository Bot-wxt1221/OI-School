#include <vector>
#include <iostream>
#include <cstdio>
inline int read();
char temp1[800005];
char temp2[800005];
char temp[800005];
int beg[800005];
int rk[2][8000005];
int sa[8000005];
int height[8000005];
std::vector<int>vec[8000005],vec2[8000005];
signed main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  scanf("%s",temp1+1);
  scanf("%s",temp2+1);
  int n=0;
  for(int i=1;temp1[i]!='\0';i++){
    temp[++n]=temp1[i];
    beg[i]=1;
  }
  temp[++n]='#';
  for(int i=1;temp2[i]!='\0';i++){
    temp[++n]=temp2[i];
  }
  int tn=n;
  int tt=1;
  while(tt<=n){
    tt*=2;
  }
  n=tt;
  int op=0;
  for(int i=1;i<=n;i++){
    rk[op][i]=temp[i];
  }
  for(int i=2;i<=n;(i=(i<<1))){
    op^=1;
    int mx=0;
    for(int j=1;j<=n;j++){
      vec[rk[op^1][j+i/2]].push_back(j);
      mx=std::max(mx,rk[op^1][j+i/2]);
    }
    int mx2=0;
    for(int j=0;j<=mx;j++){
      for(int k=0;k<vec[j].size();k++){
        vec2[rk[op^1][vec[j][k]]].push_back(vec[j][k]);
        mx2=std::max(mx2,rk[op^1][vec[j][k]]);
      }
    }
    int cnt=0;
    for(int j=0;j<=mx2;j++){
      vec[j].clear();
      for(int k=0;k<vec2[j].size();k++){
        cnt++;
        rk[op][vec2[j][k]]=cnt;
        if(k!=0&&rk[op^1][vec2[j][k]+i/2]==rk[op^1][vec2[j][k-1]+i/2]){
          rk[op][vec2[j][k]]=rk[op][vec2[j][k-1]];
        }
      }
      vec2[j].clear();
    }
  }
  for(int i=1;i<=n;i++){
    rk[op][i]-=n-tn;
  }
  for(int i=1;i<=n;i++){
    if(rk[op][i]>=0){
      sa[rk[op][i]]=i;
    }
  }
  for(int i=1,k=0;i<=tn;i++){
    if(rk[op][i]==0){
      continue;
    }
    if(k){
      k--;
    }
    while(temp[i+k]==temp[sa[rk[op][i]-1]+k]){
      k++;
    }
    height[rk[op][i]]=k;
  }
  int cnt1=0,cnt2=0;
  long long tans=0;
  for(int i=1;i<=tn;i++){
    if(height[i]==0){
      tans+=(cnt1*1ll*cnt2);
      cnt1=0;
      cnt2=0;
    }
    if(beg[sa[i-1]]){
      cnt1++;
    }else if(temp[sa[i-1]]!='#'){
      cnt2++;
    }
  }
  tans+=(1ll*cnt1*cnt2);
  printf("%lld",tans);
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

