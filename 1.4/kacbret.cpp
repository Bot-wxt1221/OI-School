#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char temp[250];
bool used[250];
int siz;
char a[250];
int len;
char ans[250];
void dfs(int now){
  int cntt=0;
  bool con=0;
  bool ncon=0;
  for(int i=1;i<=siz;i++){
    if(used[i]){
      continue;
    }
    a[++cntt]=temp[i];
    if(a[cntt]=='('&&ans[cntt]==')'){
      ncon=1;
    }
    if(a[cntt]==')'&&ans[cntt]=='('&&!ncon){
      con=1;
      break;
    }
  }
  if(len==0){
    len=cntt;
    for(int i=1;i<=cntt;i++){
      ans[i]=a[i];
    }
  }else if(!con){
    int yes=0;
    int yes2=0;
    for(int i=1;i<=std::min(len,cntt);i++){
      if(ans[i]=='('&&a[i]==')'){
        yes=1;
        break;
      }else if(ans[i]==')'&&a[i]=='('){
        yes2=1;
      }
    }
    if(len<cntt){
      yes=1;
    }
    if((!yes)||yes2){
      len=cntt;
      for(int i=1;i<=cntt;i++){
        ans[i]=a[i];
      }
    }
  }
  for(int i=1;i<=siz;i++){
    if(used[i]||temp[i]!='('){
      continue;
    }
    for(int j=i+1;j<=siz;j++){
      if(used[j]||temp[j]!=')'){
        continue;
      }
      used[i]=used[j]=1;
      dfs(now+1);
      used[i]=used[j]=0;
    }
  }
  return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("kacbret.in","r",stdin);
	freopen("kacbret.out","w",stdout);
	#endif
  scanf("%s",temp+1);
  siz=strlen(temp+1);
  len=0;
  dfs(1);
  for(int i=1;i<=len;i++){
    printf("%c",ans[i]);
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


