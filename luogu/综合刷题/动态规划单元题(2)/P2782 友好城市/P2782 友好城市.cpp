#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

const int maxn = 2e5+5;

struct node{
	int n,s;
}inf[maxn];
int pos[maxn];
int f[maxn];

bool cmp(node a,node b){
	if(a.n == b.n)
		return a.s < b.s;
	return a.n < b.n;
}

int main(){
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for(ri i = 1;i <= N;i ++)
		 cin >> inf[i].n >> inf[i].s;
	sort(inf+1,inf+1+N,cmp);
	memset(f,0x3f,sizeof(f));
	for(ri i = 1;i <= N;i ++){
		int x = inf[i].s;
		*lower_bound(f+1,f+1+N,x) = x;
	}
	printf("%d\n",lower_bound(f+1,f+N+1,f[0])-f-1);
	return 0;
}
