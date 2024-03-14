#include <bits/stdc++.h>

using namespace std;

int main(){
    int n , m , k;
    int i;
    cin >> i;
    while(i --){
    	cin >> n >> m;
        k = 1;
        while(-- n){
            if (m % 2){
                k = k * 2;
                m = (m + 1) / 2;
            }
            else{
                k = k * 2 + 1;
                m = m / 2;
            }
        }
        cout << k << endl;
    }
    return 0;
}
