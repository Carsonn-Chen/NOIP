#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#define ri register int

using namespace std;

int main() {
	int n, m;
	while(scanf("%d%d",&n,&m) == 2) {
		int ans = 0;
		for(ri i = 1; i <= n;i ++) {
			bool flag = 0;
			for(ri j = 1; j <= m;j ++) {
				char e;
				cin >> e;
				if(e == '/' || e == '\\'){
					ans ++;
					flag ^= 1;
				}
				if(e == '.' && flag)
					ans += 2;
			}
		}
		cout << ans / 2 << endl;
	}
	return 0;
}
