#include <bits/stdc++.h>
#define P 998244353
using namespace std;
int T,n,R,a[2],b[4];
int po(int a,int b) {int t=1;
    for (;b;b>>=1,a=1LL*a*a%P)
        if (b&1) t=1LL*t*a%P;return t;}
int main() {
    for (cin>>T;T--;) {scanf("%d",&n);
        a[1]=b[0]=b[1]=b[2]=1;a[0]=b[3]=0;
        for (R=n+3;R;R>>=1) {long long x,y,u,v; 
            if (R&1) x=a[0],y=a[1],
                a[0]=(x*b[0]+y*b[2])%P,a[1]=(x*b[1]+y*b[3])%P;
            x=b[0],y=b[1],u=b[2],v=b[3];
            b[0]=(x*x+y*u)%P;b[1]=(x*y+y*v)%P;
            b[2]=(u*x+v*u)%P;b[3]=(u*y+v*v)%P;
        }
        printf("%lld\n",(1LL*n*a[1]%P+P-a[0]+2)*2LL%P*po(1LL*n*n%P+n,P-2)%P);
    }return 0;
}
