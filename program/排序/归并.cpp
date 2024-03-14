#include<bits/stdc++.h>

using namespace std;

int num[100005];
int temp[100005];

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
	/*freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);*/
	int n;
	scanf("%d",&n); 
	for(int i = 1;i <= n;i ++)
		scanf("%d",&num[i]);
	merge_sort(1,n+1);
	for(int i = 1;i < n;i ++)
		printf("%d ",num[i]);
	printf("%d\n",num[n]);
	return 0;
}
