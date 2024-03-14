#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+5;

int ans[MAXN],num[10005];

int main(){
	//freopen("in.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&num[i]);
	int Max = *(max_element(num+1,num+1+n));
	printf("%d\n",Max);
	for(int i = 2;i <= Max;i ++){
		for(int j = 1;j <= n;j ++){
			if(num[j]%i == 0)
				ans[i] ++;
		}
	}
	int i = 2;
	bool pd;
	while(i <= n){
		pd = 0;
		for(int j = Max;j >= 1;j --){
			if(ans[j] >= i){
				printf("%d\n",j);
				i++;
				pd = 1;
				break;
			}
		}
		if(!pd)
			break;
	}
	for(;i <= n;i ++)
		printf("1\n");
	return 0;
}
