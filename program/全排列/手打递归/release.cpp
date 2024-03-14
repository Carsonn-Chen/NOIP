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
	//freopen("out.txt","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++)
		cin >> num[i];
	sort(num+1,num+1+n);
	pl(1);
	return 0;
}
