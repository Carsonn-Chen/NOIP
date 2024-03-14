#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int f[1005];
int w[1005];

int main(){
	ios::sync_with_stdio(false);
	int n = 1;
	int tag[7] = {0,1,2,3,5,10,20};
	int sum = 0;
	for(ri i = 1;i <= 6;i ++){
		int x;
		cin >> x;
		for(ri j = 1;j <= x;j ++)
			w[n++] = tag[i],sum += tag[i];
	}
	f[0] = 1;
	for(ri i = 1;i < n;i ++)
		for(ri j = sum;j >= w[i];j --)
			f[j] += f[j-w[i]];
	int cnt = 0;
	for(ri i = 1;i <= sum;i ++)
		if(f[i] != 0)
			cnt ++;
	cout << "Total=" << cnt << endl;
	return 0;
}
