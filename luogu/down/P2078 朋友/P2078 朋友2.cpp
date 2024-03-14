#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int read(){
    int summ = 0;
    char e = getchar();
    while(!isdigit(e))
        e = getchar();
    while(isdigit(e)){
        summ = summ * 10 + e - '0';
        e = getchar();
    }
    return summ;
}

int n,m,p,q;
int faA[20005],faB[20005];

int findA(int x){
    if(x == faA[x])
        return x;
    return faA[x] = findA(faA[x]);
}

int findB(int x){
    if(x == faB[x])
        return x;
    return faB[x] = findB(faB[x]);
}

int main(){
    n = read(),m = read(),p = read(),q = read();
    for(ri i = 1;i <= n;i ++)
        faA[i] = i;
    for(ri i = 1;i <= m;i ++)
        faB[i] = i;
    int x,y;
    int r,l;
    int cnta = 0,cntb = 0;
    for(ri i = 1;i <= p;i ++){
        x = read();y = read();
        r = findA(x),l = findA(y);
        if(r != l){
            if(r < l)
                faA[l] = r;
            else
                faA[r] = l;
        }
    }
    for(ri i = 1;i <= n;i ++)
        if(findA(i) == 1)
            cnta ++;
    for(ri i = 1;i <= q;i ++){
        x = read();y = read();
        r = findB(x),l = findB(y);
        if(r != l){
            if(r < l)
                faB[l] = r;
            else
                faB[r] = l;
        }
    }
    for(ri i = 1;i <= m;i ++)
        if(findB(i) == 1)
            cntb ++;
    cout << min(cnta,cntb);
    return 0;
}
