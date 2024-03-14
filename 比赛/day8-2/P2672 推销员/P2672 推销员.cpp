#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int dis[100005],v[100005];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(ri i = 1;i <= n;i ++)
		cin >> dis[i];
	for(ri i = 1;i <= n;i ++)
		cin >> v[i];
	sort(v+1,v+n);
	long long ans = 2*dis[n] + v[n];
	cout << ans << endl;
	for(ri i = n-1;i >= 1;i --){
		ans += v[i];
		cout << ans << endl;
	}
	return 0;
}
