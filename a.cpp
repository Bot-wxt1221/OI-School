#include<bits/stdc++.h>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE long long
inline __attribute((always_inline)) INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){if(x<0)x=-x,putchar('-');if(x>9)print(x/10);putchar(x%10^48);return;}

int arr[1000010],smax[1000010];

#define lC ((p)<<1)
#define rC (lC|1)
#define getMid int mid=(((l)+(r))>>1)

const int SGT_SIZE=1000010;

struct SGT_NODE{
    long long data,mintag;
    SGT_NODE(){
        data=0;
        return;
    }
};

std::vector<long long> vec;

struct SGT_TREE{
    SGT_NODE tree[SGT_SIZE<<2];
    int L,R;
    void downAdd(int p,long long tag){tree[p].data+=tag,tree[p].mintag+=tag;}
    void downMin(int p,long long tag){
        // tag-=tree[p].data;
        if(tag<tree[p].mintag) tree[p].mintag=tag;
    }
    void pushdown(int p){
        
        downAdd(lC,tree[p].data),downAdd(rC,tree[p].data),tree[p].data=0;
        downMin(lC,tree[p].mintag),downMin(rC,tree[p].mintag),tree[p].mintag=0x3f3f3f3f3f3f3f3f;
        return;
    }
    void build(int p,int l,int r){
        tree[p].mintag=0x3f3f3f3f3f3f3f3fll;
        if(l==r) return (void)(tree[p].mintag=smax[1]);
        getMid;
        build(lC,l,mid);
        build(rC,mid+1,r);
        return;
    }
    void modify(int p,int l,int r,int s,int t,long long tag){
        if(s<=l&&r<=t) return downAdd(p,tag);
        getMid;
        pushdown(p);
        if(s<=mid) modify(lC,l,mid,s,t,tag);
        if(mid<t) modify(rC,mid+1,r,s,t,tag);
        return;
    }
    long long query(int p,int l,int r){
        if(l==r) return tree[p].mintag;
        getMid;
        pushdown(p);
        return query(lC,l,mid)+query(rC,mid+1,r);
    }
    void build(int l,int r){
        L=l,R=r;
        return build(1,L,R);
    }
    void modify(int s,int t,long long tag){return modify(1,L,R,s,t,tag);}
    long long query(){return query(1,L,R);}
}sgt;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	#endif

    register int i;
    register long long sum=0;
    int n=read();
    for(i=1;i<=n;++i) sum+=(arr[i]=read()),vec.push_back(arr[i]);
    // std::sort(vec)
    for(i=n;i;--i) smax[i]=std::max(smax[i+1],arr[i]);

    sgt.build(1,n);
    sgt.query();

    for(i=1;i<=n;++i){
        if(arr[i]) sgt.modify(1,arr[i],-1);
        sgt.downMin(1,smax[i+1]);
    }

    print(sum+sgt.query());

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
