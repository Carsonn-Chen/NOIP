#include <bits/stdc++.h>

using namespace std;

int main(){
	int m,n,k;
	int ans;
	while(cin >> m >> n >> k){
		ans = 1;
		for(;n;n>>=1,m = (long long)m*m%k)
			if(n&1)
				ans = (long long)ans*m%k;
		cout << ans << endl;
	}
	return 0;
}
