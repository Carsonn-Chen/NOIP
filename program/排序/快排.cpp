#include <bits/stdc++.h>

using namespace std;

int num[100005];

void mysort(int begin,int end){
		int i = begin,j = end;
		int mid = num[(begin+end)/2];
		while(i < j){
			while(num[i] < mid)
				i ++;
			while(num[j] > mid)
				j --;
			if(i <= j){
				swap(num[i],num[j]);
				i ++;
				j --;
			}
		}
		if(begin < j)
			mysort(begin,j);
		if(i < end)
			mysort(i,end);
} 

int main(){
	/*freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);*/
	int n;
	scanf("%d",&n); 
	for(int i = 1;i <= n;i ++)
		scanf("%d",&num[i]);
	mysort(1,n);
	for(int i = 1;i < n;i ++)
		printf("%d ",num[i]);
	printf("%d\n",num[n]);
	return 0;
}
