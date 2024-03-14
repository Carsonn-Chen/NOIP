#include <bits/stdc++.h>

using namespace std;

struct player{
	int id;							//±àºÅ 
	int sl;							//ÊµÁ¦ 
	int cj;							//³É¼¨ 
}pop[200005];

player temp1[100005],temp2[100005];

bool cmp1(player a,player b){
	if(a.cj == b.cj)
		return a.id < b.id;
	return a.cj > b.cj;
}

int main(){
	int n,r,q,j;
	scanf("%d%d%d",&n,&r,&q);
	for(int i = 1;i <= 2*n;i ++){
		scanf("%d",&pop[i].cj);
		pop[i].id = i;
	}
	for(int i = 1;i <= 2*n;i ++)
		scanf("%d",&pop[i].sl);
	sort(pop+1,pop+1+2*n,cmp1);
	while(r --){
		j = 1;
		for(int i = 1;i <= 2*n;i += 2){
			if(pop[i].sl > pop[i+1].sl){
				pop[i].cj += 1;
				temp1[j] = pop[i];
				temp2[j] = pop[i+1];
				j ++;
			}
			else{
				pop[i+1].cj += 1;
				temp1[j] = pop[i+1];
				temp2[j] = pop[i];
				j ++;
			}
		}
		int p1 = 1,p2 = 1;
		j = 1;
		while(p1 <= n && p2 <= n){
			if(temp1[p1].cj > temp2[p2].cj){
				pop[j++] = temp1[p1++];
			}
			else if(temp1[p1].cj < temp2[p2].cj){
				pop[j++] = temp2[p2++];
			}
			else if(temp1[p1].cj = temp2[p2].cj){
				if(temp1[p1].id < temp2[p2].id)
					pop[j++] = temp1[p1++];
				else
					pop[j++] = temp2[p2++];
			}
		}
		if(p1 > n && p2 <= n)
			for(;j <= 2*n;j ++)
				pop[j] = temp2[p2++];
		else if(p2 > n && p1 <= n)
			for(;j <= 2*n;j ++)
				pop[j] = temp1[p1++];
	}
	
	/*for(int i = 1;i <= 2*n;i ++)
		printf("%d ",pop[i].id);*/
	
	printf("%d",pop[q].id);
}
