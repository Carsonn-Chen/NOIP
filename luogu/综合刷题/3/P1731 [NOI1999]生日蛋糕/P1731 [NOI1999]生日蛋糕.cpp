#include <bits/stdc++.h>

using namespace std;

int b[25];
long long ans = 0x7fffffffff;
bool flag;
int n,m;

void DFS(int v,int s,int p,int r,int h){		//v为已用体积，s为已用表面积，p为剩余层数，r为半径，h为高 
	int i,j,hh;
    if(p == 0){
        if(v == n && s < ans)
			ans = s,flag = 1;
        return;
    }
    if(v+b[p-1] > n)
		return ;
    if(2*(n-v)/r + s >= ans)  
		return;
    for(i = r-1;i >= p;i --){
        if(p == m) 
			s = i*i;
        hh = min((n-v-b[p-1]) / (i*i),h-1);
        for(j = hh;j >= p;j --)
            DFS(v+i*i*j,s+2*i*j,p-1,i,j);
    }
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= 20;i ++)
		b[i]=b[i-1]+i*i*i;
	DFS(0,0,m,n+1,n+1);
	if(flag)
		cout << ans << endl;
	else
		cout << "0" << endl;
	return 0;
}
