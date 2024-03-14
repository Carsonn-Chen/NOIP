#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int m,n,hp,a[10],b[10];
int main(){
	freopen("ending.in","r",stdin);
	freopen("ending.out","w",stdout);
	int ta = 0, tb = 0; cin >> m >> n >> hp;
	for (int i = 1; i <= m; i ++) { cin >> b[i]; tb += b[i]; }
	for (int i = 1; i <= n; i ++) { cin >> a[i]; ta += a[i]; }
	if(ta <= tb) { cout << "No" << endl; return 0; }
	sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + m);
	do{
		int cur = 1;
		for (int i = 1; i <= n; i ++) {
			if(b[cur] <= 0) cur ++;
			b[cur] -= a[i];
			if(cur == m && i <= n) { cur = i; break; } 
		} ta = 0;
		for (int i = cur + 1; i <= n; i ++) ta += a[i];
		if(ta >= hp) { cout << "Yes" << endl; return 0; }
		else { cout << "No" << endl; return 0; }
	} while (next_permutation(a + 1, a + 1 + n));
	return 0;
}
