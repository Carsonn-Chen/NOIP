#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#define ri register int
#define mod 10007

using namespace std;

int n;
long long ans = 1;

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> n;
	for(ri i = 1;i <= n;i ++){
		char e;
		cin >> e;
		if(e == '+' || e == '*') 
			s += e;
	}
	for(ri i = 0;i < (int)s.size();i ++){
		if(s[i] == '*') {
			int k = 0;
			while(s[i] == '*'){
				k ++;
				i ++;
			}
			ans *= (1 << (k+1)) -1;
			ans %= mod;
		}
	}
	ans %= mod;
	cout << ans << endl;
}
