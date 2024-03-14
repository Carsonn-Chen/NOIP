#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ri register int

using namespace std;

const int maxn = 32005;
int n,m;
int v,p,q;
int zw[maxn];
int zc[maxn];
int fw[maxn][3];
int fc[maxn][3];
int f[maxn];

int main(){
    ios::sync_with_stdio(false);
	cin >> n >> m;
    for (ri i = 1;i <= m;i ++){
        cin >> v >> p >> q;
        if (!q){
            zw[i] = v;
            zc[i] = v * p;
        }
        else{
            fw[q][0] ++;
            fw[q][fw[q][0]] = v;
            fc[q][fw[q][0]] = v * p;
        }
    }

    for (ri i = 1;i <= m;i ++)
        for (ri j = n;zw[i]!=0 && j>=zw[i];j--){
            f[j] = max(f[j],f[j-zw[i]]+zc[i]);
            if (j >= zw[i] + fw[i][1])
                f[j] = max(f[j],f[ j - zw[i] - fw[i][1] ] + zc[i] + fc[i][1]);

            if (j >= zw[i] + fw[i][2])
                f[j] = max(f[j],f[ j - zw[i] - fw[i][2] ] + zc[i] + fc[i][2]);

            if (j >= zw[i] + fw[i][1] + fw[i][2])
                f[j] = max(f[j],f[ j - zw[i] - fw[i][1] - fw[i][2] ] + zc[i] + fc[i][1] + fc[i][2]);

        }
     cout << f[n] << endl;
     return 0;
}
