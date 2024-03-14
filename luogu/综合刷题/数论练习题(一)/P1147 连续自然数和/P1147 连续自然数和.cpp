#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int main(){
	int m;
    ios::sync_with_stdio(false);
	cin >> m;
    for(ri k1 = sqrt(2*m);k1 > 1;k1 --)
        if(2*m%k1 == 0 && (k1+2*m/k1)%2 == 1){
            int k2 = 2*m/k1;
            cout<< (k2-k1+1)/2 << " " << (k1+k2-1)/2 << endl;
        }
    return 0;
}
