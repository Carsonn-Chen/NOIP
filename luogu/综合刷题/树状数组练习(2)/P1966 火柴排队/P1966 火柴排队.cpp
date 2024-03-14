#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define mod 99999997
#define LL long long
using namespace std;

int h1[100005],h2[100005];
int n;
int p1[100005],p2[100005];
int f[100005],tree[100005];

bool cmp1(int x,int y){
	return h1[x] < h1[y];
}

bool cmp2(int x,int y){
	return h2[x] < h2[y];
}

inline int lowbit(int x){
	return x & -x;
}

void add(int x,int k){
    for(;x <= n;x += lowbit(x))
        tree[x] += k;
}

int sum(int x){
    int ans = 0;
    for(;x;x -= lowbit(x))
        ans += tree[x];
    return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(ri i = 1;i <= n;i ++)
		cin >> h1[i],p1[i] = i;
	for(ri i = 1;i <= n;i ++)
		cin >> h2[i],p2[i] = i;
	sort(p1+1,p1+1+n,cmp1);
	sort(p2+1,p2+1+n,cmp2);
	for(ri i = 1;i <= n;i ++)	
		f[p1[i]] = p2[i];
	LL ans = 0;
	for(ri i = 1;i <= n;i ++){
		add(f[i],1);
		ans += i - sum(f[i]);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
