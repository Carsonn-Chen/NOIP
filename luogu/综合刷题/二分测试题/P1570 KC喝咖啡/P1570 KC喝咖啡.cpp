#include<cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int n,m;

struct node {
	int v,c;
	double div;
} a[1000];

bool cmp(node a,node b) {
	return a.div > b.div;
}

bool check(double x) {
	for(int i = 1; i <= n; i ++)
		a[i].div = a[i].v-x*a[i].c;
	sort(a+1,a+n+1,cmp);
	double tot = 0;
	for(int i = 1; i <= m; i ++)
		tot += a[i].div;
	return tot >= 0;
}

int main() {
	scanf("%d%d",&n,&m);
	double l = 0,r,mid;
	for(int i = 1; i <= n; i ++)
		scanf("%d",&a[i].v);
	for(int i = 1; i<=n ; i ++)
		scanf("%d",&a[i].c),r=r<a[i].v*1.0/a[i].c?a[i].v*1.0/a[i].c:r;
	while(r-l > 1e-6) {
		mid = (l+r)/2;
		if(check(mid))
			l = mid;
		else 
			r = mid;
	}
	printf("%.3lf",l);
	return 0;
}
