#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int f[1000005];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(ri i = 1;i <= n;i ++)
		f[i] = 1;
	for(ri i = 2;i <= n;i ++)
		for(ri j = i;j <= n;j += i)
			f[j] ++;
	long long ans = 0;
	for(ri i = 1;i <= n;i ++)
		ans += f[i];
	cout << ans << endl;
	return 0;
}
