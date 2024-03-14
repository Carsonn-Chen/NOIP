/* 二分求下界 
*/ 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const double PI= acos(-1.0);

int a[1000005],n,k;

int Erfen(){    // 复杂度O(log(n)) ，二分区间是闭区间 
   int L = 0; // 查找区间的左端点
   int R =n - 1; // 查找区间的右端点
   int ans=n; // 到目前为止找到的最优解
   while( L <= R) { // 如果查找区间不为空就继续查找
      int mid = L+(R-L>>1);   // 二分 
      if(a[mid]>= k) { ans = mid; R = mid - 1;}  
      else  L = mid+1;
   }
   return ans;
}

int main(){
	freopen("lower.in","r",stdin);
    freopen("lower.out","w",stdout);    
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i]; 
    cout<<Erfen()<<endl;   
    return 0;
}


