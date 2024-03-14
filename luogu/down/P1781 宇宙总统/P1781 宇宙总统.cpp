#include <bits/stdc++.h>

using namespace std;

struct node{
	string s;
	int no;
}pop[25];

bool cmp(node a,node b){
	if(a.s.size() != b.s.size())
		return a.s.size() > b.s.size();
	return a.s > b.s;
}

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> pop[i].s;
		pop[i].no = i;
	}
	sort(pop+1,pop+1+n,cmp);
	cout << pop[1].no << "\n" << pop[1].s << endl;
	return 0;
}
