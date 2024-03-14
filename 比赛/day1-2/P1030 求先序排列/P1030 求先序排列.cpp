#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

void creat(string in,string after){
    if (in.size() > 0){
        char ch = after [ after.size()-1];
        cout << ch;
        int k = in.find(ch);
        creat(in.substr(0,k),after.substr(0,k));
        creat(in.substr(k+1),after.substr(k,in.size()-k-1));
    }
}

int main(){
    string zx,hx;
    cin >> zx >> hx;
    creat(zx,hx);
	cout << endl;
    return 0;
}
