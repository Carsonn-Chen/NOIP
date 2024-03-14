#include <bits/stdc++.h>

using namespace std;

struct node{	
	int fa;																
	int no;															
	int count;											
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

int main(){
	//freopen("in.in","r",stdin);
	int t;
	scanf("%d",&t);
	for(int i = 1;i <= 30004;i ++)
		u[i].fa = i;
	char e;
	int a,b;
	while(t--){
		cin >> e;
		if(e == 'M'){
			cin >> a >> b;		
			int r1 = find(a),r2 = find(b);							
			u[r2].fa = r1;
			u[r2].no += u[r1].count;
			u[r1].count += u[r2].count;
		}
		else if(e == 'C'){
			cin >> a;
			int r1 = find(a);
			printf("%d\n",u[r1].count-u[a].no-1);
		}
	}
	return 0;
}
