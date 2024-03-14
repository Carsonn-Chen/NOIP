#include <bits/stdc++.h>

using namespace std;

int v[35];
int f[20005];

int main(){
	int space,n;
	cin >> space >> n;
	for(int i = 1;i <= n;i ++)
		cin >> v[i];
	for(int i = 1;i <= n;i ++)
		for(int j = space;j >= v[i];j --)
			f[j] = max(f[j],f[j-v[i]]+v[i]);
	cout << space-f[space];
	return 0;
}
