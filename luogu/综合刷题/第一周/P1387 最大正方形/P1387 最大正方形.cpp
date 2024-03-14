#include <bits/stdc++.h>

using namespace std;

int a[105][105];

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			cin >> a[i][j];
	int Max = 0;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			if(a[i][j] == 0)
				continue;
			a[i][j] += min(min(a[i-1][j],a[i-1][j-1]),a[i][j-1]);
			Max = max(Max,a[i][j]);
		}
	}
	cout << Max;
	return 0;
}
