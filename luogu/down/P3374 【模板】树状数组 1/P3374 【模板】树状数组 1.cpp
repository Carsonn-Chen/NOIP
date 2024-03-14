#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int tree[500005];
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
	for(;x != 0;x -= lowbit(x))
		ans += tree[x];
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int a,b,c;
	for(ri i = 1;i <= n;i ++){
		cin >> a;
		add(i,a);
	}
	for(ri i = 1;i <= m;i ++){
		cin >> a >> b >> c;
		if(a == 1)
			add(b,c);
		if(a == 2)
			printf("%d\n",sum(c)-sum(b-1));
	}
	return 0;
}
