#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int 

using namespace std;

int k,n;
long long ans;

int main(){
	ios::sync_with_stdio(false);
	cin >> k >> n;
	long long cnt = 1;
	while(n){
		if(n & 1)
			ans += cnt;
		cnt *= k;
		n >>= 1;
	}
	cout << ans << endl;
	return 0;
}
