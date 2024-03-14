#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int phi[2005];

int gcd(int a,int b) {
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);
}

bool flag[2005];											//标记数组
int p[2005];												//素因子的值
int cnt = 0;
void Get_phi(){												//筛法求欧拉函数
	cnt = 0;
	memset(flag, 1, sizeof(flag));
	phi[1] = 1;
	for(ri i = 2; i <= 2000; i++) {							//线性筛法
		if(flag[i]) {										//素数
			p[++cnt] = i;
			phi[i] = i-1;									//素数的欧拉函数值是素数 - 1
		}
		for(ri j = 1; j <= cnt; j ++) {
			if(i*p[j] > 2000)
				break;
			flag[i*p[j]] = 0;								//素数的倍数，所以i*p[j]不是素数
			if(i%p[j] == 0) {								//性质：i mod p == 0, 那么 phi(i * p) == p * phi(i)
				phi[i*p[j]] = p[j] * phi[i];
				break;
			}
			else
				phi[i*p[j]] = (p[j]-1) * phi[i];			//i mod p != 0, 那么 phi(i * p) == phi(i) * (p-1)
		}
	}
}

int main() {
	phi[1] = 1;
	/*for(ri i = 2; i <= 2000; i ++)
		if(phi[i] == 0)
			for(ri j = i; j <= 2000; j +=i) {
				if(!phi[j])
					phi[j] = j;
					phi[j] = phi[j] / i*(i-1);
			}*/
	//Get_phi();
	int n,m;
	while(scanf("%d%d",&n,&m) == 2&&n&&m) {
		double sum = 0;
		for(ri i = 1; i <= n; i ++) {
			sum += phi[i] * (m/i);
			int mn = m%i;
			for(ri j = 1; j <= mn; j ++)
				if(gcd(j,i) == 1)
					sum += 1;
		}
		sum = sum*2+2;
		double sum2 = (unsigned long long)n*m*2+n+m;
		double ans = sum/sum2;
		printf("%.7lf\n",ans);
	}
	return 0;
}

