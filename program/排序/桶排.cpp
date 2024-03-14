#include <bits/stdc++.h>

using namespace std;

int num[100000001] = {0};

int main(){
	int n,e;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&e);
		num[e] += 1;
	}
	int i = 1;
	while(n != 0){
		if(num[i]){
			for(int j = 1;j <= num[i];j ++)
				printf("%d ",i);
			n -= num[i];
		}
		i += 1;
	}
	return 0;
}
