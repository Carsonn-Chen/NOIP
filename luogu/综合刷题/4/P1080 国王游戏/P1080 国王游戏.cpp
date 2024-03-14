#include <bits/stdc++.h>

using namespace std;

struct bigint{
	int left;
	int right;
}num[100010];

int ans[1000010];
int len = 1;
int n;

void multiply(int x){
	for(int i = 1;i <= len;i ++)
		ans[i] *= num[x].left;
	for(int i = 1;i <= len;i ++){
		ans[i+1] += (ans[i]/10);
		ans[i] %= 10;
	}
	len++;
	while(ans[len] > 9){
		ans[len+1] += (ans[len]/10);
		ans[len] %= 10;
		len ++;	
	}
	if(ans[len] == 0)
		len --;
}

void divided(){
	for(int i = len;i >= 1;i --){
		ans[i-1] += (ans[i]%num[n].right*10);
		ans[i] /= num[n].right;
	}
	while(ans[len] == 0)
		len --;
	if(len == 0)
		printf("1");
}

bool cmp1(bigint a,bigint b){
	return a.left*a.right < b.left*b.right;
}

int main(){
	scanf("%d",&n);
	scanf("%d%d",&num[0].left,&num[0].right);
	for(int i = 1;i <= n;i ++)
		scanf("%d%d",&num[i].left,&num[i].right);
	sort(num+1,num+1+n,cmp1);
	ans[1] = num[0].left;
	for(int i = 1;i < n;i ++)
		multiply(i);
	divided();
	for(int i = len;i >= 1;i --)
		printf("%d",ans[i]);
	printf("\n");
	return 0;
}
