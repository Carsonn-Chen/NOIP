#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int read(){
	int sum = 0;
	char e = getchar();
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e))
		sum = sum*10 + (e&15),e = getchar();
	return sum;
}

int n;
int h[100005];

int main(){
	int ans = 0;
	n = read();
	for(ri i = 1;i <= n;i ++){
	    h[i+1] = -read();
		h[i] -= h[i+1];
		ans += max(h[i],0);
	}
	cout << ans;
}
