#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#define pi acos(-1,0)

using namespace std;

int num[1000005];
int n,e,ans = -1;

int main(){
	freopen("solve.in","r",stdin);
	freopen("solve.out","w",stdout);
	scanf("%d%d",&n,&e);
	for(int i = 0;i < n;i ++)
		scanf("%d",&num[i]);
	int l = 0,r = n;
	while(l <= r){
		int mid = (l+r)/2;
		if(num[mid] == e){
			ans = mid;
			break;
		}
		if(num[mid] < e)
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%d\n",ans);
	return 0;
}
