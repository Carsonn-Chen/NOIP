#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;
int num[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	int num2 = 0;
	for(int i = 0;i <= n;i ++){
		if(num[i] == num[i+1]){
			num[i] = 0; 
			num2 ++;
		}
	}
	printf("%d\n",n-num2);
	for(int i = 1;i <= n;i ++)
		if(num[i] != 0)
		printf("%d ",num[i]);
	printf("\n");
	return 0;
}
