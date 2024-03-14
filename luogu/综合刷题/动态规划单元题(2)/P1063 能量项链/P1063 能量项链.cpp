#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int num[250];

long long f[250][250];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int Max = 0;
	for(ri i = 1;i <= n;i ++)
		cin >> num[i],num[i+n] = num[i];
	for(ri i = 2;i < 2*n;i ++)
		for(ri j  = i-1;j >= 1 && i-j < n;j --)
			for(ri k = j;k < i;k ++){
				f[j][i] = max(f[j][i],f[j][k]+f[k+1][i]+num[j]*num[k+1]*num[i+1]);
				if(Max < f[j][i])
					Max = f[j][i];
			}
	cout << Max << endl;
	return 0;
}
