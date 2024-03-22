#include <iostream>
#include <cstdio>
inline int read();
char temp[10000005];
std::string str[2000005];
int idx;
class node{
  public:
    int l,r,u,d; 
}aa[10000005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
  freopen("file.in","r",stdin);
	freopen("file.out","w",stdout);
	#endif
  int n=read(),m,q;
  m=read();
  q=read();
  for(int i=0;i<=n+1;i++){
    for(int j=0;j<=m+1;j++){
      idx++;
      if(i>0&&j>0&&i<=n&&j<=m){
        scanf("%s",temp+1);
        str[idx]=std::string(temp+1);
      }
      aa[idx].l=idx-1;
      aa[idx].r=idx+1;
      aa[idx].u=idx-m-2;
      aa[idx].d=idx+m+2;
    }
  }
  for(int i=1;i<=q;i++){
    int x1=read();
    int y1=read();
    int x2=read();
    int y2=read();
    int ll=read();
    int rr=read();
    int pos1=1;
    int pos2=1;
    for(int j=1;j<=x1;j++){
      pos1=aa[pos1].d;
    }
    for(int j=1;j<=y1;j++){
      pos1=aa[pos1].r;
    }
    for(int j=1;j<=x2;j++){
      pos2=aa[pos2].d;
    }
    for(int j=1;j<=y2;j++){
      pos2=aa[pos2].r;
    }
    int now1=pos1;
    int now2=pos2;
    for(int j=1;j<=rr;j++){
      std::swap(aa[aa[pos1].u].d,aa[aa[pos2].u].d);
      std::swap(aa[pos1].u,aa[pos2].u);
      pos1=aa[pos1].r;
      pos2=aa[pos2].r;
    }
    pos1=aa[pos1].l;
    pos2=aa[pos2].l;
    for(int j=1;j<=ll;j++){
      std::swap(aa[aa[pos1].r].l,aa[aa[pos2].r].l);
      std::swap(aa[pos1].r,aa[pos2].r);
      pos1=aa[pos1].d;
      pos2=aa[pos2].d;
    }
    pos1=now1;
    pos2=now2;
    for(int j=1;j<=ll;j++){
      std::swap(aa[aa[pos1].l].r,aa[aa[pos2].l].r);
      std::swap(aa[pos1].l,aa[pos2].l);
      pos1=aa[pos1].d;
      pos2=aa[pos2].d;
    }
    pos1=aa[pos1].u;
    pos2=aa[pos2].u;
    for(int j=1;j<=rr;j++){
      std::swap(aa[aa[pos1].d].u,aa[aa[pos2].d].u);
      std::swap(aa[pos1].d,aa[pos2].d);
      pos1=aa[pos1].r;
      pos2=aa[pos2].r;
    }
  }
  int pos=aa[aa[1].d].r;
  for(int i=1;i<=n;i++){
    int now=pos;
    for(int j=1;j<=m;j++){
      printf("%s ",str[now].c_str());
      now=aa[now].r;
    }
    printf("\n");
    pos=aa[pos].d;
  }
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
    if(c==EOF){
      return 0;
    }
		c=getchar();
	}
	while(c>='0'&&c<='9'){
    if(c==EOF){
      return 0;
    }
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


