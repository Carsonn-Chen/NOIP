#include <bits/stdc++.h>

using namespace std;

struct node{															//并查集 
	int fa;																//不是爹，是祖先 
	int no;																//在集合中的编号，用于计算战舰之间的距离 
	int count;															//如果为根，记录集合的个数，用于合并时编号 
	node():no(0),count(1){}
}u[30005];


int find(int k){
	if(u[k].fa == k)
		return k;
	int temp = u[k].fa;
	u[k].fa = find(u[k].fa);
	u[k].no += u[temp].no;
	return u[k].fa;
}

/*
void unionn(int m,int n){
	int c = m;
	while(u[c].fa != c)
		c = u[c].fa;
	u[c].fa = n;
	u[c].no = u[n].count;
	u[n].count += u[c].count;
}
*/

/*
int check(int m,int n){
	int step1 = 0,step2 = 0;
	int r1 = m,r2 = n;
	while(u[r1].fa != r1){
		step1 += u[r1].no;
		r1 = u[r1].fa;
	}
	while(u[r2].fa != r2){
		step2 += u[r2].no;
		r2 = u[r2].fa;
	}
	if(r1 == r2)
		return abs(step1 - step2);
	else 
		return -1;
}
*/

int main(){
	int t;
	cin >> t;
	for(int i = 1;i <= 30004;i ++)
		u[i].fa = i;
	char e;
	int a,b;
	while(t--){
		cin >> e >> a >> b;											//a并到b的尾巴 
		int r1 = find(a),r2 = find(b);								
		if(e == 'M'){
			u[r1].fa = r2;
			u[r1].no += u[r2].count;
			u[r2].count += u[r1].count;
		}
		else if(e == 'C'){
			if(r1 == r2)
				printf("%d\n",(abs(u[a].no - u[b].no)-1));
			else
				printf("-1\n");
		}
	}
	return 0;
}
