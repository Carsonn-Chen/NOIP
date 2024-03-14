#include <bits/stdc++.h>

using namespace std;

int tim[105],v[105];
int f[1005];

int main(){
	int t,m;
	cin >> t >> m;
	for(int i = 1;i <= m;i ++)
		cin >> tim[i] >> v[i];
	for(int i = 1;i <= m;i ++)
		for(int j = t;j >= tim[i];j --)
			f[j] = max(f[j],f[j-tim[i]]+v[i]);
	cout << f[t];
	return 0;
}
