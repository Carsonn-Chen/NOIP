#include <bits/stdc++.h>

using namespace std;

int num[100005];

int main(){
	int n;
	scanf("%d",&n); 
	for(int i = 0;i < n;i ++)
		scanf("%d",&num[i]);
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < n-i-1;j ++)
			if(num[j] > num[j+1])
				swap(num[j],num[j+1]);
	for(int i = 0;i < n-1;i ++)
		printf("%d ",num[i]);
	printf("%d\n",num[n-1]);
	return 0;
}
