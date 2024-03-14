#include<bits/stdc++.h>

using namespace std;

int num[105];
int temp[105];
int tag[1005] = {0};

void merge_sort(int x,int y){
	if(y - x > 1){
		int m = (x+y)/2;
		int p = x,q = m,i = x;
		merge_sort(x,m);
		merge_sort(m,y);
		while(p < m || q < y){
			if(q >= y || (p < m && num[p] <= num[q]))
				temp[i++] = num[p++];
			else
				temp[i++] = num[q++];
		}
		for(i = x;i < y;i ++)
			num[i] = temp[i];
	}
}

int main(){
	int n;
	scanf("%d",&n); 
	int ans = n;
	for(int i = 1;i <= n;i ++)
		scanf("%d",&num[i]);
	merge_sort(1,n+1);
	for(int i = 1;i <= n;i ++){
		if(!tag[num[i]])
			tag[num[i]] = 1;
		else{
			num[i] = 0;
			ans -= 1;
		}
	}
	printf("%d\n",ans);
	for(int i = 1;i <= n;i ++)
		if(num[i])
			printf("%d ",num[i]);
	return 0;
}
