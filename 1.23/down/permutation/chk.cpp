#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define mp make_pair
#define ff first
#define ss second
#define score(x) fscore<<x<<endl
#define maxn 100005

int n,m;
int a[maxn],pos[maxn];

inline int read(){
    int x=0,f=1; char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}

int main(int argc,char *argv[])
{
	registerTestlibCmd(argc, argv);

	//FILE *fin=fopen(argv[1],"r");
    //FILE *fout=fopen(argv[2],"r");
    //FILE *fstd=fopen(argv[3],"r");
	//ofstream fscore; fscore.open(argv[5]);
	//int AC=atoi(argv[4]),WA=0;
    n=inf.readInt();
    m=inf.readInt();
	//fscanf(fin,"%d%d",&n,&m);
	for (int i=1;i<=n;i++){
        a[i]=ouf.readInt();
		if (a[i]<1||a[i]>n)quitf(_wa,"ai not in [1,n]");//{score(WA); return 0;}
	}
	for (int i=1;i<=n;i++) pos[a[i]]=i;
	for (int i=1;i<=n;i++) if (!pos[i])quitf(_wa,"pos wrong");//{score(WA); return 0;}
	int cnt=0;
	for (int i=1;i<=m;i++){
		int x,y,z;
        x=inf.readInt();
        y=inf.readInt();
        z=inf.readInt();
        //fscanf(fin,"%d%d%d",&x,&y,&z);
		if (pos[z]>pos[y]&&pos[y]>pos[x]) ++cnt;
		if (pos[z]<pos[y]&&pos[y]<pos[x]) ++cnt;
	}
	if (cnt*2<m) quitf(_wa,"number wrong"); else quitf(_ok,"correct");
    return 0;
}
