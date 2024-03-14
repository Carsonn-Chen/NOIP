#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define LL long long
#define ri register int
#define mod 1000000009

using namespace std;

int n;
int tree[100005];
LL sum[100005];
int f[100005];

struct node {
	LL sum;
	int p;
	bool operator < (const node &a) const {
		return sum < a.sum;
	}
}a[100005];

inline int read() {
	char c = getchar();
	int num = 0,f = 1;
	for(; !isdigit(c); c=getchar())
		if(c == '-')
			f = -1;
	for(; isdigit(c); c=getchar())
		num = num*10+c-'0';
	return num*f;
}

int lowbit(int x){
	return x & -x;
}

void add(int x,int k){
	for(;x <= n;x += lowbit(x))
		tree[x] = (tree[x]+k) % mod;
}

LL Sum(int x){
	LL ans = 0;
	for(;x;x -= lowbit(x))
		ans = (ans+tree[x]) % mod;
	return ans;
}

int main(){
	n = read();
	for(ri i = 1;i <= n;i ++){
		a[i].sum = (a[i-1].sum + read()) % mod;
		a[i].p = i;
	}
	a[n+1].sum = 0;
	a[n+1].p = n+1;
	sort(a+1,a+n+2);
	LL tmp = 0;
	for(ri i = 1;i <= n+1;i ++) {
		if (i == 1 || a[i].sum != a[i-1].sum)
			tmp ++;
		f[a[i].p] = tmp;
	}
	add(f[n+1],1);
	tmp = 0;
	for(ri i = 1;i <= n;i ++) {
		tmp = Sum(f[i]);
		add(f[i],tmp);
	}
	printf("%lld",tmp);
	return 0;
}
