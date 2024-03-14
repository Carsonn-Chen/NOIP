#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define ri register int
#define maxn 5005

using namespace std;

int a[5001],f[5001],cnt[5001];

int main(){
	ios::sync_with_stdio(false);
    fill(f,f+5004,1);
    memset(cnt,0,sizeof(cnt));
    int n;
    cin >> n;
    for(ri i = 1;i <= n;i ++)
        cin >> a[i];
    int Max_long = 0;
    for(ri i = 1;i <= n;i ++){
        for(ri j = 1;j < i;j ++)
            if(a[i] < a[j])
                f[i] = max(f[i],f[j]+1);
        Max_long = max(Max_long,f[i]);
        for(ri j = 1;j < i;j ++){
            if(f[i] == f[j] && a[i] == a[j])
                cnt[j] = 0;
            else if(f[i] == f[j]+1 && a[i] < a[j])
                cnt[i] += cnt[j];
        }
        if(!cnt[i])
            cnt[i] = 1;
    }
    int sum = 0;
    for(ri i = 1;i <= n;i ++)
        if(f[i] == Max_long)
            sum += cnt[i];
    cout << Max_long << ' ' << sum << endl;
    return 0;
}
