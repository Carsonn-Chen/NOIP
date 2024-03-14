#include <bits/stdc++.h>

using namespace std;

int num[105];
bool tag[1005] = {0};

int main(){
	int n;
	scanf("%d",&n); 
	int ans = n;
	for(int i = 0;i < n;i ++)
		scanf("%d",&num[i]);
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < n-i-1;j ++)
			if(num[j] > num[j+1])
				swap(num[j],num[j+1]);
	for(int i = 0;i < n;i ++){
		if(!tag[num[i]])
			tag[num[i]] = 1;
		else{
			num[i] = 0;
			ans -= 1;
		}
	}
	printf("%d\n",ans);
	for(int i = 0;i < n;i ++)
		if(num[i])
			printf("%d ",num[i]);
	return 0;
}
