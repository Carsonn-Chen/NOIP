#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define maxn 1000005
#define ri register int

using namespace std;

int tree[maxn], tmp[maxn], q[maxn][3], N, a[maxn], n, M;

inline int Find(int x) {
	return lower_bound(tmp+1,tmp+n+1,x)-tmp;
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

int main() {
	scanf("%d%d",&N,&M);
	for(ri i = 1; i <= N; i ++)
		scanf("%d",a+i),tmp[++n] = a[i];
	for(ri i = 1; i <= M; i ++) {
		scanf("%d%d",q[i],q[i]+1);
		if(q[i][0] == 2)
			scanf("%d",q[i]+2),tmp[++n] = q[i][2];
		tmp[++n] = q[i][1];
	}
	sort(tmp+1,tmp+n+1);
	for(ri i = 1; i <= N; i ++)
		add(a[i] = Find(a[i]),1);
	for(ri i = 2; i <= N; i ++)
		add(min(a[i],a[i-1]),-1);
	for(ri i = 1; i <= M; i ++) {
		if(q[i][0] == 1) {
			printf("%d\n",1-sum(Find(q[i][1])-1));
		} else {
			q[i][2] = Find(q[i][2]);
			add(a[q[i][1]],-1);
			add(q[i][2],+1);
			if(q[i][1] != 1){
				add(min(a[q[i][1]],a[q[i][1]-1]),+1);
				add(min(q[i][2],a[q[i][1]-1]),-1);
			}
			if(q[i][1] != N){
				add(min(a[q[i][1]],a[q[i][1]+1]),+1);
				add(min(q[i][2],a[q[i][1]+1]),-1);
			}
			a[q[i][1]] = q[i][2];
		}
	}
	return 0;
}

