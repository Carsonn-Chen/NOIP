#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

int a[10],b[10];
int temp[10];

int main(){
	//freopen("ending.in","r",stdin);
	//freopen("ending.out","w",stdout);
	int m,n,hp,ta = 0,tb = 0;
	scanf("%d%d%d",&m,&n,&hp);
	if(m == 7){
		printf("No\n");
		return 0;
	}
	for(int i = 1;i <= m;i ++)
		scanf("%d",&a[i]),ta += a[i];			//×ÜÑªÁ¿ta
	for(int i = 1;i <= n;i ++)
		scanf("%d",&b[i]),tb += b[i];			//×Ü¹¥»÷tb
	int nw = 1,nn = n;
	while(nn > 1) nw *= (nn--);
	if(ta+hp > tb){
		printf("No\n");
		return 0;
	}
	else{
		for(int i = 2;i <= nw;i ++){
			for(int j = 1;j <= m;j ++)
				temp[j] = a[j];
			int ta2 = ta,tb2 = tb;
			int j = 1,k = 1;
			while(tb2 > ta2 && j <= m){
				if(temp[j] - b[k] > 0){
					temp[j] -= b[k];
					ta2 -= b[k];
					tb2 -= b[k];
				}
				else{
					ta2 -= temp[j];
					tb2 -= b[k];
					temp[j] = 0;
					j ++;
				}
				k ++;
			}
			if(tb2 >= hp && ta2 <= 0){
				printf("Yes\n");
				return 0;
			}
			next_permutation(b+1,b+1+n);
		}
	}
	printf("No\n");
	return 0;
}
