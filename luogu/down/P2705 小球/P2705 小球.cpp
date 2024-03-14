#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int 

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	long long r,b,c,d,e;
	long long ans = 0;
	cin >> r >> b >> c >> d >> e;
	ans = r*c + b*d;
	if(r > b)
		ans = max(ans,2*b*e + (r-b)*c);
	else
		ans = max(ans,2*r*e + (b-r)*d);
	cout << ans << endl;
	return 0;
}
