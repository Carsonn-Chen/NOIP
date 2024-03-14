#include <bits/stdc++.h>

using namespace std;

int n;
int num[10005];
int ans[10005];
int tag[10005];

void pl(int i){
	if(i == n+1){
		for(int j = 1;j <= n;j ++)
			printf("%d ",ans[j]);
		printf("\n");
		return;
	}
	for(int j = 1;j <= n;j ++){
		if(!tag[j]){
			tag[j] = 1;
			ans[i] = num[j];
			pl(i+1);
			tag[j] = 0;
		}
	}
		
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i ++)
		cin >> num[i];
	sort(num+1,num+1+n);
	//pl(1);
	int m = 1;
	for(int i = 1;i <= n;i ++)
		m *= i;
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= n;j ++)
			printf("%d ",num[j]);
		printf("\n");
		next_permutation(num+1,num+1+n);
		
	}
	return 0;
}
