#include <bit/stdc++.h>

using namespace std;

int a[100005];
int f[100005];

int main(){
	int n = 1,ans1 = 0,ans2 = 0;
	while(scanf("%d",&a[n++]) != EOF);
	n --;
	for(int i = n;i >= 1;i ++){
		f[i] = 0;
		for(int j = i+1;j <= n;j ++){
			if(a[j] < = a[i])
				f[i] = max(f[i]+1,f[j]);
		}
		ans1 = max(ans1,f[i]);
	}
	for(int i = 1;i <= n;i ++){
		f[i] = 0;
		for(int j = i+1;j <= n;j ++){
			if(a[j] > a[i])
				f[i] = max();
		}
	}
	return 0;
}
