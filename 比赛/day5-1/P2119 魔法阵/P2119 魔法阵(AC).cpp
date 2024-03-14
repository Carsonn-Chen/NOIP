#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int n,m;
int v[40005],num[15005];
int a[15005],b[15005],c[15005],d[15005];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(ri i = 1; i <= m; i ++) {
		cin >> v[i];
		num[v[i]] ++;
	}
	for(ri t = 1; t * 9 < n; t++) { //枚举t
		int sum = 0;
		int va,vb,vc,vd;
		for(vd = t * 9 + 2; vd <= n; vd++){					//枚举d的位置
			va = vd - 9 * t - 1;							//a的魔法值
			vb = vd - 7 * t - 1;							//b的魔法值
			vc = vd - t;									//c的魔法值
			sum += num[vb] * num[va];						//求能组成的魔法阵的个数
			c[vc] += num[vd] * sum;
			d[vd] += num[vc] * sum;
		}
		sum = 0;
		for(va = n - t * 9 - 1; va >= 1; va--){				//枚举a的位置
			vb = va + 2 * t;
			vc = va + t * 8 + 1;
			vd = va + t * 9 + 1;
			sum += num[vc] * num[vd];
			a[va] += num[vb] * sum;
			b[vb] += num[va] * sum;
		}
	}
	for(ri i = 1; i <= m; i++)
		printf("%d %d %d %d\n", a[v[i]],b[v[i]],c[v[i]],d[v[i]]);
}
