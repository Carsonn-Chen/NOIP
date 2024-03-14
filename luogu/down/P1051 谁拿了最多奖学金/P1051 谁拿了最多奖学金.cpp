#include <bits/stdc++.h>

using namespace std;

struct inf{
	string name;
	int qm;
	int bj;
	char gb;
	char xb;
	int lw;
	int jxj;
	int id;
	inf():jxj(0){}
}pop[105];


bool cmp1(inf a,inf b){
	if(a.jxj == b.jxj)
		return a.id < b.id;
	return a.jxj > b.jxj;
}

int main(){
	int n;
	int all = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		cin >> pop[i].name >> pop[i].qm >> pop[i].bj >> pop[i].gb >> pop[i].xb >> pop[i].lw;
		pop[i].id = i;
	}
	for(int i = 1;i <= n;i ++){
		if(pop[i].qm > 80 && pop[i].lw >= 1)
			pop[i].jxj += 8000;
		if(pop[i].qm > 85 && pop[i].bj > 80)
			pop[i].jxj += 4000;
		if(pop[i].qm > 90)
			pop[i].jxj += 2000;
		if(pop[i].qm > 85 && pop[i].xb == 'Y')
			pop[i].jxj += 1000;
		if(pop[i].bj > 80 && pop[i].gb == 'Y')
			pop[i].jxj += 850;
		all += pop[i].jxj;
	}
	sort(pop+1,pop+1+n,cmp1);
	cout << pop[1].name << "\n" << pop[1].jxj << "\n" << all << endl;
	return 0;
}
