#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int main(){
	int n,x,y;
	cin >> n >> x >> y;
	int k = min(min(n - y + 1 , y) , min(n - x + 1, x));
	int s = n * n - (n-(k-1)*2) * (n-(k-1)*2) + 1;
	int ans = s;
	if(x == k)
		cout << ans + y-(k-1)-1;
	else if(x == n-(k-1))
		cout << ans + (n-(k-1)*2)*2-2 + n-(k-1)-y;
	else if(y == k)
		cout << ans + (n-(k-1)*2)*3-3 + n-(k-1)-x;
	else
		cout << ans + n-(k-1)*2-1 + x - (k-1)-1;
	return 0;
}
