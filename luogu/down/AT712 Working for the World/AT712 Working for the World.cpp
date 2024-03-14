#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

bool check(int x){
	for(ri i = 2;i <= sqrt(x);i ++)
		if(x%i == 0)
			return false;
	return true;
}

int main() {
	int n;
	scanf("%d",&n);
	while(n != 0) {
		for(ri i = 1;i <= n;i ++)
			if(n%i == 0)
				if(check(n/i)) {
					printf("%d\n",n/i);
					break;
				}
		scanf("%d",&n);
	}
	return 0;
}
