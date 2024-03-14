#include <bits/stdc++.h>

using namespace std;

struct node{
	int no;
	int grade;
}pop[5005];

bool cmp(node a,node b){
	if(a.grade != b.grade)
		return a.grade > b.grade;
	else
		return a.no < b.no;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++)
		scanf("%d%d",&pop[i].no,&pop[i].grade);
	sort(pop+1,pop+1+n,cmp);
	m = m * 1.5;
	int fsx = pop[m].grade;	
	int ans;															//·ÖÊýÏß
	for(int i = 1;i <= n;i ++){
		if(pop[i].grade >= fsx)
			ans ++;
		else
			break;
	}
	printf("%d %d\n",fsx,ans);
	for(int i = 1;i <= ans;i ++)
		printf("%d %d\n",pop[i].no,pop[i].grade);
	return 0;
}
