#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <stack>
#define ri register int

using namespace std;

int num[1005];
char ans[3005];
stack<int> s1,s2;
int pos = 1,now = 1;

void cksol(){
    if(!s1.empty()){
        if(s1.top() == now){
            now ++;
            s1.pop();
            ans[pos++] = 'b';
            cksol();
        }
    }
    
    if(!s2.empty()){
        if(s2.top() == now){
            now ++;
            s2.pop();
            ans[pos++] = 'd';
            cksol();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(ri i = 1;i <= n;i ++)
        cin >> num[i];
    for(ri i = 1;i <= n;i ++){
        if(!s1.empty() && !s2.empty()){
            if(s1.top() < num[i] && s2.top() < num[i]){
                cout << "0" << endl;
                return 0;
            }
        }
        if(s1.empty()){
            s1.push(num[i]);
            ans[pos++] = 'a';
        }else{
            if(s1.top() > num[i]){
                s1.push(num[i]);
                ans[pos++] = 'a';
            }else{
                s2.push(num[i]);
                ans[pos++] = 'c';
            }
        }
        cksol();
    }
    /*if(ans[n+n] < 'a' || ans[n+n] > 'd'){
        cout << "0" << endl;
        return 0;
    }*/
    for(ri i = 1;i <= n+n;i ++)
        cout << ans[i] << " ";
    return 0;
}
