#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const double PI= acos(-1.0);

const double eps=1e-10;
int T,n;
double a[10005],b[10005],c[10005];

double f(double x){
	int i,j;
	double maxx = -0x7fffffff;
	for(int i = 1;i <= n;i++)
		maxx = max(maxx,a[i] * x * x + b[i] * x + c[i]);
	return maxx;
}

int main(){
	freopen("curves.in","r",stdin)	;
	freopen("curves.out","w",stdout);	
	int i,j;
	scanf("%d",&T);
	while(T--){	
		scanf("%d",&n);
		for(i = 1;i <= n;i++)
			scanf("%lf%lf%lf",&a[i],&b[i],&c[i]); 
		double L = 0.0,R = 1000.0;
		while(R-L>= eps ){		
			double Lmid = L + (R - L) / 3;    //Èý·Ö
			double Rmid = R - (R - L) / 3;
			if(f(Lmid) <= f(Rmid))  R = Rmid;
			else  L = Lmid;
		}
		printf("%.4lf\n",f(L));  
	}
	return 0;
}
