#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
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
int s[100005][2];
int sum[100005][2];

int main(){
	n = read(),m = read();
	for(ri i = 1;i <= n;i ++)
		num[i] = read();
	for(ri i = 1;i <= n;i ++){
		col[i] = read();
		s[col[i]][i%2] ++;
        sum[col[i]][i%2] = (sum[col[i]][i%2] + num[i])%10007;
	}
	int ans = 0;
	for(ri i = 1;i <= n;i ++)
        ans = (ans + i*( (s[col[i]][i%2] - 2 ) * num[i] % 10007 + sum[col[i]][i%2])) % 10007;
	write(ans);
}
