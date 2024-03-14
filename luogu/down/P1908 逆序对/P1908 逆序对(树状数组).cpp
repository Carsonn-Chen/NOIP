#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int read(){
	int summ = 0;
	char e = getchar();
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e)){
		summ = summ * 10 + e - '0';
		e = getchar();
	}
	return summ;
}

const int maxn = 5e5+5;
int n;
long long tree[maxn];
int num[maxn],disc[maxn];

inline int lowbit(int x){
	return x & -x;
}

void add(int x){
	for(;x <= n;x += lowbit(x))
		tree[x] ++;
}

long long getsum(int x){
	int sum = 0;
	for(;x;x -= lowbit(x))
		sum += tree[x];
	return sum;
}

int main(){
	n = read();
	for(ri i = 1;i <= n;i ++){
		num[i] = read();
		disc[i] = num[i];
	}
	long long ans = 0;
	sort(disc+1,disc+1+n);
	int end = unique(disc+1,disc+1+n) - (disc + 1);
	for(ri i = n;i >= 1;i --){
		int pos = lower_bound(disc + 1,disc + 1 + end,num[i]) - disc;
		add(pos);
		if(pos != 1)
			ans += getsum(pos-1);
	}
	printf("%lld\n",ans);
	return 0;
}
