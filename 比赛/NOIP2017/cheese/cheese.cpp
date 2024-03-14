#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
	double x,y,z;
	int tag;
	node():tag(2){}
}rnd[1005];

queue<node>q;

bool sign;
double T,n,h,r;

bool pd(node a,node b){
	if(((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z)) <= 4*r*r)
		return true;
	return false;
}

void solve(node &a){
	if(a.tag == 3){
		sign = true;
		return ;
	}
	if(a.tag != 0){
		a.tag = 0;
		for(int i = 1;i <= n;i ++)
			if(pd(a,rnd[i]))
				solve(rnd[i]);
	}
}

int main(){
	//freopen("cheese.in","r",stdin); 
	//freopen("cheese.out","w",stdout);
	cin >> T;
	while(T--){
		sign = false;
		cin >> n >> h >> r;
		for(int i = 1;i <= n;i ++)
			cin >> rnd[i].x >> rnd[i].y >> rnd[i].z;
		for(int i = 1;i <= n;i ++){
			if((rnd[i].z-r) <= 0){
				rnd[i].tag = 1;
				q.push(rnd[i]);
			}
			if((rnd[i].z+r) >= h){
				if(rnd[i].tag == 1)
					sign = true;
				rnd[i].tag = 3;	
			}
		}
		while(!q.empty() && sign==false){
			node temp = q.front();
			q.pop();
			solve(temp);
		}
		if(sign)
			printf("Yes\n");
		else
			printf("No\n");
		while(!q.empty())
			q.pop();
		for(int i = 1;i <= n;i ++)
			rnd[i].tag = 2;
	}
	return 0;
}
