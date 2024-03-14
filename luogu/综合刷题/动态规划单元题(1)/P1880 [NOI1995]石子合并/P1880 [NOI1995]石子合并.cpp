#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define ri register int

using namespace std;

int num[250];
int f1[250][250];
int f2[250][250];
int s[250];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(ri i = 1;i <= n;i ++)
		cin >> num[i],num[i+n] = num[i];
	for(ri i = 1;i <= 2*n;i ++)	
		s[i]=s[i-1]+num[i];
	for(ri p = 1;p < n;p ++)  {  
        for(ri i=1,j=i+p;(j<n+n) && (i<n+n);i++,j=i+p)  {  
			f2[i][j]=999999999;  
	        for(ri k = i;k < j;k ++){  
	            f1[i][j] = max(f1[i][j], f1[i][k]+f1[k+1][j]+s[j]-s[i-1]);   
	            f2[i][j] = min(f2[i][j], f2[i][k]+f2[k+1][j]+s[j]-s[i-1]);  
	        }
	    }
    }
	int Min = 999999999,Max = 0;  
    for(ri i = 1;i <= n;i ++)  {
    	Min = min(Min,f2[i][i+n-1]);
        Max = max(Max,f1[i][i+n-1]);  
    }    
	cout << Min << '\n' << Max;
	return 0;
}
