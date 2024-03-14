#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int tree[500005],a[500005];
int n,m;

int lowbit(int x){
	return x & -x;
}

void add(int x,int k){
	for(;x <= n;x += lowbit(x))
		tree[x] += k;
}

int sum(int x){
	int ans = 0;
	for(;x > 0;x -= lowbit(x))
		ans += tree[x];
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int b,c,d;
	int last = 0;
	for(ri i = 1;i <= n;i ++){
		cin >> a[i];
		add(i,a[i]-a[i-1]);
	}
	int t;
	for(ri i = 1;i <= m;i ++){
		cin >> t;
		if(t == 1){
			cin >> b >> c >> d;
			add(b,d);
			add(c+1,-d);
		}
		else if(t == 2){
			cin >> b;
			printf("%d\n",sum(b));
		}
	}
	return 0;
}
