#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define mod 1073741824

using namespace std;

int f[55];
bool num[2005];

/*bool pd(int x){
	for(ri i = 2;i*i <= x;i ++)
		if(x % i == 0)
			return false;
	return true;
}*/

int main(){
	int n;
	scanf("%d",&n);
	f[1] = 1;
	f[2] = 1;
	for(ri i = 3;i <= n;i ++)
		f[i] = (f[i-1]+f[i-2]) % mod;
	printf("%d=",f[n]);
	/*for(ri i = 2;i <= 2000;i ++)
		if(!pd(i))
			num[i] = 1;
	while(f[n] > 1){
		for(ri i = 2;i <= 2000;i ++){
			if(!num[i] && f[n] % i == 0){
				f[n] /= i;
				if(f[n] != 1)
					printf("%d*",i);
				else
					printf("%d",i);
				break;
			}
		}
	}*/
	while(f[n] > 1){
		for(ri i = 2;i <= f[n];i ++){
			if(f[n] % i == 0){
				f[n] /= i;
				if(f[n] != 1)
					printf("%d*",i);
				else
					printf("%d",i);
				break;
			}
		}
	}
	return 0;
}
