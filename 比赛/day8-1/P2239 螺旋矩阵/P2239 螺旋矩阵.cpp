#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int f[10000][10000];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int val = 1;
	for(int x = 0;x < (n+1)/2;x ++){
		for(ri y = x;y < n-x;y ++)
			f[x][y] = val++;
		for(ri y = x+1;y < n-x;y ++)
			f[y][n-x-1] = val++;
		for(ri y = n-x-2;y >= x;y --)
			f[n-x-1][y] = val++;
		for(ri y = n-x-2;y > x;y --)
			f[y][x] = val++;
	}
	int a,b;
	cin >> a >> b;
	cout << f[a-1][b-1];
	return 0;
}
