#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char temp[30005];
char temp2[10]="agnus";
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("agnus.in","r",stdin);
	freopen("agnus.out","w",stdout);
	#endif
  scanf("%s",temp+1);
  int siz=strlen(temp+1);
  int ans=0;
  int pre=1;
  for(int i=1;i+4<=siz;i++){
    bool yes=1;
    for(int j=0;j<5;j++){
      if(temp[i+j]!=temp2[j]){
        yes=0;
        break;
      }
    }
    if(yes){
      ans+=(siz-(i+4)+1)*(i-pre+1);
      pre=i+1;
    }
  }
  printf("%d",ans);
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


