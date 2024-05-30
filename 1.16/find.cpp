#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
//#define int long long
inline long long read();
int to[520];
char temp[200005];
long long siz[200005];
std::string fir[200005];
char tt[2000005];
std::vector<int>vec2[200005];
std::vector<int>vec[200005];
std::vector<long long>nsiz[200005];
std::vector <long long>siz2[200005];
std::string dp[200005];
bool dpp[200005];
std::string dfs(int now,long long l,long long r,int to,bool rec){
  if(dpp[now]&&l==1&&r==siz[now]){
    return dp[now];
  }
  if(l==0||r==0){
    return "";
  }
  if(now==0){
    std::string t="";
    t+=char(to+'a');
    return t;
  }
  int tl=std::lower_bound(nsiz[now].begin()+1,nsiz[now].end(),l)-nsiz[now].begin();
  int tr=std::lower_bound(nsiz[now].begin()+1,nsiz[now].end(),r)-nsiz[now].begin();
  if(tl==tr){
    return dfs(vec[now][tl],l-nsiz[now][tl-1],r-nsiz[now][tr-1],vec2[now][tl],0);
  }
  std::string t="";
  t+=dfs(vec[now][tl],l-nsiz[now][tl-1],siz2[now][tl],vec2[now][tl],0);
  for(int i=tl+1;i<tr;i++){
    t+=dfs(vec[now][i],1,siz2[now][i],vec2[now][i],1);
  }
  t+=dfs(vec[now][tr],1,r-nsiz[now][tr-1],vec2[now][tr],0);
  if(l==1&&r==siz[now]){
    dpp[now]=1;
    dp[now]=t;
  }
  return t;
}

signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("8.in","r",stdin);
	freopen("find.out","w",stdout);
	#endif
  long long l=read(),r,q;
  r=read();
  q=read();
  for(int i=1;i<=q;i++){
    std::cin>>temp[i];
    scanf("%s",tt+1);
    fir[i]=std::string(tt+1);
  }
  for(int i=q;i>=1;i--){
    siz[i]=0;
    siz2[i].push_back(0);
    nsiz[i].push_back(0);
    vec[i].push_back(0);
    vec2[i].push_back(0);
    for(int j=0;j<fir[i].size();j++){
      if(to[fir[i][j]-'a']!=0){
        siz[i]+=siz[to[fir[i][j]-'a']];
        siz2[i].push_back(siz[to[fir[i][j]-'a']]);
      }else{
        siz[i]++;
        siz2[i].push_back(1);
      }
      siz[i]=std::min(siz[i],(long long)(1e18+2));
      vec[i].push_back(to[fir[i][j]-'a']);
      vec2[i].push_back(fir[i][j]-'a');
      nsiz[i].push_back(siz[i]);
    }
    to[temp[i]-'a']=i;
  }
  printf("%s",dfs(to[0],l,r,0,0).c_str());
	return 0;
}
inline long long read(){
	long long x=0,f=1;char c=getchar();
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

