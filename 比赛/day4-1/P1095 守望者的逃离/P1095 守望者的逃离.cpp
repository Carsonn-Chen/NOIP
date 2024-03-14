#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int m,s,t;

/*int main(){
	ios::sync_with_stdio(false);
	cin >> m >> s >> t;
	while(m - 10 >= 0){
		ss += 60;
		tt += 1;
		m -= 10;
	}
	while(s - ss >= 120){
		if(m - 10 >= 0){
			ss += 60;
			tt += 1;
			m -= 10;
		}else{
			m += 4;
			tt += 1;
		}
	}
	if(s -ss <= 0){
		cout << "Yes" << endl;
		cout << tt << endl;
	}
	int t1;
	if((s - ss) % 17 == 0)
		t1 = (s - ss) / 17;
	else
		t1 = (s - ss) / 17 + 1;
	int t2 = 0;
	int s2 = 0;
	int s3 = 0;
	while(s2 + ss < s){
		if(m - 10 >= 0){
			s2 += 60;
			if(t2 + tt < t)
				s3 += 60;
			m -= 10;
			t2 ++;
		}else{
			m += 4;
			t2 ++;
		}
	}
	if(tt + min(t2,t1) >= t){
		cout << "No" << endl;
		cout << ss + max(s3,(t-tt)*17) << endl;
	}else{
		cout << "Yes" << endl;
		cout << tt + min(t2,t1) << endl;
	}
	return 0;
}*/

int dp[300001];
int main() {
	scanf("%d%d%d",&m,&s,&t);
	for(ri i = 1;i <= t;i ++){
		if(m >= 10){
			dp[i] = dp[i-1] + 60;
			m -= 10;
		}
		else{
			dp[i] = dp[i-1];
			m += 4;
		}
	}
	for(ri i = 1;i <= t;i ++){
		dp[i] = max(dp[i],dp[i-1] + 17);
		if(dp[i] >= s) {
			printf("Yes\n%d",i);
			return 0;
		}
	}
	printf("No\n%d",dp[t]);
	return 0;
}
