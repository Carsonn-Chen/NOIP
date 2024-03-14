#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int 

using namespace std;

int sum[3005];

int main(){
	int n,m;
	cin >> n >> m;
	int a;
	for(ri i = 1;i <= n;i ++)
		cin >> a,sum[i] = sum[i-1] + a;
	int Min = 1e9;
	for(ri i = m;i <= n;i ++)
		Min = min(Min,sum[i] - sum[i-m]);
	cout << Min << endl;
	return 0;
}
