#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int
#define mod 10007

using namespace std;

int read(){
	int summ = 0,f = 1;
	char e = getchar();
	while(!isdigit(e)){
		if(e == '-')
			f = -1;
		e = getchar();
	}
	while(isdigit(e)){
		summ = summ*10 + e - '0';
		e = getchar();
	}
	return summ * f;
}

void write(int x){
    if(x > 9)
		write(x/10);
    putchar(x%10+'0');
}

int n,m;
int col[100005],num[100005];

int main(){
	n = read(),m = read();
	for(ri i = 1;i <= n;i ++)
		num[i] = read();
	for(ri i = 1;i <= n;i ++)
		col[i] = read();
	long long ans = 0;
	for(ri l = 1;l <= n;l ++)
		for(ri y = 1;y <= n;y ++){
			int x = y - l;
			int z = y + l;
			if(x < 1 || z > n || col[x] != col[z])
				continue;
			ans = (ans + (x+z) * (num[x] + num[z])) % mod;
		}
	write(ans);
	return 0;
}
