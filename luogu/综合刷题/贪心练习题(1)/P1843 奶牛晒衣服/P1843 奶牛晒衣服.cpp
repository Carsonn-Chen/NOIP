#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int>q;

int main(){
	int n,a,b;
	int temp;
	scanf("%d%d%d",&n,&a,&b);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&temp);
		q.push(temp);
	}
	int ans = 0;
	while(1){
		temp = q.top();
		q.pop();
		if(ans * a >= temp)
			break;
		ans ++;
		q.push(temp - b);
	}
	printf("%d\n",ans);
	return 0;
}
