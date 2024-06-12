#include<bits/stdc++.h>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE __int128_t
#define OUTPUT_DATA_TYPE __int128_t
inline __attribute((always_inline)) INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){if(x<0)x=-x,putchar('-');if(x>9)print(x/10);putchar(x%10^48);return;}

__int128_t p1,p2;
__int128_t base1,base2;

struct NODE{
	__int128_t val1,val2;
	bool operator < (const NODE o) const{
		// return val1+val2<o.val1+o.val2;
		if(std::min(val1,p1-val1)==std::min(o.val1,p1-o.val1)) return std::min(val2,p2-val2)<std::min(o.val2,p2-o.val2);
		return std::min(val1,p1-val1)<std::min(o.val1,p1-o.val1);
	}
	NODE operator + (const NODE o) const{
		__int128_t a=val1+o.val1;
		__int128_t b=val2+o.val2;
		if(a>=p1) a-=p1;
		if(b>=p2) b-=p2;
		return {a,b};
	}
	NODE operator - (const NODE o) const{
		__int128_t a=val1-o.val1+p1;
		__int128_t b=val2-o.val2+p2;
		if(a>=p1) a-=p1;
		if(b>=p2) b-=p2;
		return {a,b};
	}
};


int A[1000010];
__int128_t W1[1000010],W2[1000010];
std::pair<NODE,std::pair<int,int>> S[1000010];
int lC[2000010],rC[2000010],n;
std::vector<int> tree;

void dfs(int u,int val){
	if(u<n) return A[u]=val,void();
	dfs(lC[u],val),dfs(rC[u],val);
}

__int128_t zero(__int128_t x){
	x%=p1;
	return std::min(x,p1-x);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	std::mt19937 mt(time(0));

    register int i,len,now,pos,op,ttt=0,cnt,flg,l,r,a,b,cntHack=0;
    register NODE val,chk={0,0};

	fprintf(stderr,"p1:\n");p1=read();
	fprintf(stderr,"base1:\n");base1=read();
	fprintf(stderr,"p2:\n");p2=read();
	fprintf(stderr,"base2:\n");base2=read();
    fprintf(stderr,"x:\n");__int128_t x=read();
  fprintf(stderr,"x2:\n");__int128_t x2=read();

    
    fprintf(stderr,"bias:\n");int bias=read();
    fprintf(stderr,"rev:\n");int rev=read();
	
    fprintf(stderr,"k:\n");int k=read();
	fprintf(stderr,"ops:\n");long long ops=read();
	fprintf(stderr,"mtree:\n");int mtree=read();

    n=1<<k;

	for(i=W1[0]=W2[0]=1;i<=n;++i) W1[i]=W1[i-1]*base1%p1,W2[i]=W2[i-1]*base2%p2;
    for(i=0;i<n;++i)
        chk=chk+(NODE){W1[i+bias]*'d',W2[i+bias]*'d'};
    
    chk=chk+(NODE){p1-x%p1,p2-x2%p2};

	while(1){

		for(i=0;i<n;++i) S[i]={{W1[i+bias],W2[i+bias]},{i,0}},A[i]=0;
		S[0].first=S[0].first+chk;
		S[0].second.second=1;

		cnt=n;

		for(now=0;now<k;++now){
			len=1<<now;
			// if(now>=mtree)
			std::sort(S,S+(n/len));
			for(l=pos=0,r=n/len;l<r;++pos){
				op=0;
				if(mt()%1000'000'000<ops) op=1;
				if(now<mtree) op=0;
				if(op){
					a=l,b=--r;
					l+=1;
				}else{
					a=l,b=l+1;
					l+=2;
				}
				flg=S[a].second.second+S[b].second.second;
				val=S[a].first+S[b].first,lC[cnt]=S[a].second.first,rC[cnt]=S[b].second.first;
				S[pos]={val,{cnt,flg}};
				if(flg&&val.val1%p1==0&&val.val2%p2==0){
					dfs(cnt,1);
                    printf("%d\n",1);
                    if(rev) for(i=n-1;~i;--i) putchar('d'+A[i]);
                    else for(i=0;i<n;++i) putchar('d'+A[i]);
                    return 0;

					++cntHack;
				}
				++cnt;
			}
		}

		// ++ops;
	}


	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
