#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int n;
int h[100005];
int ans = 0;

int read(){
	int sum = 0;
	char e = getchar();
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e))
		sum = sum*10 + (e&15),e = getchar();
	return sum;
}

void calc(int l,int r){
	ans ++;
	for(ri i = l;i <= r;i ++)
		h[i] --;
	for(ri i = l;i <= r+1;i ++){
		if(h[i] == 0){
			if(i-1 >= l)
				calc(l,i-1);
			l = i + 1;
		}
	}
}

int main(){
	n = read();
	for(ri i = 1;i <= n;i ++)
		h[i] = read();
	int l = 1;
	for(ri i = l;i <= n+1;i ++){
		if(h[i] == 0){
			calc(l,i-1);
			l = i + 1;
		}
	}
	printf("%d",ans);
	return 0;
}
