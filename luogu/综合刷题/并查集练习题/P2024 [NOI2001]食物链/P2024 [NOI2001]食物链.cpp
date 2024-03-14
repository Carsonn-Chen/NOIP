#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

inline int read() {
	char c = getchar();
	int num = 0;
	for(; !isdigit(c); c=getchar());
	for(; isdigit(c); c=getchar())
		num = num*10+c-'0';
	return num;
}

int n,m,ans,fa[400000];

int find(int x) {
	if(x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

int main() {
	n = read(),m = read();
	for(ri i = 1; i <= n * 3; i++)
		fa[i] = i;
	for(ri i = m;i >= 1;i --) {
		int a = read(), b = read(), c = read();
		if (b > n || c > n) {
			ans++;
			continue;
		}
		if (a == 1) {
			if (find(b + n) == find(c) || find(b) == find(c + n)) {
				ans++;
			} else {
				fa[find(b)] = find(c);
				fa[find(b + n)] = find(c + n);
				fa[find(b + n + n)] = find(c + n + n);
			}
		} else {
			if (find(b) == find(c) || find(b) == find(c + n)) {
				ans++;
			} else {
				fa[find(b + n)] = find(c);
				fa[find(b + n + n)] = find(c + n);
				fa[find(b)] = find(c + n + n);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
