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
	for(ri t = 1; t * 9 < n; t++) { //ö��t
		int sum = 0;
		int va,vb,vc,vd;
		for(vd = t * 9 + 2; vd <= n; vd++){					//ö��d��λ��
			va = vd - 9 * t - 1;							//a��ħ��ֵ
			vb = vd - 7 * t - 1;							//b��ħ��ֵ
			vc = vd - t;									//c��ħ��ֵ
			sum += num[vb] * num[va];						//������ɵ�ħ����ĸ���
			c[vc] += num[vd] * sum;
			d[vd] += num[vc] * sum;
		}
		sum = 0;
		for(va = n - t * 9 - 1; va >= 1; va--){				//ö��a��λ��
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
