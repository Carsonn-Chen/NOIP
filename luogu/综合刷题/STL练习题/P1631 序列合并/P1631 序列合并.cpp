#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define ri register int

using namespace std;

int a[100005], b[100005], to[100005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;

int main() {
	int n;
	scanf("%d", &n);
	for (ri i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (ri i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		to[i] = 1;
		q.push(pair<int, int>(a[1] + b[i], i));
	}
	while(n--) {
		printf("%d ", q.top().first);
		int x = q.top().second;
		q.pop();
		q.push(pair<int, int>(a[++to[x]] + b[x], x));
	}
	return 0;
}
