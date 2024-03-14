#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+5;
int ans[MAXN],num[10005];

int main(){
	int n,Max = 0,temp;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&temp);
		Max = max(temp,Max);
		int temp2 = sqrt(temp);
		for(int j = 1;j <= temp2;j ++){
			if(temp%j == 0){
				ans[j] ++;
				if(temp != j*j)
					ans[temp/j] ++;
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		while(ans[Max] < i)
			Max --;
		printf("%d\n",Max);
	}
	return 0;
}
