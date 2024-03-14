#include <bits/stdc++.h>

using namespace std;

int tim[10005],v[10005];
int f[100005];

int main(){
	int t,m;
	cin >> t >> m;
	for(int i = 1;i <= m;i ++)
		cin >> tim[i] >> v[i];
	for(int i = 1;i <= m;i ++)
		for(int j = tim[i];j <= t;j ++)
			f[j] = max(f[j],f[j-tim[i]]+v[i]);
	cout << f[t];
	return 0;
}
