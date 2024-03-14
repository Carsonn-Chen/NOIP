#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
using namespace std;


const int MAXN = 1e8+5;
int num[MAXN];
set<int>ss;

int main(){
	freopen("ribbon.in","r",stdin);
	freopen("ribbon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int l,r,Max = 0;
	for(int i = 1;i <= n;i ++){
		scanf("%d%d",&l,&r);
		Max = max(Max,r);
		for(int j = l;j <= r;j ++)
			num[j] = i;
	}
	int cnt = 0;
	for(int i = 1;i <= Max;i ++){
		if(!ss.count(num[i]) && num[i]){
			cnt ++;
			ss.insert(num[i]);
		}
	}
	printf("%d\n",cnt);
	return 0;
}
