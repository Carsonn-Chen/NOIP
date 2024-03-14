#include <bits/stdc++.h>

using namespace std;

int num[40][40];

int main(){
	int n;
	int r,l;
	scanf("%d",&n);
	r = 1;
	l = (n+1)/2;
	for(int i = 1;i <= n*n;i ++){
		num[r][l] = i;
		if(i % n){
			r --;
			l ++;
			if(r == 0)
				r = n;
			if(l == n+1)
				l = 1;
		}
		else
			r ++;
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++)
			printf("%d ",num[i][j]);
		printf("\n");
	}
	return 0;
}
