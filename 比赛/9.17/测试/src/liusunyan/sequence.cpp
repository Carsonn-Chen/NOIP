#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define SIZE 100005
long long a[SIZE];
struct Node{
    int r,l;
    long long sum;
    #define r(x) t[x].r
    #define l(x) t[x].l
    #define sum(x) t[x].sum
    #define add(x) t[x].add
}t[SIZE<<2];

void build(int p,int l,int r)
{
    l(p) = l,r(p) = r;
    if(l == r) {sum(p) = a[l];return;}
    int mid = (l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    sum(p) = max(sum(p*2),sum(p*2+1));
}


long long ask(int p,int l,int r)
{
    if(l <= l(p) && r >= r(p)) return sum(p);
    int mid = (l(p)+r(p))/2;
    long long val = 0;
    if(l <= mid) val = max(ask(p*2,l,r),val);
    if(r > mid) val = max(ask(p*2+1,l,r),val);
    return val;
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    memset(t,0,sizeof(t));
    memset(a,0,sizeof(a));
    int N;
    cin >> N;
    for(int i = 1;i <= N;i ++) cin >> a[i];
    build(1,1,N);
    long long ans = 0;
    cout << ask(1,1,4);
    for(int l = 1;l <= N;l ++) {
    	long long ans1 = 0;
    	for(int r = l;r <= N;r ++) {
    		ans1 += ask(1,l,r); // log
    	}
    	ans += ans1;
    }
    cout << ans;
    return 0;
}
