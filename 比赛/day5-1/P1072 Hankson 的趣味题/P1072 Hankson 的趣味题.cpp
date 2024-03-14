#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#define ri register int

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long a0,a1,b0,b1;
	while(n --){
		cin >> a0 >> a1 >> b0 >> b1;
		int ans = 0;
		for(long long  i = 1;i*i<= b1;i ++){
			if(b1 % i == 0){
				if((i * b0 / __gcd(i,b0)) == b1 && __gcd(a0,i) == a1)
					ans ++;
				if(b1 / i != i){
					if(__gcd(b1 / i,a0) == a1 && ((b1 / i) * b0 / __gcd((b1 / i),b0)) == b1)
						ans ++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
