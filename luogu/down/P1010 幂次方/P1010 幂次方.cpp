#include <bits/stdc++.h>

using namespace std;

void solve(int x){
	if(x == 0)
		return;
	int y = 1;
	while(pow(2,y) <= x)
		y ++;
	y -= 1;
	if(y==0) cout<<"2(0)";
    if(y==1) cout<<"2";
    if(y>1){
        cout<<"2(";
        solve(y);
        cout<<")";
    }
     if(x != pow(2,y)){
        cout<<"+";
        solve(x - pow(2,y)); 
    } 
     
}

int main(){
	int n;
	cin >> n;
	solve(n);
	return 0;
}
