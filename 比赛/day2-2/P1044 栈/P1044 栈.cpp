#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <iostream>
#define ri register int

using namespace std;

int main() {
	int n;
	cin >> n;
	long long a[25];
	a[1] = 1;
	for(ri i = 2;i <= n;i ++)
		a[i] = a[i-1]*(4*i-2)/(i+1);
	cout << a[n] << endl;
	return 0;
}
