#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define ri register int

using namespace std;

int n,k,sum[10001],num=1,f[10001];

struct node {
	int begin,end;
} inf[10001];

bool cmp(node a,node b)  {
	return a.begin > b.begin;
}

int main() {
	cin>>n>>k;
	for(ri i = 1; i <= k; i ++) {
		cin >> inf[i].begin >> inf[i].end;
		sum[inf[i].begin] ++;
	}
	sort(inf+1,inf+k+1,cmp);
	for(ri i = n; i >= 1; i --) {
		if(sum[i] == 0)
			f[i] = f[i+1]+1;
		else 
			for(ri j = 1; j <= sum[i]; j ++){
				if(f[i+inf[num].end] > f[i])
					f[i] = f[i+inf[num].end];
				num ++;
			}
	}
	cout<<f[1]<<endl;
}
