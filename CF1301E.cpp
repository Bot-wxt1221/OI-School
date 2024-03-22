#include <iostream>
#include <cstdio>
#include <cmath>
inline int read();
char temp[505][505];
int R[505][505];
int G[505][505];
int Y[505][505];
int B[505][505];
int val[255][505][505];
inline int ans(int ma[505][505],int x1,int y1,int x2,int y2){
  if(x1>x2||y1>y2){
    return 0;
  }
  x1=std::min(x1,501);
  x1=std::max(x1,1);
  y1=std::min(y1,501);
  y1=std::max(y1,1);
  x2=std::min(x2,501);
  x2=std::max(x2,1);
  y2=std::min(y2,501);
  y2=std::max(y2,1);
  return ma[x2][y2]-ma[x2][y1-1]-ma[x1-1][y2]+ma[x1-1][y1-1];
}
inline int get(int x,int l,int r){
  if(l>r){
    return 0;
  }
  int lg=std::log2(r-l+1);
  return std::max(val[lg][x][l],val[lg][x][r-(1<<lg)+1]);
}
namespace Fread {
const int SIZE = 1 << 21;
char buf[SIZE], *S, *T;
}
namespace Fwrite {
const int SIZE = 1 << 21;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
    fwrite(buf, 1, S - buf, stdout);
    S = buf;
}
inline void putchar(char c) {
    *S++ = c;
    if (S == T) flush();
}
struct NTR {
    ~ NTR() { flush(); }
} ztr;
}
#ifdef ONLINE_JUDGE
#define putchar Fwrite :: putchar
#endif
namespace Fastio {
struct Reader {
    template<typename T>
    Reader& operator >> (T& x) {
        char c = getchar();
        T f = 1;
        while (c < '0' || c > '9') {
            if (c == '-') f = -1;
            c = getchar();
        }
        x = 0;
        while (c >= '0' && c <= '9') {
            x = x * 10 + (c - '0');
            c = getchar();
        }
        x *= f;
        return *this;
    }
    Reader& operator >> (char& c) {
        c = getchar();
        while (c == ' ' || c == '\n') c = getchar();
        return *this;
    }
    Reader& operator >> (char* str) {
        int len = 0;
        char c = getchar();
        while (c == ' ' || c == '\n') c = getchar();
        while (c != ' ' && c != '\n' && c != '\r') { // \r\n in windows
            str[len++] = c;
            c = getchar();
        }
        str[len] = '\0';
        return *this;
    }
    Reader(){}
} cin;
const char endl = '\n';
struct Writer {
    template<typename T>
    Writer& operator << (T x) {
        if (x == 0) { putchar('0'); return *this; }
        if (x < 0) { putchar('-'); x = -x; }
        static int sta[45];
        int top = 0;
        while (x) { sta[++top] = x % 10; x /= 10; }
        while (top) { putchar(sta[top] + '0'); --top; }
        return *this;
    }
    Writer& operator << (char c) {
        putchar(c);
        return *this;
    }
    Writer& operator << (char* str) {
        int cur = 0;
        while (str[cur]) putchar(str[cur++]);
        return *this;
    }
    Writer& operator << (const char* str) {
        int cur = 0;
        while (str[cur]) putchar(str[cur++]);
        return *this;
    }
    Writer(){}
} cout;
}
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
int main(){
  #ifdef ONLINE_JUDGE
  #else
  freopen(".in","r",stdin);
  freopen(".out","w",stdout);
  #endif
  int n=read(),m,q;
  m=read();
  q=read();
  for(int i=1;i<=n;i++){
    cin>>(temp[i]+1);
  }
  for(int i=1;i<=501;i++){
    for(int j=1;j<=501;j++){
      if(temp[i][j]=='R'){
        R[i][j]=1;
      }else if(temp[i][j]=='G'){
        G[i][j]=1;
      }else if(temp[i][j]=='Y'){
        Y[i][j]=1;
      }else if(temp[i][j]=='B'){
        B[i][j]=1;
      }
      R[i][j]+=R[i-1][j]+R[i][j-1]-R[i-1][j-1];
      B[i][j]+=B[i-1][j]+B[i][j-1]-B[i-1][j-1];
      Y[i][j]+=Y[i-1][j]+Y[i][j-1]-Y[i-1][j-1];
      G[i][j]+=G[i-1][j]+G[i][j-1]-G[i-1][j-1];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(temp[i][j]!='R'){
        continue;
      }
      int l=1,r=std::min(i,std::min(n-i,std::min(j,m-j)));
      while(r-l>3){
        int mid=(l+r)/2;
        if(ans(R,(i-mid+1),(j-mid+1),i,j)!=mid*mid){
          goto end;
        }
        if(ans(G,(i-mid+1),(j+1),i,j+mid)!=mid*mid){
          goto end;
        }
        if(ans(Y,(i+1),(j-mid+1),i+mid,j)!=mid*mid){
          goto end;
        }
        if(ans(B,(i+1),(j+1),i+mid,j+mid)!=mid*mid){
          goto end;
        }
        goto suc;
        end:{}
        r=mid+1;
        break;
        suc:{}
        l=mid-1;
      }
      for(int ii=r;ii>=l;ii--){
        int mid=ii;
        if(ans(R,(i-mid+1),(j-mid+1),i,j)!=mid*mid){
          goto end2;
        }
        if(ans(G,(i-mid+1),(j+1),i,j+mid)!=mid*mid){
          goto end2;
        }
        if(ans(Y,(i+1),(j-mid+1),i+mid,j)!=mid*mid){
          goto end2;
        }
        if(ans(B,(i+1),(j+1),i+mid,j+mid)!=mid*mid){
          goto end2;
        }
        goto suc2;
        end2:{}
        continue;
        suc2:{}
        val[ii][i][j]=1;
        break;
      }
    }
  }
  for(int ii=0;ii<=std::max(n/2+1,m/2+1);ii++){
    for(int i=1;i<=501;i++){
      for(int j=1;j<=501;j++){
        val[ii][i][j]+=val[ii][i-1][j]+val[ii][i][j-1]-val[ii][i-1][j-1];
      }
    }
  }
  for(int ii=std::max(n/2+1,m/2+1);ii>=0;ii--){
    for(int i=1;i<=501;i++){
      for(int j=1;j<=501;j++){
        val[ii][i][j]+=val[ii+1][i][j];
      }
    }
  }
  for(int i=1;i<=q;i++){
    int l1;
    int r1;
    int l2;
    int r2;
    cin>>l1>>r1>>l2>>r2;
    int l=0,r=n;
    for(int ii=r;ii>=l;ii--){
      int mid=ii;
      if(ii==0){
        goto suc4;
      }
      if(l1+mid-1>l2-mid||r1+mid-1>r2-mid){
        continue;
      }
//      for(int iii=l1+mid-1;iii<=l2-mid;iii++)
      if(val[ii][l2-mid][r2-mid]-val[ii][l2-mid][r1+mid-2]-val[ii][l1+mid-2][r2-mid]+val[ii][l1+mid-2][r1+mid-2]){
        goto suc4;
      }
      end4:{}
      continue;
      suc4:{}
      cout<<ii*ii*4<<endl;
      break;
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


