#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <queue>
#define ri register int

using namespace std;

struct node{
	int a,b,c;
	int x;
	int calc(){
		return a*x*x + b*x + c;
	}
};

priority_queue<node,vector<node>,less<node> >q;

bool operator<(node a,node b){
    	return a.calc() > b.calc();
}

int main() {
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	node temp;
	for (ri i = 1; i <= n; i++){
		cin >> temp.a >> temp.b >> temp.c;
		temp.x = -(temp.b/2*temp.a);
		if(temp.x < 1)
			temp.x = 1;
		q.push(temp);
	}
	for(ri i = 1;i <= m;i ++){
		temp = q.top();q.pop();
		cout << temp.calc() << " ";
		temp.x += 1;
		q.push(temp);
	}
	return 0;
}
