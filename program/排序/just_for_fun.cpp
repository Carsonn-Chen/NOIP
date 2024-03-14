#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int num[100005];
int temp[100005];

void merge_sort(int l,int r){
	if(r - l <= 1)
		return ;
	int mid = (l+r) >> 1;
	merge_sort(l,mid);
	merge_sort(mid,r);
	int p = l,q = mid,i = l;
	while(p < mid || q < r){
		if(q >= r || (p < mid && num[p] < num[q]))
			temp[i++] = num[p ++];
		else
			temp[i++] = num[q++];
	}
	for(ri i = l;i < r;i ++)
		num[i] = temp[i];
}

void quick_sort(int l,int r){
	int ll = l,rr = r;
	int mid = num[(r+l)/2];
	while(ll < rr){
		while(num[ll] < mid)
			++ ll;
		while(num[rr] > mid)
			-- rr;
		if(ll <= rr){
			swap(num[ll],num[rr]);
			++ ll;
			-- rr;
		}
	}
	if(l < rr)
		quick_sort(l,rr);
	if(ll < r)
		quick_sort(ll,r);
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(ri i = 1;i <= n;i ++)
		cin >> num[i];
	//merge_sort(1,n+1);
	quick_sort(1,n);
	for(ri i = 1;i <= n;i ++)
		cout << num[i] << " ";
	return 0;
}
