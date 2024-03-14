#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+5;
int num[maxn],temp[maxn];
long long ans = 0;

void solve(int begin,int end){
	if(end-begin > 1){
		int m = (begin+end)/2;
		int p = begin,q = m,i = begin;
		solve(p,m);
		solve(q,end);
		while(p < m || q < end){
			if(q >= end || (p < m && num[p] <= num[q]))
				temp[i++] = num[p++];
			else{
				temp[i++] = num[q++];
				ans = ans + m - p;
			}
		}
		for(i = begin;i < end;i ++)
			num[i] = temp[i];
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&num[i]);
	solve(1,n+1);
	printf("%lld\n",ans);
}
